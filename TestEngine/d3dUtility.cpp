//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: d3dUtility.cpp
// 
// Author: Frank Luna (C) All Rights Reserved
//
// System: AMD Athlon 1800+ XP, 512 DDR, Geforce 3, Windows XP, MSVC++ 7.0 
//
// Desc: Provides utility functions for simplifying common tasks.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include "d3dUtility.h"

bool d3d::InitD3D(
	HINSTANCE hInstance,
	int width, int height,
	bool windowed,
	std::unique_ptr<CoreEngine> &device)
{
	//
	// Create the main application window.
	//
    //建立并注册窗口类
	WNDCLASS wc;

	wc.style         = 0/*CS_HREDRAW | CS_VREDRAW | MM_TEXT*/;
	wc.lpfnWndProc   = (WNDPROC)d3d::WndProc; 
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = 0;
	wc.lpszClassName = L"TESTENGINE";

	if( !RegisterClass(&wc) ) 
	{
		::MessageBox(0, L"RegisterClass() - FAILED", 0, 0);
		return false;
	}
	//创建窗口	
	HWND hwnd = 0;
	hwnd = ::CreateWindow(L"TESTENGINE", L"TESTENGINE", 
		  WS_OVERLAPPEDWINDOW ,
		0, 0, width, height,
		0 /*parent hwnd*/, 0 /* menu */, hInstance, 0 /*extra*/); 

	if( !hwnd )
	{
		::MessageBox(0, L"CreateWindow() - FAILED", 0, 0);
		return false;
	}

	::ShowWindow(hwnd, SW_SHOW);
	//Sleep(1000);
	::UpdateWindow(hwnd);

	//
	// Init D3D: 
	//


	HRESULT hr = 0;

	// Step 1: Create the IDirect3D9 object.
	hr = TNYCreateDevice(hwnd, device);
	if (FAILED(hr))
	{
		return false;
	}
	return true;
}

int d3d::EnterMsgLoop( bool (*ptr_display)(float timeDelta) )
{
	MSG msg;
	::ZeroMemory(&msg, sizeof(MSG));

	//static float lastTime = (float)timeGetTime(); 
	while(msg.message != WM_QUIT)
	{
		if(::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		else
        {	
		/*	float currTime  = (float)timeGetTime();
			float timeDelta = (currTime - lastTime)*0.001f;*/

			ptr_display(0);

			//lastTime = currTime;
        }
    }

    return msg.wParam;
}


