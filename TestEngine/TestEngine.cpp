// TestEngine.cpp : 定义应用程序的入口点。
//

#include "d3dUtility.h"
#include "global.h"
#include "TNYMATH.h"
#include "CAM4DV1.h"
#include "TNYScene.h"
#include "PLXFileLoader.h"
#include <vector>
#define MAX_LOADSTRING 100
#pragma comment(lib,"TinyEngine")

using namespace std;
using namespace TNYMATH;
// 全局变量:
std::unique_ptr<CoreEngine> g_device = nullptr;
CAM4DV1 cam; // 相机
//
float g_theta_x = 0.0f;	// 相机与X轴的欧拉角
float g_theta_y = 0.0f;	// 相机与Y轴的欧拉角
float g_theta_z = 0.0f;	// 相机与Z轴的欧拉角
float g_cam_dist = 200;	// 相机到物体的距离，滚轮控制
//
OBJECT4DV1 obj;
std::unique_ptr<TNYScene> g_scene;
std::vector<OBJECT4DV1> g_objlist;
PLXFileLoader plx;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

void MoveTank();
bool Setup()
{
	////g_scene->initScene();
	int towerNum = 20;
	g_objlist.resize(towerNum + 2);

	POINT4D cam_pos = { 0,50,-50,1 };
	VECTOR4D cam_dir = { PI_DIV_4,PI_DIV_2,-150,1 };
	VECTOR4D vscale = { 0.5,0.5,0.5,1 }, vpos = { 0,0,0,1 }, vrot = { 0,0,0,1 };

	std::string file = "tank2.plg";
	if (!plx.Load_OBJECT4DV1_PLG(&g_objlist[0], const_cast<char*>(file.c_str()), &vscale, &vpos, &vrot))
	{
		return false;
	}
	g_objlist[0].dir.z = 1.0f;

	file = "tower1.plg";


	for (int i=1; i<towerNum;i++)
	{
		if (!plx.Load_OBJECT4DV1_PLG(&g_objlist[i], const_cast<char*>(file.c_str()), &vscale, &vpos, &vrot))
		{
			return false;
		}
		// 设置位置
		g_objlist[i].world_pos.x = RAND_RANGE(-300, 300);
		g_objlist[i].world_pos.y = 0;
		g_objlist[i].world_pos.z = RAND_RANGE(-500, 500);
		//char temp[64] = {};
		//sprintf(temp, "x:%.2f, y:%.2f, z:%.2f\n", g_objlist[i].world_pos.x, g_objlist[i].world_pos.y, g_objlist[i].world_pos.z);
		//OutputDebugStringA(temp);
	}

	//file = "marker1.plg";
	//if (!plx.Load_OBJECT4DV1_PLG(&g_objlist[21], const_cast<char*>(file.c_str()), &vscale, &vpos, &vrot))
	//{
	//	return false;
	//}
	//
	//RENDERLIST4DV1 rend_list;
	//
	obj.id = 0;
	obj.dir = { 0,0,0 };

	cam.Init_CAM4DV1(0, &cam_pos, &cam_dir, NULL, 50.0, 500.0, 90, g_device->m_width, g_device->m_heigth);

	return true;
}
void Cleanup()
{
	// Nothing to cleanup in this sample.
	//ReleaseDevice(g_device);
}
void MoveTank()
{
	MATRIX4X4 my_inv;
	VECTOR4D_Normalize(&g_objlist[0].dir);

	if (KEY_DOWN('W'))
	{
		g_objlist[0].world_pos.x += 0.01*g_objlist[0].dir.x;
		g_objlist[0].world_pos.y += 0.01*g_objlist[0].dir.y;
		g_objlist[0].world_pos.z += 0.01*g_objlist[0].dir.z;
	}
	else if (KEY_DOWN('S'))
	{
		g_objlist[0].world_pos.x -= 0.01*g_objlist[0].dir.x;
		g_objlist[0].world_pos.y -= 0.01*g_objlist[0].dir.y;
		g_objlist[0].world_pos.z -= 0.01*g_objlist[0].dir.z;
	}
	else if (KEY_DOWN('A'))
	{
		float theta_y = -0.01;

		float cos_theta = Fast_Cos(theta_y);
		float sin_theta = Fast_Sin(theta_y);
		//MATRIX4X4 my_inv;
		Mat_Init_4x4(&my_inv, cos_theta, 0, -sin_theta, 0,
			0, 1, 0, 0,
			sin_theta, 0, cos_theta, 0,
			0, 0, 0, 1);

		Mat_Mul_VECTOR4D_4x4(&g_objlist[0].dir, &my_inv, &g_objlist[0].dir);

		for (int i = 0; i < g_objlist[0].num_vertices; i++)
		{
			VECTOR4D pResult;
			Mat_Mul_VECTOR4D_4x4(&g_objlist[0].vlist_local[i], &my_inv, &pResult);
			VECTOR4D_COPY(&g_objlist[0].vlist_local[i], &pResult);
		}
		// 相机旋转
		//Mat_Mul_4x4(&cam.mcam, &my_inv, &cam.mcam);

	}
	else if (KEY_DOWN('D'))
	{
		float theta_y = 0.01;

		float cos_theta = Fast_Cos(theta_y);
		float sin_theta = Fast_Sin(theta_y);
		//MATRIX4X4 my_inv;
		Mat_Init_4x4(&my_inv, cos_theta, 0, -sin_theta, 0,
			0, 1, 0, 0,
			sin_theta, 0, cos_theta, 0,
			0, 0, 0, 1);
		Mat_Mul_VECTOR4D_4x4(&g_objlist[0].dir, &my_inv, &g_objlist[0].dir);

		for (int i = 0; i < g_objlist[0].num_vertices; i++)
		{
			VECTOR4D pResult;
			Mat_Mul_VECTOR4D_4x4(&g_objlist[0].vlist_local[i], &my_inv, &pResult);
			VECTOR4D_COPY(&g_objlist[0].vlist_local[i], &pResult);
		}
		//Mat_Mul_4x4(&cam.mcam, &my_inv, &cam.mcam);
	}
}
bool Display(float timeDelta)
{
	static float intervalTime = 0;
	static float theta_y = 0.0f;
	static float theta_x = 0.0f;
	if (g_device) // Only use Device methods if we have a valid device.
	{

		Sleep(10);
		g_device->Clear(0xff000000);

		if (KEY_DOWN(VK_LEFT)) {
			// 相机绕Y轴旋转
			cam.Camera_move(CAM4DV1::CAM_MOVE_SPHERICAL, CAM4DV1::CAM_MOVE_LEFT, 0.01);
		}
		else if (KEY_DOWN(VK_RIGHT))
		{
			cam.Camera_move(CAM4DV1::CAM_MOVE_SPHERICAL, CAM4DV1::CAM_MOVE_RIGHT, 0.01);
		}
		else if (KEY_DOWN(VK_UP))
		{
			cam.Camera_move(CAM4DV1::CAM_MOVE_SPHERICAL, CAM4DV1::CAM_MOVE_UP, 0.01);
		}
		else if (KEY_DOWN(VK_DOWN))
		{
			cam.Camera_move(CAM4DV1::CAM_MOVE_SPHERICAL, CAM4DV1::CAM_MOVE_DOWN, 0.01);
		}


		cam.Build_CAM4DV1_Matrix_UVN(CAM4DV1::UVN_MODE_SPHERICAL);
		// draw tank		
		//// 绘制地形
		for (int i=0;i<20;i++)
		{
			Reset_OBJECT4DV1(&g_objlist[i]);

			MoveTank();

			Model_To_World_OBJECT4DV1(&g_objlist[i]);
			if (!Cull_OBJECT4DV1(&g_objlist[i], &cam, CULL_OBJECT_XYZ_PLANES))
			{
				//Remove_Backfaces_OBJECT4DV1(&g_objlist[i], &cam, true);

				World_To_Camera_OJECT4DV1(&cam, &g_objlist[i]);

				if (Camera_To_Perspective_OBJECT4DV1(&g_objlist[i], &cam))
				{
					// 屏幕变换
					Perspective_To_Screen_OBJECT4DV1(&g_objlist[i], &cam);
					g_device->DrawObject(&g_objlist[i]);
				}
				
			}
			
		}
		//Reset_OBJECT4DV1(&obj);
		////timeval
		////cam.Build_CAM4DV1_Matrix_Euler(CAM4DV1::CAM_ROT_SEQ_ZXY);
		////float cam_thetay = 0.0f;
		//

		////MATRIX4X4 my_inv;
		////MATRIX4X4 mx_inv;
		////if (KEY_DOWN(VK_LEFT)) {
		////	// 相机绕Y轴旋转
		////	cam.Camera_move(CAM4DV1::CAM_MOVE_SPHERICAL, CAM4DV1::CAM_MOVE_LEFT, 0.01);
		////}
		////else if (KEY_DOWN(VK_RIGHT))
		////{
		////	cam.Camera_move(CAM4DV1::CAM_MOVE_SPHERICAL, CAM4DV1::CAM_MOVE_RIGHT, 0.01);
		////}
		////else if (KEY_DOWN(VK_UP))
		////{
		////	cam.Camera_move(CAM4DV1::CAM_MOVE_SPHERICAL, CAM4DV1::CAM_MOVE_UP, 0.01);
		////}
		////else if (KEY_DOWN(VK_DOWN))
		////{
		////	cam.Camera_move(CAM4DV1::CAM_MOVE_SPHERICAL, CAM4DV1::CAM_MOVE_DOWN, 0.01);
		////}
		//cam.Build_CAM4DV1_Matrix_UVN(CAM4DV1::UVN_MODE_SPHERICAL);
		////cam.Build_CAM4DV1_Matrix_Euler(CAM4DV1::CAM_ROT_SEQ_XYZ);
		///*	float cos_theta = Fast_Cos(theta_y);
		//	float sin_theta = Fast_Sin(theta_y);
		//	float cos_theta_x = Fast_Cos(theta_x);
		//	float sin_theta_x = Fast_Sin(theta_x);
		//	Mat_Init_4x4(&my_inv, cos_theta, 0, -sin_theta, 0,
		//		0, 1, 0, 0,
		//		sin_theta, 0, cos_theta, 0,
		//		0, 0, 0, 1);

		//	Mat_Init_4x4(&mx_inv, 1, 0, 0, 0,
		//		0, cos_theta_x, -sin_theta_x, 0,
		//		0, sin_theta_x, cos_theta_x, 0,
		//		0, 0, 0, 1);

		//	MATRIX4X4 m_inv;
		//	Mat_Mul_4x4(&my_inv,&mx_inv,&m_inv);

		//	Mat_Mul_4x4(&cam.mcam, &m_inv, &cam.mcam);*/
		//// 局部坐标转世界坐标
		//Model_To_World_OBJECT4DV1(&obj);
		//// 模型旋转

		//
		////g_scene->DrawScene();
		////// 创建相机变换矩阵
		////cam.Build_CAM4DV1_Matrix_UVN(CAM4DV1::UVN_MODE_SIMPLE);
		//
		////Reset_RENDERLIST4DV1(&rend_list);
		//Remove_Backfaces_OBJECT4DV1(&obj, &cam, true);
		//// 世界坐标到相机坐标
		//World_To_Camera_OJECT4DV1(&cam, &obj);
		//// 相机坐标到透视坐标变换
		//Camera_To_Perspective_OBJECT4DV1(&obj, &cam);
		//// 屏幕变换
		//Perspective_To_Screen_OBJECT4DV1(&obj, &cam);
		//g_device->DrawObject(&obj);
		//g_device->DrawPrimitiveIndex(obj.vlist_screen, obj.vlist_index, TNY_TRANGLELIST, 12);

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
