// TestEngine.cpp : 定义应用程序的入口点。
//

#include "d3dUtility.h"
#include "global.h"
#include "TNYMATH.h"
#include "CAM4DV1.h"
#include "TNYScene.h"
#define MAX_LOADSTRING 100
#pragma comment(lib,"TinyEngine")

using namespace TNYMATH;
// 全局变量:
std::unique_ptr<CoreEngine> g_device = nullptr;
CAM4DV1 cam; // 相机
OBJECT4DV1 obj;
std::unique_ptr<TNYScene> g_scene;

bool Setup()
{
	////g_scene->initScene();
	POINT4D cam_pos = { 0,0,-200,1 };
	VECTOR4D cam_dir = { 0,0,0,1 };

	//VECTOR4D vscale = { 0.5,0.5,0.5,1 }, vpos = { 0,0,0,1 }, vrot = { 0,0,0,1 };
	//RENDERLIST4DV1 rend_list;
	//
	obj.id = 0;
	obj.dir = { 0,0,0 };
	obj.num_polys = 12;
	obj.num_vertices = 8;
	//
	obj.vlist_local[0].x = -50;
	obj.vlist_local[0].y = 50;
	obj.vlist_local[0].z = 50;
	obj.vlist_local[0].w = 1;
	//
	obj.vlist_local[1].x = 50;
	obj.vlist_local[1].y = 50;
	obj.vlist_local[1].z = 50;
	obj.vlist_local[1].w = 1;
	//
	obj.vlist_local[2].x = 50;
	obj.vlist_local[2].y = -50;
	obj.vlist_local[2].z = 50;
	obj.vlist_local[2].w = 1;

	obj.vlist_local[3].x = -50;
	obj.vlist_local[3].y = -50;
	obj.vlist_local[3].z = 50;
	obj.vlist_local[3].w = 1;
	////obj.vlist_local[0].

	obj.vlist_local[4].x = -50;
	obj.vlist_local[4].y = 50;
	obj.vlist_local[4].z = -50;
	obj.vlist_local[4].w = 1;
	//
	obj.vlist_local[5].x = 50;
	obj.vlist_local[5].y = 50;
	obj.vlist_local[5].z = -50;
	obj.vlist_local[5].w = 1;
	//
	obj.vlist_local[6].x = 50;
	obj.vlist_local[6].y = -50;
	obj.vlist_local[6].z = -50;
	obj.vlist_local[6].w = 1;

	obj.vlist_local[7].x = -50;
	obj.vlist_local[7].y = -50;
	obj.vlist_local[7].z = -50;
	obj.vlist_local[7].w = 1;


	obj.vlist_index[0] = 0, obj.vlist_index[1] = 1, obj.vlist_index[2] = 2;
	obj.vlist_index[3] = 0, obj.vlist_index[4] = 2, obj.vlist_index[5] = 3;

	obj.vlist_index[6] = 0, obj.vlist_index[7] = 1, obj.vlist_index[8] = 5;
	obj.vlist_index[9] = 0, obj.vlist_index[10] = 5, obj.vlist_index[11] = 4;
//
	obj.vlist_index[12] = 0, obj.vlist_index[13] = 4, obj.vlist_index[14] = 7;
	obj.vlist_index[15] = 0, obj.vlist_index[16] = 7, obj.vlist_index[17] = 3;
//
	obj.vlist_index[18] = 6, obj.vlist_index[19] = 7, obj.vlist_index[20] = 4;
	obj.vlist_index[21] = 6, obj.vlist_index[22] = 4, obj.vlist_index[23] = 5;
//
	obj.vlist_index[24] = 6, obj.vlist_index[25] = 5, obj.vlist_index[26] = 1;
	obj.vlist_index[27] = 6, obj.vlist_index[28] = 1, obj.vlist_index[29] = 2;
//
	obj.vlist_index[30] = 6, obj.vlist_index[31] = 7, obj.vlist_index[32] = 3;
	obj.vlist_index[33] = 6, obj.vlist_index[34] = 3, obj.vlist_index[35] = 2;

	//g_scene->AddObject(&obj);

	//g_scene->SetCamera(0, &cam_pos, &cam_dir, NULL, 50.0, 500.0, 90, 
	//	g_scene->GetWidth(), g_scene->GetHeight());

	cam.Init_CAM4DV1(0, &cam_pos, &cam_dir, NULL, 50.0, 500.0, 90, g_device->m_width, g_device->m_heigth);

	return true;
}
void Cleanup()
{
	// Nothing to cleanup in this sample.
	//ReleaseDevice(g_device);
}

bool Display(float timeDelta)
{
	static float intervalTime = 0;
	static float theta_y = 0.0f;

	if (g_device) // Only use Device methods if we have a valid device.
	{

		
		Sleep(10);
		g_device->Clear(0xff000000);

		Reset_OBJECT4DV1(&obj);
		//timeval
		// 局部坐标转世界坐标
		Model_To_World_OBJECT4DV1(&obj);
		// 模型旋转
		theta_y += 0.01;
		if (theta_y > PI2) {
			theta_y = 0.0;
		}
		//if (theta_y > PI2) {
		//	theta_y = -theta_y;
		//}
		float cos_theta = Fast_Cos(theta_y);
		float sin_theta = Fast_Sin(theta_y);
		MATRIX4X4 my_inv;
		Mat_Init_4x4(&my_inv, cos_theta, 0, -sin_theta, 0,
			0, 1, 0, 0,
			sin_theta, 0, cos_theta, 0,
			0, 0, 0, 1);

		

		for (int i = 0; i < obj.num_vertices; i++)
		{
			VECTOR4D pResult;
			Mat_Mul_VECTOR4D_4x4(&obj.vlist_trans[i], &my_inv, &pResult);
			VECTOR4D_COPY(&obj.vlist_trans[i], &pResult);
		}
		//
		//g_scene->DrawScene();
		//// 创建相机变换矩阵
		cam.Build_CAM4DV1_Matrix_Euler(CAM4DV1::CAM_ROT_SEQ_ZXY);
		//Build_CAM4DV1_Matrix_Euler(&cam, CAM4DV1::CAM_ROT_SEQ_ZXY);
		//Reset_RENDERLIST4DV1(&rend_list);
		// 世界坐标到相机坐标
		World_To_Camera_OJECT4DV1(&cam, &obj);
		// 相机坐标到透视坐标变换
		Camera_To_Perspective_OBJECT4DV1(&obj, &cam);
		// 屏幕变换
		Perspective_To_Screen_OBJECT4DV1(&obj, &cam);

		g_device->DrawPrimitiveIndex(obj.vlist_screen, obj.vlist_index, TNY_TRANGLELIST, 12);

		g_device->present();
	}
	return true;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	d3d::InitD3D(hInstance, 800, 600, true, g_device);
	Setup();
	d3d::EnterMsgLoop(Display);

	Cleanup();
	
	return 0;
}



LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}
