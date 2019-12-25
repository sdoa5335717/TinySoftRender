#pragma once
#include "TNYMATH.h"
class CAM4DV1
{
public:
	CAM4DV1();
	~CAM4DV1();

	enum {
		CAM_ROT_SEQ_XYZ = 0,
		CAM_ROT_SEQ_YXZ = 1,
		CAM_ROT_SEQ_XZY = 2,
		CAM_ROT_SEQ_YZX = 3,
		CAM_ROT_SEQ_ZYX = 4,
		CAM_ROT_SEQ_ZXY = 5
	};
	enum {
		UVN_MODE_SIMPLE = 0,
		UVN_MODE_SPHERICAL = 1
	};
	enum {
		CAM_MOVE_XYZ = 0,
		CAM_MOVE_SPHERICAL
	};
	enum {
		CAM_MOVE_UP=0,
		CAM_MOVE_DOWN,
		CAM_MOVE_LEFT,
		CAM_MOVE_RIGHT,
		CAM_MOVE_FONT,
		CAM_MOVE_BACK
	};
	void Init_CAM4DV1(int cam_attr, TNYMATH::POINT4D_PTR cam_pos,
		TNYMATH::VECTOR4D_PTR cam_dir, TNYMATH::POINT4D_PTR cam_target,
		float near_clip_z, float far_clip_z, float fov, float vp_width, float vp_height);

	void Build_CAM4DV1_Matrix_Euler(int cam_rot_seq);
	void Build_CAM4DV1_Matrix_UVN(int mode);
	// 相机移动
	void Camera_move(int moveType, int direction, float delta) 
	{
		// 相机平移
		//if (moveType == CAM_MOVE_XYZ)
		//{
		//	if (direction == CAM_MOVE_UP) 
		//	{
		//		pos.y += delta;
		//	}
		//	else if (direction == CAM_MOVE_DOWN)
		//	{
		//		pos.y -= delta;
		//	}
		//	else if (direction == CAM_MOVE_LEFT)
		//	{
		//		pos.x -= delta;
		//	}
		//	else if (direction == CAM_MOVE_RIGHT)
		//	{
		//		pos.x += delta;
		//	}
		//}
		// 球面移动
		if (moveType == CAM_MOVE_SPHERICAL)
		{
			if (direction == CAM_MOVE_UP)
			{
				dir.x += delta;
			}
			else if (direction == CAM_MOVE_DOWN)
			{
				dir.x -= delta;
			}
			else if (direction == CAM_MOVE_LEFT)
			{
				dir.y += delta;
			}
			else if (direction == CAM_MOVE_RIGHT)
			{
				dir.y -= delta;
			}
		}
		//Build_CAM4DV1_Matrix_Euler(CAM_ROT_SEQ_ZXY);
	}
public:
	int state;
	int attr;

	TNYMATH::POINT4D pos; // 相机在世界坐标中的位置
	TNYMATH::VECTOR4D dir; // 欧拉角度或UVN注视方向

	TNYMATH::VECTOR4D u, v, n;
	TNYMATH::POINT4D target; // UVN目标位置

	float view_dist_h, view_dist_v; // 水平视距和垂直视距
	float view_dist;
	float fov; // 水平方向和垂直方向的视野

	//3d 裁剪面
	float near_clip_z, far_clip_z;

	TNYMATH::PLANE3D rt_clip_plane;
	TNYMATH::PLANE3D lt_clip_plane;
	TNYMATH::PLANE3D tp_clip_plane;
	TNYMATH::PLANE3D bt_clip_plane;

	float viewplane_width, viewplane_height; // 视平面的宽度和高度

	float viewport_width;
	float viewport_height;
	float viewport_center_x;	// 视口的中心
	float viewport_center_y;

	float aspect_ratio; // 宽高比

	TNYMATH::MATRIX4X4 mcam;	// 世界坐标到相机坐标
	TNYMATH::MATRIX4X4 mper;	// 相机坐标到透视坐标
	TNYMATH::MATRIX4X4 mscr;	// 透视坐标到屏幕坐标
};

