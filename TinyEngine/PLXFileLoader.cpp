#include "PLXFileLoader.h"
#include <stdlib.h>

using namespace TNYMATH;

PLXFileLoader::PLXFileLoader()
{
}


PLXFileLoader::~PLXFileLoader()
{
}

int PLXFileLoader::Load_OBJECT4DV1_PLG(TNYMATH::OBJECT4DV1_PTR obj, char* filename, 
	TNYMATH::VECTOR4D_PTR scale, 
	TNYMATH::VECTOR4D_PTR pos, /* 初始位置 */ 
	TNYMATH::VECTOR4D_PTR rot /* 初始旋转角度 */)
{
	FILE* fp = nullptr;
	char buffer[256] = {};

	char* token_string = nullptr;

	// 1, 清空 初始化obj
	memset(obj, 0, sizeof(OBJECT4DV1));
	obj->state = OBJECT4DV1_STATE_ACTIVE | OBJECT4DV1_STATE_VISIBLE;

	// 设置物体位置
	obj->world_pos.x = pos->x;
	obj->world_pos.y = pos->y;
	obj->world_pos.z = pos->z;
	obj->world_pos.w = pos->w;

	// 2, 为读取面打开文件
	if (!(fp = fopen(filename, "r")))
	{
		//OutputDebugString("Cannt open PLG file");
		return 0;
	}
	// 读取物体描述符
	if (!(token_string = Get_Line_PLG(buffer, 255, fp)))
	{
		return 0;
	}

	sscanf(token_string, "%s %d %d", obj->name, &obj->num_vertices, &obj->num_polys);

	// 4 加载顶点列表
	for (int vertex = 0; vertex < obj->num_vertices; vertex++)
	{
		if (!(token_string = Get_Line_PLG(buffer, 255, fp)))
		{
			return 0;
		}
		// 分析顶点
		sscanf(token_string, "%f %f %f", &obj->vlist_local[vertex].x, 
			&obj->vlist_local[vertex].y, &obj->vlist_local[vertex].z);

		//
	}
	// 计算平均半径和最大半径
	// Compute_OBJECT4DV1_Radius(obj);
	int poly_surface_desc = 0; //PLG 多边形描述符
	int poly_num_verts = 0;
	char tmp_string[8] = {};
	// 5 加载多边形列表
	for (int poly = 0;poly<obj->num_polys;poly++)
	{
		if (!(token_string = Get_Line_PLG(buffer, 255, fp)))
		{
			return 0;
		}
		sscanf(token_string, "%s %d %d %d %d", tmp_string, &poly_num_verts, &obj->plist[poly].vert[0],
			&obj->plist[poly].vert[1], &obj->plist[poly].vert[2]);
		if (tmp_string[0] == '0' && toupper(tmp_string[1]) == 'X')
		{
			sscanf(tmp_string, "%x", &poly_surface_desc);
		}
		else
		{
			poly_surface_desc = atoi(tmp_string);
		}
		obj->plist[poly].vlist = obj->vlist_local;
		// 提取多边形描述符中的每个字段
		// 单面/双面
		if (poly_surface_desc & PLX_2SIDED_FLAG)
		{
			SET_BIT(obj->plist[poly].attr, POLY4DV1_ATTR_2SIDE);
		}
		else {

		}
		// 设置颜色模式
		if (poly_surface_desc & PLX_COLOR_MODE_RGB_FLAG)
		{
			SET_BIT(obj->plist[poly].attr, POLY4DV1_ATTR_RGB16);
			int red = ((poly_surface_desc & 0x0f00) >> 8);
			int green = ((poly_surface_desc & 0x00f0) >> 4);
			int blue = (poly_surface_desc & 0x000f);
			
			obj->plist[poly].color = 0xffff0000;
		}
		else
		{
			SET_BIT(obj->plist[poly].attr, POLY4DV1_ATTR_8BITCOLOR);
			obj->plist[poly].color = (poly_surface_desc & 0x00ff);
		}

		int shade_mode = (poly_surface_desc & PLX_SHADE_MODE_MASK);
		switch (shade_mode)
		{
		case PLX_SHADE_MODE_PURE_FLAG:
		{
			SET_BIT(obj->plist[poly].attr, POLY4DV1_ATTR_SHADE_MODE_PURE);
			break;
		}
		case PLX_SHADE_MODE_FLAT_FLAG:
		{
			SET_BIT(obj->plist[poly].attr, POLY4DV1_ATTR_SHADE_MODE_FLAT);
			break;
		}
		case PLX_SHADE_MODE_GOURAUD_FLAG:
		{
			SET_BIT(obj->plist[poly].attr, POLY4DV1_ATTR_SHADE_MODE_GOURAUD);
			break;
		}
		case PLX_SHADE_MODE_PHONG_FLAG:
		{
			SET_BIT(obj->plist[poly].attr, POLY4DV1_ATTR_SHADE_MODE_PHONG);
			break;
		}
		default:
			break;
		}

		obj->plist[poly].state = POLY4DV1_STATE_ACTIVE;
	}
	fclose(fp);

	return 1;
}
