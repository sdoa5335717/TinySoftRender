#include "global.h"
#include "CAM4DV1.h"
#include <assert.h>
using namespace TNYMATH;
void World_To_Camera_RENDERLIST4DV1(TNYMATH::RENDERLIST4DV1_PTR rend_list, CAM4DV1_PTR cam)
{
	for (int poly = 0; poly < rend_list->num_polys; poly++)
	{
		POLYF4DV1_PTR curr_poly = rend_list->poly_ptrs[poly];

		// 当多边形处于活动状态，可见时才对它进行变换
		if ((curr_poly == NULL) || 
			!(curr_poly->state & POLY4DV1_STATE_ACTIVE) || 
			(curr_poly->state & POLY4DV1_STATE_CLIPPED) ||
			(curr_poly->state&POLY4DV1_STATE_BACKFACE))
		{
			continue;
		}
		for (int vertex =0;vertex < 3;vertex++)
		{
			POINT4D presult;
			Mat_Mul_VECTOR4D_4x4(&curr_poly->tvlist[vertex], &cam->mcam, &presult);
			VECTOR4D_COPY(&curr_poly->tvlist[vertex], &presult);
		}
	}
}

void World_To_Camera_OJECT4DV1(CAM4DV1_PTR cam, TNYMATH::OBJECT4DV1_PTR obj)
{
	for (int vertex =0;vertex<obj->num_vertices;vertex++)
	{
		POINT4D presult;
		Mat_Mul_VECTOR4D_4x4(&obj->vlist_trans[vertex], &cam->mcam, &presult);
		VECTOR4D_COPY(&obj->vlist_trans[vertex], &presult);
	}
}

int Cull_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam, int cull_flags)
{
	// 1将物体的包围球球心变换为相机坐标
	POINT4D sphere_pos;

	Mat_Mul_VECTOR4D_4x4(&obj->world_pos, &cam->mcam, &sphere_pos);

	// 2 根据剔除标记对物体执行剔除操作
	if (cull_flags & CULL_OBJECT_Z_PLANE)
	{
		if (((sphere_pos.z - obj->max_radius) > cam->far_clip_z) || ((sphere_pos.z + obj->max_radius) < cam->near_clip_z))
		{
			SET_BIT(obj->state, OBJECT4DV1_STATE_CULLED);
			return 1;
		}
	}

	if (cull_flags & CULL_OBJECT_X_PLANE)
	{
		float z_test = (0.5)*cam->viewplane_width*sphere_pos.z / cam->view_dist;

		if (((sphere_pos.x - obj->max_radius) > z_test) || ((sphere_pos.x + obj->max_radius) < -z_test))
		{
			SET_BIT(obj->state, OBJECT4DV1_STATE_CULLED);
			return 1;
		}
	}


	if (cull_flags & CULL_OBJECT_Y_PLANE)
	{
		float z_test = (0.5)*cam->viewplane_height*sphere_pos.z / cam->view_dist;

		if (((sphere_pos.y - obj->max_radius) > z_test) || ((sphere_pos.y + obj->max_radius) < -z_test))
		{
			SET_BIT(obj->state, OBJECT4DV1_STATE_CULLED);
			return 1;
		}
	}
	return 0;
}

void Reset_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj)
{
	RESET_BIT(obj->state, OBJECT4DV1_STATE_CULLED);
	for (int poly = 0;poly<obj->num_polys;poly++)
	{
		POLY4DV1_PTR curr_poly = &obj->plist[poly];
		if (!(curr_poly->state & POLY4DV1_STATE_ACTIVE))
		{
			continue;
		}

		RESET_BIT(curr_poly->state, POLY4DV1_STATE_CLIPPED);
		RESET_BIT(curr_poly->state, POLY4DV1_STATE_BACKFACE);
	}
}

void Remove_Backfaces_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam)
{
	if (obj->state & OBJECT4DV1_STATE_CULLED)
	{
		return;
	}
	for (int poly = 0; poly < obj->num_polys; poly++)
	{

		POLY4DV1_PTR curr_poly = &obj->plist[poly];
		if (!(curr_poly->state & POLY4DV1_STATE_ACTIVE) /*||*/
			/*			(curr_poly->state & POLY4DV1_STATE_CLIPPED) ||
						(curr_poly->state & POLY4DV1_ATTR_2SIDE) ||
						(curr_poly->state & POLY4DV1_STATE_BACKFACE)*/)
		{
			continue;
		}
		int vindex_0 = curr_poly->vert[0];
		int vindex_1 = curr_poly->vert[1];
		int vindex_2 = curr_poly->vert[2];
		// 计算多边形面法线
		VECTOR4D u, v, n;

		VECTOR4D_Build(&obj->vlist_trans[vindex_0], &obj->vlist_trans[vindex_1], &u);
		VECTOR4D_Build(&obj->vlist_trans[vindex_0], &obj->vlist_trans[vindex_2], &v);

		VECTOR4D_Cross(&u, &v, &n);
		//n.x = -n.x;
		//n.y = -n.y;
		//n.z = -n.z;
		VECTOR4D view;
		VECTOR4D_Build(&obj->vlist_trans[vindex_0], &cam->pos, &view);

		float dp = VECTOR4D_Dot(&n, &view);
		if (dp <= 0.0) {
			SET_BIT(curr_poly->state, POLY4DV1_STATE_BACKFACE);
		}
	}
}

void Remove_Backfaces_RENDERLIST4DV1(TNYMATH::RENDERLIST4DV1_PTR rend_list, CAM4DV1_PTR cam)
{
	for (int poly = 0; poly<rend_list->num_polys;poly++)
	{
		POLYF4DV1_PTR curr_poly = rend_list->poly_ptrs[poly];

		if ((curr_poly == NULL) || (!(curr_poly->state&POLY4DV1_STATE_ACTIVE)) ||
			(curr_poly->state&POLY4DV1_STATE_CLIPPED) ||
			(curr_poly->attr&POLY4DV1_ATTR_2SIDE) ||
			(curr_poly->state&POLY4DV1_STATE_BACKFACE))
		{
			continue;
		}

		VECTOR4D u, v, n;

		VECTOR4D_Build(&curr_poly->tvlist[0], &curr_poly->tvlist[1], &u);
		VECTOR4D_Build(&curr_poly->tvlist[0], &curr_poly->tvlist[2], &v);
		VECTOR4D_Cross(&u, &v, &n);

		VECTOR4D view;
		VECTOR4D_Build(&curr_poly->tvlist[0], &cam->pos, &view);

		float dp = VECTOR4D_Dot(&n, &view);
		if (dp <= 0.0) {
			SET_BIT(curr_poly->state, POLY4DV1_STATE_BACKFACE);
		}
	}
}

void Camera_To_Perspective_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam)
{
	for (int vertex =0;vertex<obj->num_vertices;vertex++)
	{
		float z = obj->vlist_trans[vertex].z;
		obj->vlist_trans[vertex].x = cam->view_dist*obj->vlist_trans[vertex].x / z;
		obj->vlist_trans[vertex].y = cam->view_dist*obj->vlist_trans[vertex].y / z;

		assert(obj->vlist_trans[vertex].x >= -1.0f && obj->vlist_trans[vertex].x <= 1.0f);
		assert(obj->vlist_trans[vertex].y >= -1.0f && obj->vlist_trans[vertex].y <= 1.0f);
	}
}

void Build_Camera_To_Perspective_MATRIX4X4(CAM4DV1_PTR cam, TNYMATH::MATRIX4X4_PTR m)
{
	Mat_Init_4x4(m, cam->view_dist_h, 0, 0, 0,
		0, cam->view_dist_v*cam->aspect_ratio, 0, 0,
		0, 0, 1, 1,
		0, 0, 0, 1);////
}

void Convert_From_Homogeneous4D_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj)
{
	for (int vertex =0; vertex<obj->num_vertices;vertex++)
	{
		//VECTOR4D_DIV_BY_W()
	}
}

void Perspective_To_Screen_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam)
{
	float alpha = (0.5*cam->viewport_width - 0.5);
	float beta = (0.5*cam->viewport_height - 0.5);
	for (int vertex=0;vertex < obj->num_vertices;vertex++)
	{
		obj->vlist_trans[vertex].x = alpha + alpha * obj->vlist_trans[vertex].x;
		obj->vlist_trans[vertex].y = beta - beta * obj->vlist_trans[vertex].y;

		obj->vlist_screen[vertex].x = obj->vlist_trans[vertex].x;
		obj->vlist_screen[vertex].y = obj->vlist_trans[vertex].y;

		obj->vlist_screen[vertex]._color = 0xffff0000;
	}
}

void Build_Perspective_To_Screen_4D_MATRIX4X4(CAM4DV1_PTR cam, TNYMATH::MATRIX4X4_PTR m)
{
	float alpha = (0.5*cam->viewport_width - 0.5);
	float beta = (0.5*cam->viewport_height - 0.5);

	Mat_Init_4x4(m, alpha, 0, 0, 0,
		0, -beta, 0, 0,
		alpha, beta, 1, 0,
		0, 0, 0, 1);
}

void Camera_To_Perspective_Screen_OBJECT4DV1(TNYMATH::OBJECT4DV1_PTR obj, CAM4DV1_PTR cam)
{
	float alpha = (0.5*cam->viewport_width - 0.5);
	float beta = (0.5*cam->viewport_height - 0.5);

	for (int vertex=0;vertex<obj->num_vertices;vertex++)
	{
		float z = obj->vlist_trans[vertex].z;

		// 根据相机的观察参数对顶点进行变换
		obj->vlist_trans[vertex].x = cam->view_dist_h*obj->vlist_trans[vertex].x / z;
		obj->vlist_trans[vertex].y = cam->view_dist_v * obj->vlist_trans[vertex].y*cam->aspect_ratio / z;

		obj->vlist_trans[vertex].x = obj->vlist_trans[vertex].x + alpha;
		obj->vlist_trans[vertex].y = -obj->vlist_trans[vertex].y + beta;
	}
}

void Camera_To_Perspective_Screen_RENDERLIST4DV1(TNYMATH::RENDERLIST4DV1_PTR rend_list, CAM4DV1_PTR cam)
{
	for (int poly = 0; poly < rend_list->num_polys; poly++)
	{
		POLYF4DV1_PTR curr_poly = rend_list->poly_ptrs[poly];
		if ((curr_poly == NULL) || (!(curr_poly->state&POLY4DV1_STATE_ACTIVE)) ||
			(curr_poly->state & POLY4DV1_STATE_CLIPPED) ||
			(curr_poly->state & POLY4DV1_STATE_BACKFACE))
		{
			continue;
		}

		float alpha = (0.5*cam->viewport_width - 0.5);
		float beta = (0.5*cam->viewport_height - 0.5);

		for (int vertex = 0;vertex<3;vertex++)
		{
			float z = curr_poly->vlist[vertex].z;

			curr_poly->tvlist[vertex].x = cam->view_dist_h*curr_poly->tvlist[vertex].x / z;
			curr_poly->tvlist[vertex].y = cam->view_dist_v*curr_poly->tvlist[vertex].y * cam->aspect_ratio / z;

			curr_poly->tvlist[vertex].x = curr_poly->tvlist[vertex].x + alpha;
			curr_poly->tvlist[vertex].y = -curr_poly->tvlist[vertex].y + beta;
		}
	}
}
void Model_To_World_OBJECT4DV1(OBJECT4DV1_PTR obj, int coord_select)
{
	// NOTE: Not matrix based
	// this function converts the local model coordinates of the
	// sent object into world coordinates, the results are stored
	// in the transformed vertex list (vlist_trans) within the object

	// interate thru vertex list and transform all the model/local 
	// coords to world coords by translating the vertex list by
	// the amount world_pos and storing the results in vlist_trans[]

	if (coord_select == TRANSFORM_LOCAL_TO_TRANS)
	{
		for (int vertex = 0; vertex < obj->num_vertices; vertex++)
		{
			// translate vertex
			VECTOR4D_Add(&obj->vlist_local[vertex], &obj->world_pos, &obj->vlist_trans[vertex]);
		} // end for vertex
	} // end if local
	else
	{ // TRANSFORM_TRANS_ONLY
		for (int vertex = 0; vertex < obj->num_vertices; vertex++)
		{
			// translate vertex
			VECTOR4D_Add(&obj->vlist_trans[vertex], &obj->world_pos, &obj->vlist_trans[vertex]);
		} // end for vertex
	} // end else trans

} // end Model_To_World_OBJECT4DV1
