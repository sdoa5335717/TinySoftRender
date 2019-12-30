#pragma once
#include <string.h>
#include <corecrt_math.h>
#include "utils.h"
#define PI ((float)3.141592654f)
#define PI2 ((float)6.283185307f)
#define PI_DIV_2 ((float)1.570796327f)
#define PI_DIV_4 ((float)0.785398163f)
#define PI_INV ((float)0.318309886f)

#define FIXP16_SHIFT 16
#define FIXP16_MAG 65536
#define FIXP16_DP_MASK 0x0000ffff
#define FIXP16_WP_MASK 0xffff0000
#define FIXP16_ROUND_UP 0x00008000

#define EPSILON_E4 (float)(1E-4)
#define EPSILON_E5 (float)(1E-5)
#define EPSILON_E6 (float)(1E-6)

#define PARM_LINE_NO_INTERSECT 0
#define PARM_LINE_INTERSECT_IN_SEGMENT 1
#define PARM_LINE_INTERSECT_OUT_SEGMENT 2
#define PARM_LINE_INTERSECT_EVERYWHERE 3

#define MIN(a,b) (((a) < (b))? (a):(b))
#define MAX(a,b) (((a) > (b))? (a):(b))

#define SWAP(a, b, t) {t=a; a=b; b=4;}

#define DEG_TO_RAD(ang) ((ang)*PI/180.0f)
#define RAD_TO_DEG(rad) ((rad)*180.0f/PI)
#define RAND_RANGE(x, y) ( (x) + (rand()%((y)-(x)+1)))

#define SET_BIT(word,bit_flag)   ((word)=((word) | (bit_flag)))
#define RESET_BIT(word,bit_flag) ((word)=((word) & (~bit_flag)))

// 矩阵宏
#define MAT_ZERO_2X2(m) {memset(m, 0, sizeof(MATRIX2X2));}
#define MAT_ZERO_3X3(m) {memset(m, 0, sizeof(MATRIX3X3));}
#define MAT_ZERO_4X4(m) {memset(m, 0, sizeof(MATRIX4X4));}
#define MAT_ZERO_4X3(m) {memset(m, 0, sizeof(MATRIX4X3));}
///
#define MAT_IDENTITY_2X2(m) {memcpy(m, &TNYMATH::IMAT_2X2, sizeof(TNYMATH::MATRIX2X2));}
#define MAT_IDENTITY_3X3(m) {memcpy(m, &TNYMATH::IMAT_3X3, sizeof(TNYMATH::MATRIX3X3));}
#define MAT_IDENTITY_4X4(m) {memcpy(m, &TNYMATH::IMAT_4X4, sizeof(TNYMATH::MATRIX4X4));}
#define MAT_IDENTITY_4X3(m) {memcpy(m, &TNYMATH::IMAT_2X2, sizeof(TNYMATH::MATRIX4X3));}
// 复制矩阵
#define MAT_COPY_2X2(src_mat, dest_mat) {memcpy(dest_mat, src_mat, sizeof(TNYMATH::MATRIX2X2));}
#define MAT_COPY_3X3(src_mat, dest_mat) {memcpy(dest_mat, src_mat, sizeof(TNYMATH::MATRIX3X3));}
#define MAT_COPY_4X4(src_mat, dest_mat) {memcpy(dest_mat, src_mat, sizeof(TNYMATH::MATRIX4X4));}
#define MAT_COPY_4X3(src_mat, dest_mat) {memcpy(dest_mat, src_mat, sizeof(TNYMATH::MATRIX4X3));}
// 定点数宏
#define FIXP16_WP(fp) (fp>>FIXP16_SHIFT)
#define FIXP16_DP(fp) (fp&FIXP16_DP_MASK)

#define INT_TO_FIXP16(i) (i<<FIXP16_SHIFT)
#define FLOAT_TO_FIXP16(f) (((float) (f)*(float)FIXP16_MAG+0.5))
#define FIXP16_TO_FLOAT(fp) (((float)fp)/FIXP16_MAG)

#define POLY4DV1_ATTR_2SIDE 0x0001
#define POLY4DV1_ATTR_TRANSPARENT 0x0002
#define POLY4DV1_ATTR_8BITCOLOR 0x0004
#define POLY4DV1_ATTR_RGB16 0x0008
#define POLY4DV1_ATTR_RGB24 0x0010

#define POLY4DV1_ATTR_SHADE_MODE_PURE 0x0020
#define POLY4DV1_ATTR_SHADE_MODE_FLAT 0x0040
#define POLY4DV1_ATTR_SHADE_MODE_GOURAUD 0x0080
#define POLY4DV1_ATTR_SHADE_MODE_PHONG	0x0100

//多边形和面的状态值
#define POLY4DV1_STATE_ACTIVE 0x0001
#define POLY4DV1_STATE_CLIPPED 0x0002
#define POLY4DV1_STATE_BACKFACE 0x0004

// defines for objects version 1
#define OBJECT4DV1_MAX_VERTICES           1024  // 64
#define OBJECT4DV1_MAX_POLYS              1024 // 128

// states for objects
#define OBJECT4DV1_STATE_ACTIVE           0x0001
#define OBJECT4DV1_STATE_VISIBLE          0x0002 
#define OBJECT4DV1_STATE_CULLED           0x0004

#define RENDERLIST4DV1_MAX_POLYS 1024
namespace TNYMATH
{
	//extern float cos_look[361];
	//extern float sin_look[361];
	// 2D点，2D向量
	typedef struct VECTOR2D_TYP {
		union
		{
			float M[2];

			struct {
				float x, y;
			};
		};
	}VECTOR2D, POINT2D, *VECTOR2D_PTR, *POINT2D_PTR;
	// 3D点， 3D向量
	typedef struct VECTOR3D_TYP {
		union
		{
			float M[3];

			struct {
				float x, y, z;
			};
		};
	}VECTOR3D, POINT3D, *VECTOR3D_PTR, *POINT3D_PTR;
	// 4D 
	typedef struct VECTOR4D_TYP {
		union
		{
			float M[4] = {};

			struct {
				float x, y, z, w;
			};
		};
	}VECTOR4D, POINT4D, *VECTOR4D_PTR, *POINT4D_PTR;
	// 2D顶点
	typedef struct VERTEX2DI_TYP {
		int x = 0, y = 0;
	}VERTEX2DI, *VERTEX2DI_PTR;
	// 2D
	typedef struct VERTEX2DF_TYP {
		float x = 0.0f, y = 0.0f;
	}VERTEX2DF, *VERTEX2DF_PTR;
	//////////////////
	//2D参数化直线
	typedef struct PARMLINE2D_TYPE {
		POINT2D p0, p1;
		VECTOR2D v;	//方向
	}PARMLINE2D, *PARMLINE2D_PTR;
	// 3D参数化直线
	typedef struct PARMLINE3D_TYPE {
		POINT3D p0, p1;
		VECTOR3D v;
	}PARMLINE3D, *PARMLINE3D_PTR;
	// 3D平面
	typedef struct PLANE3D_TYPE {
		POINT3D p0;
		VECTOR3D n;	// 法向量
	}PLANE3D, *PLANE3D_PTR;
	// 矩阵
	typedef struct MATRIX4X4_TYPE {
		union
		{
			float M[4][4];
			struct {
				float M00, M01, M02, M03;
				float M10, M11, M12, M13;
				float M20, M21, M22, M23;
				float M30, M31, M32, M33;
			};
		};
	}MATRIX4X4, *MATRIX4X4_PTR;
	// 4x3
	typedef struct MATRIX4X3_TYPE {
		union
		{
			float M[4][3];
			struct {
				float M00, M01, M02;
				float M10, M11, M12;
				float M20, M21, M22;
				float M30, M31, M32;
			};
		};
	}MATRIX4X3, *MATRIX4X3_PTR;
	// 1x4
	typedef struct MATRIX1X4_TYPE {
		union
		{
			float M[4];
			struct {
				float M00, M01, M02, M03;
			};
		};
	}MATRIX1X4, *MATRIX1X4_PTR;
	// 3x3
	typedef struct MATRIX3X3_TYPE {
		union
		{
			float M[3][3];
			struct {
				float M00, M01, M02;
				float M10, M11, M12;
				float M20, M21, M22;
			};
		};
	}MATRIX3X3, *MATRIX3X3_PTR;
	// 1x3
	typedef struct MATRIX1X3_TYPE {
		union
		{
			float M[3];
			struct {
				float M00, M01, M02;
			};
		};
	}MATRIX1X3, *MATRIX1X3_PTR;
	// 3x2
	typedef struct MATRIX3X2_TYPE {
		union
		{
			float M[3][2];
			struct {
				float M00, M01;
				float M10, M11;
				float M20, M21;
			};
		};
	}MATRIX3X2, *MATRIX3X2_PTR;
	// 2x2
	typedef struct MATRIX2X2_TYPE {
		union
		{
			float M[2][2];
			struct {
				float M00, M01;
				float M10, M11;
			};
		};
	}MATRIX2X2, *MATRIX2X2_PTR;
	// 1x2
	typedef struct MATRIX1X2_TYPE {
		union
		{
			float M[2];
			struct {
				float M00, M01;
			};
		};
	}MATRIX1X2, *MATRIX1X2_PTR;
	// 四元数
	typedef struct QUAT_TYPE
	{
		union {
			float M[4];	// w,x,y,z;
			struct {
				float q0;
				VECTOR3D qv;
			};
			struct {
				float w, x, y, z;
			};
		};


	}QUAT, *QUAT_PTR;
	// 2D极坐标
	typedef struct POLAR2D_TYPE
	{
		float r; //半径
		float theta; // 角度
	}POLAR2D, *POLAR2D_PTR;
	// 3D柱面坐标
	typedef struct CYLINDRICAL3D_TYPE {
		float r;
		float theta;
		float z;
	}CYLINDRICAL3D, *CYLINDRICAL3D_PTR;
	// 3D球面坐标
	typedef struct SPHERICAL3D_TYPE {
		float p;
		float theta;
		float phi;
	}SPHERICAL3D, *SPHERICAL3D_PTR;
	// 顶点数
	typedef int FIXP16;
	typedef int* FIXP16_PTR;
	//
	const MATRIX4X4 IMAT_4X4 = { 1,0,0,0,
								0,1,0,0,
								0,0,1,0,
								0,0,0,1 };
	const MATRIX4X3 IMAT_4X3 = { 1,0,0,
							0,1,0,
							0,0,1,
							0,0,0 };
	const MATRIX3X3 IMAT_3X3 = { 1,0,0,
							0,1,0,
							0,0,1 };

	const MATRIX2X2 IMAT_2X2 = { 1,0,
						0,1 };
	//////////////////////
	// 多边形
	typedef struct POLY_EX_TYP_1{
		POINT3D v[3];
	}POLY_EX_1,*POLY_EX_1_PTR;
	typedef struct POLY_EX_TYP_2 {
		POINT3D_PTR vlist;
		int vertices[3];
	}POLY_EX_2,*POLY_EX_2_PTR;
	typedef struct POLY4DV1_TYP {
		int state;
		int attr;
		int color;
		POINT4D_PTR vlist;
		int vert[3];
	}POLY4DV1, *POLY4DV1_PTR;

	typedef struct POLYF4DV1_TYP {
		int state;
		int attr;
		int color;

		POINT4D vlist[3];	// 三角形顶点
		POINT4D tvlist[3];	// 变换后的顶点

		POLYF4DV1_TYP* next;
		POLYF4DV1_TYP* prev;
	}POLYF4DV1,*POLYF4DV1_PTR;

	typedef struct OBJECT4DV1_TYP {
		unsigned int id;
		char name[64];
		int state;
		int attr;
		float avg_radius;	// 物体的平均半径
		float max_radius;	// 物体的最大半径
		POINT4D world_pos;	// 物体在世界坐标系中的位置
		VECTOR4D dir; // 物体局部坐标系下的旋转角度，为用户定义的坐标或单位方向向量
		VECTOR4D ux, uy, uz;	// 记录物体朝向的局部坐标轴，物体被旋转时，将相应的旋转。

		int num_vertices;
		POINT4D vlist_local[64];
		POINT4D vlist_trans[64];
		UTILS::uint vlist_index[192];
		UTILS::Vertex vlist_screen[64];

		int num_polys;
		POLY4DV1 plist[128]; // 存储多边形的数组
	}OBJECT4DV1, *OBJECT4DV1_PTR;
	// 渲染列表
	typedef struct RENDERLIST4DV1_TYP {
		int state;
		int attr;
		// 渲染列表是一个指针数组，其中每个指针指向一个自包含的，可渲染的多边形面(POLY4DV1)
		POLYF4DV1_PTR poly_ptrs[RENDERLIST4DV1_MAX_POLYS];
		// 为了避免每一帧都为多边形分配和释放存储空间，多边形存储在下述数组中
		POLY4DV1 poly_data[RENDERLIST4DV1_MAX_POLYS];

		int num_polys;
	}RENDERLIST4DV1,*RENDERLIST4DV1_PTR;
	//////////////////////////
	void VECTOR2D_ZERO(VECTOR2D_PTR v);
	void VECTOR3D_ZERO(VECTOR3D_PTR v);
	void VECTOR4D_ZERO(VECTOR4D_PTR v);
	//////////////////////////
	void VECTOR2D_INITXY(VECTOR2D_PTR v, float x, float y);
	void VECTOR3D_INITXYZ(VECTOR3D_PTR v, float x, float y, float z);
	void VECTOR4D_INITXYZ(VECTOR4D_PTR v, float x, float y, float z);
	/////////////////////////
	void VECTOR2D_INIT(VECTOR2D_PTR vdst, VECTOR2D_PTR vsrc);
	void VECTOR3D_INIT(VECTOR3D_PTR vdst, VECTOR3D_PTR vsrc);
	void VECTOR4D_INIT(VECTOR4D_PTR vdst, VECTOR4D_PTR vsrc);
	////////////////////
	void VECTOR2D_COPY(VECTOR2D_PTR vdst, VECTOR2D_PTR vsrc);
	void VECTOR3D_COPY(VECTOR3D_PTR vdst, VECTOR3D_PTR vsrc);
	void VECTOR4D_COPY(VECTOR4D_PTR vdst, VECTOR4D_PTR vsrc);
	////////////////////
	void POINT2D_INIT(POINT2D_PTR vdst, POINT2D_PTR vsrc);
	void POINT3D_INIT(POINT3D_PTR vdst, POINT3D_PTR vsrc);
	void POINT4D_INIT(POINT4D_PTR vdst, POINT4D_PTR vsrc);
	////////////////////
	void POINT2D_COPY(POINT2D_PTR vdst, POINT2D_PTR vsrc);
	void POINT3D_COPY(POINT3D_PTR vdst, POINT3D_PTR vsrc);
	void POINT4D_COPY(POINT4D_PTR vdst, POINT4D_PTR vsrc);
	//// 矩阵转置
	void MAT_TRANSPOSE_3X3(MATRIX3X3_PTR m);
	void MAT_TRANSPOSE_4X4(MATRIX4X4_PTR m);
	void MAT_TRANSPOSE_3X3(MATRIX3X3_PTR m, MATRIX3X3_PTR mt);
	void MAT_TRANSPOSE_4X4(MATRIX4X4_PTR m, MATRIX4X4_PTR mt);
	void MAT_COLUMN_SWAP_2X2(MATRIX2X2_PTR m, int c, MATRIX1X2_PTR v);
	void MAT_COLUMN_SWAP_3X3(MATRIX3X3_PTR m, int c, MATRIX1X3_PTR v);
	void MAT_COLUMN_SWAP_4X4(MATRIX4X4_PTR m, int c, MATRIX1X4_PTR v);
	void MAT_COLUMN_SWAP_4X3(MATRIX4X3_PTR m, int c, MATRIX1X4_PTR v);
	// 四元数
	void QUAT_ZERO(QUAT_PTR q);
	void QUAT_INITWXYZ(QUAT_PTR q, float w, float x, float y, float z);
	void QUAT_INIT_VECTOR3D(QUAT_PTR q, VECTOR3D_PTR v);
	void QUAT_INIT(QUAT_PTR qdst, QUAT_PTR qsrc);
	void QUAT_COPY(QUAT_PTR qdst, QUAT_PTR qsrc);
	// 通用三角函数
	float Fast_Sin(float theta);
	float Fast_Cos(float theta);
	// 距离函数
	int Fast_Distance_2D(int x, int y);
	float Fast_Distance_3D(float fx, float fy, float fz);
	// 极坐标，柱面坐标，球面坐标函数
	void POLAR2D_To_POINT2D(POLAR2D_PTR polar, POINT2D_PTR rect);
	void POLAR2D_To_RectXY(POLAR2D_PTR polar, float* x, float* y);
	void POINT2D_To_POLAR2D(POINT2D_PTR rect, POLAR2D_PTR polar);
	void POINT2D_To_PolarRTh(POINT2D_PTR rect, float *r, float* theta);
	void CYLINDRICAL3D_To_POINT3D(CYLINDRICAL3D_PTR cyl, POINT3D_PTR rect);
	void CYLINDRICAL3D_To_RectXYZ(CYLINDRICAL3D_PTR cyl, float* x, float* y, float* z);
	void POINT3D_To_CYLINDRICAL3D(POINT3D_PTR rect, CYLINDRICAL3D_PTR cyl);
	void POINT3D_To_CylindricalRThZ(POINT3D_PTR rect, float* r, float* theta, float* z);
	void SPHERICAL3D_To_POINT3D(SPHERICAL3D_PTR sph, POINT3D_PTR rect);
	void SPHERICAL3D_To_RectXYZ(SPHERICAL3D_PTR sph, float* x, float* y, float* z);
	void POINT3D_To_SPHERICAL3D(POINT3D_PTR rect, SPHERICAL3D_PTR sph);
	void POINT3D_To_ShpericalPThPh(POINT3D_PTR rect, float* p, float* theta, float* phi);
	// 2D向量函数
	void VECTOR2D_Add(VECTOR2D_PTR va, VECTOR2D_PTR vb, VECTOR2D_PTR vsum);
	VECTOR2D VECTOR2D_Add(VECTOR2D_PTR va, VECTOR2D_PTR vb);
	void VECTOR2D_Sub(VECTOR2D_PTR va, VECTOR2D_PTR vb, VECTOR2D_PTR vdiff);
	VECTOR2D VECTOR2D_Sub(VECTOR2D_PTR va, VECTOR2D_PTR vb);
	void VECTOR2D_Scale(float k, VECTOR2D_PTR va);
	void VECTOR2D_Scale(float k, VECTOR2D_PTR va, VECTOR2D_PTR vscaled);
	///
	float VECTOR2D_Dot(VECTOR2D_PTR va, VECTOR2D_PTR vb);
	float VECTOR2D_Length(VECTOR2D_PTR va);
	float VECTOR_Length_Fast(VECTOR2D_PTR va);
	void VECTOR2D_Normalize(VECTOR2D_PTR va);
	void VECTOR2D_Normalize(VECTOR2D_PTR va, VECTOR2D_PTR vn);
	void VECTOR2D_Build(VECTOR2D_PTR init, VECTOR2D_PTR term, VECTOR2D_PTR result);
	float VECTOR2D_CosTh(VECTOR2D_PTR va, VECTOR2D_PTR vb);
	void VECTOR2D_Print(VECTOR2D_PTR va, char* name);
	//3D向量
	void VECTOR3D_Add(VECTOR3D_PTR va, VECTOR3D_PTR vb, VECTOR3D_PTR vsum);
	VECTOR3D VECTOR3D_Add(VECTOR3D_PTR va, VECTOR3D_PTR vb);
	void VECTOR3D_Sub(VECTOR3D_PTR va, VECTOR3D_PTR vb, VECTOR3D_PTR vdiff);
	VECTOR3D VECTOR3D_Sub(VECTOR3D_PTR va, VECTOR3D_PTR vb);
	void VECTOR3D_Scale(float k, VECTOR3D_PTR va);
	void VECTOR3D_Scale(float k, VECTOR3D_PTR va, VECTOR3D_PTR vscaled);
	///
	float VECTOR3D_Dot(VECTOR3D_PTR va, VECTOR3D_PTR vb);
	void VECTOR3D_Cross(VECTOR3D_PTR va, VECTOR3D_PTR vb, VECTOR3D_PTR vn);
	VECTOR3D VECTOR3D_Cross(VECTOR3D_PTR va, VECTOR3D_PTR vb);
	float VECTOR3D_Length(VECTOR3D_PTR va);
	float VECTOR3D_Length_Fast(VECTOR3D_PTR va);
	void VECTOR3D_Normalize(VECTOR3D_PTR va);
	void VECTOR3D_Normalize(VECTOR3D_PTR va, VECTOR3D_PTR vn);
	void VECTOR3D_Build(VECTOR3D_PTR init, VECTOR3D_PTR term, VECTOR3D_PTR result);
	float VECTOR3D_CosTh(VECTOR3D_PTR va, VECTOR3D_PTR vb);
	void VECTOR3D_Print(VECTOR3D_PTR va, char* name);
	// 4D向量
	void VECTOR4D_Add(VECTOR4D_PTR va, VECTOR4D_PTR vb, VECTOR4D_PTR vsum);
	VECTOR4D VECTOR4D_Add(VECTOR4D_PTR va, VECTOR4D_PTR vb);
	void VECTOR4D_Sub(VECTOR4D_PTR va, VECTOR4D_PTR vb, VECTOR4D_PTR vdiff);
	VECTOR4D VECTOR4D_Sub(VECTOR4D_PTR va, VECTOR4D_PTR vb);
	void VECTOR4D_Scale(float k, VECTOR4D_PTR va);
	void VECTOR4D_Scale(float k, VECTOR4D_PTR va, VECTOR4D_PTR vscaled);
	///
	float VECTOR4D_Dot(VECTOR4D_PTR va, VECTOR4D_PTR vb);
	void VECTOR4D_Cross(VECTOR4D_PTR va, VECTOR4D_PTR vb, VECTOR4D_PTR vn);
	VECTOR4D VECTOR4D_Cross(VECTOR4D_PTR va, VECTOR4D_PTR vb);
	float VECTOR4D_Length(VECTOR4D_PTR va);
	float VECTOR4D_Length_Fast(VECTOR4D_PTR va);
	void VECTOR4D_Normalize(VECTOR4D_PTR va);
	void VECTOR4D_Normalize(VECTOR4D_PTR va, VECTOR4D_PTR vn);
	void VECTOR4D_Build(VECTOR4D_PTR init, VECTOR4D_PTR term, VECTOR4D_PTR result);
	float VECTOR4D_CosTh(VECTOR4D_PTR va, VECTOR4D_PTR vb);
	void VECTOR4D_Print(VECTOR4D_PTR va, char* name);
	// 2x2矩阵
	void Mat_Init_2X2(MATRIX2X2_PTR ma, float m00, float m01, float m10, float m11);
	void Print_Mat_2X2(MATRIX2X2_PTR ma, char* name);
	float Mat_Det_2X2(MATRIX2X2_PTR m);
	void Mat_Add_2X2(MATRIX2X2_PTR ma, MATRIX2X2_PTR mb, MATRIX2X2_PTR msum);
	void Mat_Mul_2X2(MATRIX2X2_PTR ma, MATRIX2X2_PTR mb, MATRIX2X2_PTR mprod);
	int Mat_Inverse_2X2(MATRIX2X2_PTR m, MATRIX2X2_PTR mi);
	int Solve_2X2_System(MATRIX2X2_PTR A, MATRIX1X2_PTR X, MATRIX1X2_PTR B);
	// 3x3矩阵
	int Mat_Mul_1x2_3x2(MATRIX1X2_PTR ma, MATRIX3X2_PTR mb, MATRIX1X2_PTR mprod);
	int Mat_Mul_1x3_3x3(MATRIX1X3_PTR ma, MATRIX3X3_PTR mb, MATRIX3X3_PTR mprod);
	int Mat_Mul_3x3(MATRIX3X3_PTR ma, MATRIX3X3_PTR mb, MATRIX3X3_PTR mprod);
	int Mat_Init_3x2(MATRIX3X2_PTR ma, float m00, float m01, float m10,
		float m11, float m20, float m21);
	void Mat_Add_3x3(MATRIX3X3_PTR ma, MATRIX3X3_PTR mb, MATRIX3X3_PTR msum);
	void Mat_Mul_VECTOR3D_3x3(VECTOR3D_PTR va, MATRIX3X3_PTR mb, VECTOR3D_PTR vprod);
	int Mat_Inverse_3x3(MATRIX3X3_PTR m, MATRIX3X3_PTR mi);
	void Mat_Init_3x3(MATRIX3X3_PTR ma,
		float m00, float m01, float m02,
		float m10, float m11, float m12,
		float m20, float m21, float m22);
	void Print_Mat_3x3(MATRIX3X3_PTR ma, char* name);
	float Mat_Det_3x3(MATRIX3X3_PTR m);

	int Solve_3x3_System(MATRIX3X3_PTR A, MATRIX1X3_PTR X, MATRIX1X3_PTR B);
	// 4x4矩阵
	void Mat_Add_4x4(MATRIX4X4_PTR ma, MATRIX4X4_PTR mb, MATRIX4X4_PTR msum);
	int Mat_Mul_4x4(MATRIX4X4_PTR ma, MATRIX4X4_PTR mb, MATRIX4X4_PTR mprod);
	void Mat_Mul_1x4_4x4(MATRIX1X4_PTR ma, MATRIX4X4_PTR mb, MATRIX1X4_PTR mprod);
	void Mat_Mul_VECTOR3D_4x4(VECTOR3D_PTR va, MATRIX4X4_PTR mb, VECTOR3D_PTR vprod);
	void Mat_Mul_VECTOR3D_4x3(VECTOR3D_PTR va, MATRIX4X3_PTR mb, VECTOR3D_PTR vprod);
	void Mat_Mul_VECTOR4D_4x4(VECTOR4D_PTR va, MATRIX4X4_PTR mb, VECTOR4D_PTR vprod);
	void Mat_Mul_VECTOR4D_4x3(VECTOR4D_PTR va, MATRIX4X3_PTR mb, VECTOR4D_PTR vprod);
	int Mat_Inverse_4x4(MATRIX4X4_PTR m, MATRIX4X4_PTR mi);
	void Mat_Init_4x4(MATRIX4X4_PTR ma,
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33);
	void Print_Mat_4x4(MATRIX4X4_PTR ma, char* name);
	//////
	// 四元数函数
	void QUAT_Add(QUAT_PTR q1, QUAT_PTR q2, QUAT_PTR qaum);
	void QUAT_Sub(QUAT_PTR q, QUAT_PTR q2, QUAT_PTR qdiff);
	void QUAT_Conjuate(QUAT_PTR q, QUAT_PTR qconj);
	void QUAT_Scale(QUAT_PTR q, float scale, QUAT_PTR qs);
	void QUAT_Scale(QUAT_PTR q, float scale);
	float QUAT_Norm(QUAT_PTR q);
	float QUAT_Norm2(QUAT_PTR q);
	void QUAT_Normalize(QUAT_PTR q, QUAT_PTR qn);
	void QUAT_Normalize(QUAT_PTR q);
	void QUAT_Unit_Inverse(QUAT_PTR q, QUAT_PTR qi);
	void QUAT_Unit_Inverse(QUAT_PTR q);
	void QUAT_Mul(QUAT_PTR q1, QUAT_PTR q2, QUAT_PTR q3, QUAT_PTR qprod);
	void QUAT_Triple_Product(QUAT_PTR q1, QUAT_PTR q2, QUAT_PTR q3, QUAT_PTR qprod);
	void VECTOR3D_Theta_To_QUAT(QUAT_PTR q, VECTOR3D_PTR v, float theta);
	void VECTOR4D_Theta_To_QUAT(QUAT_PTR q, VECTOR4D_PTR v, float theta);
	void EulerZYX_To_QUAT(QUAT_PTR q, float theta_z, float theta_y, float theta_x);
	void QUAT_To_VECTOR3D_Theta(QUAT_PTR q, VECTOR3D_PTR v, float* theta);
	void QUAT_Print(QUAT_PTR q, char* name);
	// 2D 参数化直线函数
	void Init_Parm_Line2D(POINT2D_PTR p_init, POINT2D_PTR p_term, PARMLINE2D_PTR p);
	void Compute_Parm_Line2D(PARMLINE2D_PTR p, float t, POINT2D_PTR pt);
	int Intersect_Parm_Lines2D(PARMLINE2D_PTR p1, PARMLINE2D_PTR p2, float *t1, float *t2);
	int Intersect_Parm_Lines2D(PARMLINE2D_PTR p1, PARMLINE2D_PTR p2, POINT2D_PTR pt);
	// 3D 参数化直线函数
	void Init_Parm_Line3D(POINT3D_PTR p_init, POINT3D_PTR p_term, PARMLINE3D_PTR p);
	void Compute_Parm_Line3D(PARMLINE3D_PTR p, float t, POINT3D_PTR pt);
	// 3D 平面函数
	void PLANE3D_Init(PLANE3D_PTR plane, POINT3D_PTR p0, VECTOR3D_PTR normal, int normalize);
	float Compute_Point_In_Plane3D(POINT3D_PTR pt, PLANE3D_PTR plane);
	int Intersect_Parm_Line3D_Plane3D(PARMLINE3D_PTR pline, PLANE3D_PTR plane, float* t, POINT3D_PTR pt);
	// 顶点函数
	FIXP16 FIXP16_MUL(FIXP16 fp1, FIXP16 fp2);
	FIXP16 FIXP16_DIV(FIXP16 fp1, FIXP16 fp2);
	void FIXP16_Print(FIXP16 fp);
}