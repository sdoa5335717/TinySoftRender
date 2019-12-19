#pragma once
#include "TNYMATH.h"
class CAM4DV1;
typedef CAM4DV1* CAM4DV1_PTR;

#define CULL_OBJECT_X_PLANE 0x0001
#define CULL_OBJECT_Y_PLANE 0x0002
#define CULL_OBJECT_Z_PLANE 0x0004
#define CULL_OBJECT_XYZ_PLANES (CULL_OBJECT_X_PLANE|CULL_OBJECT_Y_PLANE|CULL_OBJECT_Z_PLANE)

// transformation control flags
#define TRANSFORM_LOCAL_ONLY       0  // perform the transformation in place on the
									  // local/world vertex list 
#define TRANSFORM_TRANS_ONLY       1  // perfrom the transformation in place on the 
									  // "transformed" vertex list

#define TRANSFORM_LOCAL_TO_TRANS   2  // perform the transformation to the local
									  // vertex list, but store the results in the
									  // transformed vertex list

void World_To_Camera_RENDERLIST4DV1(TNYMATH::RENDERLIST4DV1_PTR rend_list, CAM4DV1_PTR cam);

void World_To_Camera_OJECT4DV1(CAM4DV1_PTR cam, TNYMATH::OBJECT4DV1_PTR obj);

int Cull_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam, int cull_floags);

void Reset_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj);

void Remove_Backfaces_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam);

void Remove_Backfaces_RENDERLIST4DV1(TNYMATH::RENDERLIST4DV1_PTR rend_list, CAM4DV1_PTR cam);

void Camera_To_Perspective_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam);

void Build_Camera_To_Perspective_MATRIX4X4(CAM4DV1_PTR cam, TNYMATH::MATRIX4X4_PTR m);

void Convert_From_Homogeneous4D_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj);

void Perspective_To_Screen_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam);

void Build_Perspective_To_Screen_4D_MATRIX4X4(CAM4DV1_PTR cam, TNYMATH::MATRIX4X4_PTR m);

void Camera_To_Perspective_Screen_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam);

void Camera_To_Perspective_Screen_RENDERLIST4DV1(TNYMATH::RENDERLIST4DV1_PTR rend_list, CAM4DV1_PTR cam);

void Model_To_World_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, int coord_select = TRANSFORM_LOCAL_TO_TRANS);