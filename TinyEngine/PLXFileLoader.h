#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "TNYMATH.h"
#define PLX_RGB_MASK 0x8000
#define PLX_SHADE_MODE_MASK 0x8000
#define PLX_2SIDED_MASK 0x1000 // 抽取双面状态设置
#define PLX_COLOR_MASK 0x0fff

#define PLX_COLOR_MODE_RGB_FLAG 0x8000
#define PLX_COLOR_MODE_INDEXED_FLAG 0x0000

#define PLX_2SIDED_FLAG 0x1000
#define PLX_1SIDED_FLAG 0x0000

#define PLX_SHADE_MODE_PURE_FLAG 0x0000
#define PLX_SHADE_MODE_FLAT_FLAG 0x2000
#define PLX_SHADE_MODE_GOURAUD_FLAG 0x4000
#define PLX_SHADE_MODE_PHONG_FLAG 0x8000

class PLXFileLoader
{
public:
	PLXFileLoader();
	~PLXFileLoader();

	char* Get_Line_PLG(char* buffer, int maxlength, FILE* fp) {
		int index = 0;
		int length = 0;
		
		while (1) {
			if (!fgets(buffer, maxlength, fp)) {
				return nullptr;
			}
			for (length = strlen(buffer), index = 0; isspace(buffer[index]); index++);
			
			// 检查是否是空行或者注释
			if (index >= length || buffer[index] == '#')
			{
				continue;
			}

			return (&buffer[index]);
		}
	}

	int Load_OBJECT4DV1_PLG(TNYMATH::OBJECT4DV1_PTR obj, char* filename,
		TNYMATH::VECTOR4D_PTR scale,
		TNYMATH::VECTOR4D_PTR pos, // 初始位置
		TNYMATH::VECTOR4D_PTR rot  // 初始旋转角度
	);
};

