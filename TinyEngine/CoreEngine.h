#pragma once
#include <windows.h>
#include "utils.h"
#include "CoreDraw.h"
#include "CAM4DV1.h"
#include "global.h"
#include <mutex>
class CoreEngine
{
public:
	CoreEngine(HWND hWnd);
	virtual ~CoreEngine();

	bool init();

	void installCam(CAM4DV1* pCam);

	void Clear(UTILS::Rgba clearcolor);

	void present();

	void DrawObject(TNYMATH::OBJECT4DV1* pObj)
	{
		if (!pObj) {
			return;
		}
		for (auto i=0;i<pObj->num_polys;i++)
		{
			if (!(pObj->plist[i].state & POLY4DV1_STATE_ACTIVE)||
				(pObj->plist[i].state & POLY4DV1_STATE_BACKFACE)/* ||
				(pObj->plist[i].state & POLY4DV1_STATE_CLIPPED) ||
				(pObj->plist[i].state & POLY4DV1_ATTR_2SIDE) ||
				(pObj->plist[i].state & POLY4DV1_STATE_BACKFACE)*/)
			{
				continue;
			}
			m_draw.Trangle(UTILS::Vertex((int)pObj->vlist_trans[pObj->plist[i].vert[0]].x, (int)pObj->vlist_trans[pObj->plist[i].vert[0]].y, pObj->plist[i].color),
				UTILS::Vertex((int)pObj->vlist_trans[pObj->plist[i].vert[1]].x, (int)pObj->vlist_trans[pObj->plist[i].vert[1]].y, pObj->plist[i].color),
				UTILS::Vertex((int)pObj->vlist_trans[pObj->plist[i].vert[2]].x, (int)pObj->vlist_trans[pObj->plist[i].vert[2]].y, pObj->plist[i].color),
				m_buffer);
		}
		//pObj->
	}
	void SetTransform(int type, const TNYMATH::MATRIX4X4& matx)
	{
		if (type == TNY_WORLD) {
			Mat_Init_4x4(&m_world, matx.M00, matx.M01, matx.M02, matx.M03,
				matx.M10, matx.M11, matx.M12, matx.M13,
				matx.M20, matx.M21, matx.M22, matx.M23,
				matx.M30, matx.M31, matx.M32, matx.M33);
		}
		else if (type == TNY_PROJ)
		{
			Mat_Init_4x4(&m_proj, matx.M00, matx.M01, matx.M02, matx.M03,
				matx.M10, matx.M11, matx.M12, matx.M13,
				matx.M20, matx.M21, matx.M22, matx.M23,
				matx.M30, matx.M31, matx.M32, matx.M33);
		}
	}
	int m_width = 0;
	int m_heigth = 0;

	void DrawPrimitiveIndex(UTILS::Vertex* vertex, UTILS::uint* uIndex,
		int type, int nPrimitiveCount);

	
protected:
	//bool initMainWindow(int,int);
	bool initDevice();
	void DrawPrimitive(TNYMATH::OBJECT4DV1* pObj, int type);
	void TransformToWorld(TNYMATH::OBJECT4DV1* pObj)
	{
		if (!pObj) return;
		for (auto i=0;i<pObj->num_vertices;i++)
		{
			Mat_Mul_VECTOR4D_4x4(&pObj->vlist_local[i], &m_world, &pObj->vlist_trans[i]);
		}
	}
	void TransformToScreen(TNYMATH::OBJECT4DV1* pObj)
	{
		if (!pObj) return;

		Camera_To_Perspective_OBJECT4DV1(pObj, m_cam);

		Perspective_To_Screen_OBJECT4DV1(pObj, m_cam);
		//for (auto i = 0; i < pObj->num_vertices; i++)
		//{
		//	Mat_Mul_VECTOR4D_4x4(&pObj->vlist_local[i], &m_proj, &pObj->vlist_trans[i]);
		//}
	}
	void DrawPrimitive(UTILS::Vertex* vertex,
		int type, int nPrimitiveCount)
	{

	}

private:
	bool m_AppPaused =false;       // 应用是否暂停

	// 后台缓存
	UTILS::Rgba* m_buffer = nullptr;

	HDC m_hDC;
	HDC m_hMem;
	HWND m_hWnd;

	CoreDraw m_draw;

	// 相机
	CAM4DV1* m_cam = nullptr;
	// 世界矩阵
	TNYMATH::MATRIX4X4 m_world;
	// 投影矩阵
	TNYMATH::MATRIX4X4 m_proj;
#ifdef _DEBUG
	HANDLE m_hDebug = INVALID_HANDLE_VALUE;
#endif
};

