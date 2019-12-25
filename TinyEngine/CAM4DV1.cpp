#include "CAM4DV1.h"

using namespace TNYMATH;

CAM4DV1::CAM4DV1()
{
}


CAM4DV1::~CAM4DV1()
{
}

void CAM4DV1::Init_CAM4DV1(int cam_attr, TNYMATH::POINT4D_PTR cam_pos, 
	TNYMATH::VECTOR4D_PTR cam_dir, TNYMATH::POINT4D_PTR cam_target, 
	float near_clip_z, float far_clip_z, float fov, float vp_width, float vp_height)
{
	attr = cam_attr;

	VECTOR4D_COPY(&pos, cam_pos);
	VECTOR4D_COPY(&dir, cam_dir);

	// 对于UVN相机
	VECTOR4D_INITXYZ(&u, 1, 0, 0);
	VECTOR4D_INITXYZ(&v, 0, 1, 0);
	VECTOR4D_INITXYZ(&n, 0, 0, 1);
	if (cam_target) {
		VECTOR4D_COPY(&target, cam_target);
	}
	else
	{
		VECTOR4D_ZERO(&target);
	}
	this->near_clip_z = near_clip_z;
	this->far_clip_z = far_clip_z;

	viewport_width = vp_width;
	viewport_height = vp_height;

	viewport_center_x = (vp_width - 1) / 2;
	viewport_center_y = (vp_height - 1) / 2;

	aspect_ratio = (float)viewport_width / (float)viewport_height;

	MAT_IDENTITY_4X4(&mcam);
	MAT_IDENTITY_4X4(&mper);
	MAT_IDENTITY_4X4(&mscr);

	this->fov = fov;
	
	// 将视平面设置为2x(2/ar)
	viewplane_width = 2.0;
	viewplane_height = 2.0 / aspect_ratio;
	// 根据fov和视平面大小计算视距
	float tan_fov_div2 = tan(DEG_TO_RAD(fov / 2));

	view_dist = (0.5)*viewplane_width*tan_fov_div2;

	view_dist_h = 0.5*viewplane_width;
	view_dist_v = 0.5*viewplane_height;

	if (fov == 90.0) {
		// 建立裁剪面
		POINT3D pt_origin;
		VECTOR3D_INITXYZ(&pt_origin, 0, 0, 0);
		VECTOR3D vn; // 面法线
		//右裁剪面
		VECTOR3D_INITXYZ(&vn, 1, 0, -1); // 平面 x=z
		PLANE3D_Init(&rt_clip_plane, &pt_origin, &vn, 1);
		// 左
		VECTOR3D_INITXYZ(&vn, -1, 0, -1); // 平面-x=z
		PLANE3D_Init(&lt_clip_plane, &pt_origin, &vn, 1);
		// 上
		VECTOR3D_INITXYZ(&vn, 0, 1, -1); // 平面y=z
		PLANE3D_Init(&tp_clip_plane, &pt_origin, &vn, 1);
		// 下
		VECTOR3D_INITXYZ(&vn, 0, -1, -1); // 平面-y=z
		PLANE3D_Init(&lt_clip_plane, &pt_origin, &vn, 1);
	}
	else
	{
		POINT3D pt_origin;
		VECTOR3D_INITXYZ(&pt_origin, 0, 0, 0);
		VECTOR3D vn; // 面法线
		//右裁剪面
		VECTOR3D_INITXYZ(&vn, view_dist, 0, -viewplane_width / 2.0); // 平面 x=z
		PLANE3D_Init(&rt_clip_plane, &pt_origin, &vn, 1);
		// 左
		VECTOR3D_INITXYZ(&vn, -view_dist, 0, -viewplane_width / 2.0); // 平面-x=z
		PLANE3D_Init(&lt_clip_plane, &pt_origin, &vn, 1);
		// 上
		VECTOR3D_INITXYZ(&vn, 0, view_dist, -viewplane_width / 2.0); // 平面y=z
		PLANE3D_Init(&tp_clip_plane, &pt_origin, &vn, 1);
		// 下
		VECTOR3D_INITXYZ(&vn, 0, -view_dist, -viewplane_width / 2.0); // 平面-y=z
		PLANE3D_Init(&lt_clip_plane, &pt_origin, &vn, 1);
	}
}

void CAM4DV1::Build_CAM4DV1_Matrix_Euler(int cam_rot_seq)
{
	MATRIX4X4 mt_inv, mx_inv, my_inv, mz_inv, mrot, mtmp;	//平移，旋转x,y,z
	// 1， 根据相机位置计算相机平移矩阵的逆矩阵
	Mat_Init_4x4(&mt_inv, 1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-pos.x, -pos.y, -pos.z, 1);

	// 2，创建旋转矩阵的逆矩阵
	// 提取欧拉角度
	float theta_x = dir.x;
	float theta_y = dir.y;
	float theta_z = dir.z;

	float cos_theta = Fast_Cos(theta_x);
	float sin_theta = -Fast_Sin(theta_x);

	Mat_Init_4x4(&mx_inv, 1, 0, 0, 0,
			0, cos_theta, sin_theta, 0,
			0,-sin_theta, cos_theta, 0,
		0, 0, 0, 1);

	cos_theta = Fast_Cos(theta_y);
	sin_theta = -Fast_Sin(theta_y);

	Mat_Init_4x4(&my_inv, cos_theta, 0, -sin_theta, 0,
		0, 1, 0, 0,
		sin_theta, 0, cos_theta, 0,
		0, 0, 0, 1);


	cos_theta = Fast_Cos(theta_z);
	sin_theta = -Fast_Sin(theta_z);

	Mat_Init_4x4(&mz_inv, cos_theta, sin_theta, 0, 0,
		-sin_theta, cos_theta, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	// 计算逆旋转矩阵的乘积
	switch (cam_rot_seq)
	{
	case CAM_ROT_SEQ_XYZ:
	{
		Mat_Mul_4x4(&mx_inv, &my_inv, &mtmp);
		Mat_Mul_4x4(&mtmp, &mz_inv, &mrot);
		break;
	}
	case CAM_ROT_SEQ_YXZ:
	{
		Mat_Mul_4x4(&my_inv, &mx_inv, &mtmp);
		Mat_Mul_4x4(&mtmp, &mz_inv, &mrot);
		break;
	}
	case CAM_ROT_SEQ_XZY:
	{
		Mat_Mul_4x4(&mx_inv, &mz_inv, &mtmp);
		Mat_Mul_4x4(&mtmp, &my_inv, &mrot);
		break;
	}
	case CAM_ROT_SEQ_YZX:
	{
		Mat_Mul_4x4(&my_inv, &mz_inv, &mtmp);
		Mat_Mul_4x4(&mtmp, &mx_inv, &mrot);
		break;
	}
	case CAM_ROT_SEQ_ZYX:
	{
		Mat_Mul_4x4(&mz_inv, &my_inv, &mtmp);
		Mat_Mul_4x4(&mtmp, &mx_inv, &mrot);
		break;
	}
	case CAM_ROT_SEQ_ZXY:
	{
		Mat_Mul_4x4(&mz_inv, &mx_inv, &mtmp);
		Mat_Mul_4x4(&mtmp, &my_inv, &mrot);
		break;
	}
	default:
		break;
	}
	Mat_Mul_4x4(&mt_inv, &mrot, &mcam);
}

void CAM4DV1::Build_CAM4DV1_Matrix_UVN(int mode)
{
	MATRIX4X4 mt_inv, mt_uvn, mtmp;

	// 1 创建逆平移矩阵
	Mat_Init_4x4(&mt_inv, 1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-pos.x, -pos.y, -pos.z, 1);

	if (mode == UVN_MODE_SPHERICAL) {
		// 使用球面坐标模式
		float phi = dir.x;
		float theta = dir.y; // 方位角

		float sin_phi = Fast_Sin(phi);
		float cos_phi = Fast_Cos(phi);

		float sin_theta = Fast_Sin(theta);
		float cos_theta = Fast_Cos(theta);

		target.x = -1 * sin_phi*sin_theta;
		target.y = 1 * cos_phi;
		target.z = sin_phi * cos_theta;
	}
	// n = <目标位置-观察点位置>
	//VECTOR4D_COPY(&n, &dir);
	VECTOR4D_Build(&pos, &target, &n);
	VECTOR4D_INITXYZ(&v, 0, 1, 0);
	VECTOR4D_Cross(&v, &n, &u);
	VECTOR4D_Cross(&n, &u, &v);

	// 归一化
	VECTOR4D_Normalize(&u);
	VECTOR4D_Normalize(&v);
	VECTOR4D_Normalize(&n);

	Mat_Init_4x4(&mt_uvn, u.x, v.x, n.x, 0,
		u.y, v.y, n.y, 0,
		u.z, v.z, n.z, 0,
		0, 0, 0, 1);

	Mat_Mul_4x4(&mt_inv, &mt_uvn, &mcam);
}
