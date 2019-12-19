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
	void Init_CAM4DV1(int cam_attr, TNYMATH::POINT4D_PTR cam_pos,
		TNYMATH::VECTOR4D_PTR cam_dir, TNYMATH::POINT4D_PTR cam_target,
		float near_clip_z, float far_clip_z, float fov, float vp_width, float vp_height);

	void Build_CAM4DV1_Matrix_Euler(int cam_rot_seq);
	void Build_CAM4DV1_Matrix_UVN(int mode);
public:
	int state;
	int attr;

	TNYMATH::POINT4D pos; // ��������������е�λ��
	TNYMATH::VECTOR4D dir; // ŷ���ǶȻ�UVNע�ӷ���

	TNYMATH::VECTOR4D u, v, n;
	TNYMATH::POINT4D target; // UVNĿ��λ��

	float view_dist_h, view_dist_v; // ˮƽ�Ӿ�ʹ�ֱ�Ӿ�
	float view_dist;
	float fov; // ˮƽ����ʹ�ֱ�������Ұ

	//3d �ü���
	float near_clip_z, far_clip_z;

	TNYMATH::PLANE3D rt_clip_plane;
	TNYMATH::PLANE3D lt_clip_plane;
	TNYMATH::PLANE3D tp_clip_plane;
	TNYMATH::PLANE3D bt_clip_plane;

	float viewplane_width, viewplane_height; // ��ƽ��Ŀ��Ⱥ͸߶�

	float viewport_width;
	float viewport_height;
	float viewport_center_x;	// �ӿڵ�����
	float viewport_center_y;

	float aspect_ratio; // ���߱�

	TNYMATH::MATRIX4X4 mcam;	// �������굽�������
	TNYMATH::MATRIX4X4 mper;	// ������굽͸������
	TNYMATH::MATRIX4X4 mscr;	// ͸�����굽��Ļ����
};
