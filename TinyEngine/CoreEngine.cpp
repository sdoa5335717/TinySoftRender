#include "CoreEngine.h"
#include <assert.h>
#include <strsafe.h>
using namespace UTILS;
namespace {
	CoreEngine* g_pEngine = nullptr;
}

CoreEngine::CoreEngine(HWND hWnd)
	:m_hWnd(hWnd)
{
	//g_pEngine = this;
	init();
}


CoreEngine::~CoreEngine()
{
}

bool CoreEngine::init()
{/*
	if (!initMainWindow(nWidth, Heigth))
	{
		return false;
	}*/
	if (!initDevice())
	{
		return false;
	}
	m_draw.SetDrawSize(m_width, m_heigth);
#ifdef _DEBUG
	//AllocConsole();
	//m_hDebug = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
	return true;
}


void CoreEngine::installCam(CAM4DV1* pCam)
{
	m_cam = pCam;
}

bool CoreEngine::initDevice()
{
	m_hDC = GetDC(m_hWnd);
	m_hMem = ::CreateCompatibleDC(m_hDC);
	if (!m_hMem)
	{
		return false;
	}
	RECT rc;
	//GetWindowRect(m_hWnd, &rc);
	GetClientRect(m_hWnd, &rc);
	m_width = rc.right - rc.left;
	m_heigth = rc.bottom - rc.top;
	// ´´½¨HDC£¬hMem
	BITMAPINFO	bmpInfor;
	bmpInfor.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmpInfor.bmiHeader.biWidth = m_width;
	bmpInfor.bmiHeader.biHeight = -m_heigth;
	bmpInfor.bmiHeader.biPlanes = 1;
	bmpInfor.bmiHeader.biBitCount = 32;
	bmpInfor.bmiHeader.biCompression = BI_RGB;
	bmpInfor.bmiHeader.biSizeImage = 0;
	bmpInfor.bmiHeader.biXPelsPerMeter = 0;
	bmpInfor.bmiHeader.biYPelsPerMeter = 0;
	bmpInfor.bmiHeader.biClrUsed = 0;
	bmpInfor.bmiHeader.biClrImportant = 0;

	HBITMAP	hBmp = CreateDIBSection(m_hDC, &bmpInfor, DIB_RGB_COLORS, (void**)&m_buffer, 0, 0);
	SelectObject(m_hMem, hBmp);
	
	return true;
}

//LRESULT CoreEngine::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//		// WM_ACTIVATE is sent when the window is activated or deactivated.  
//		// We pause the game when the window is deactivated and unpause it 
//		// when it becomes active.  
//	case WM_ACTIVATE:
//		/*	if (LOWORD(wParam) == WA_INACTIVE)
//			{
//				m_AppPaused = true;
//				m_Timer.Stop();
//			}
//			else
//			{
//				m_AppPaused = false;
//				m_Timer.Start();
//			}*/
//		return 0;
//
//		// WM_SIZE is sent when the user resizes the window.  
//	case WM_SIZE:
//		// Save the new client area dimensions.
//		//m_ClientWidth = LOWORD(lParam);
//		//m_ClientHeight = HIWORD(lParam);
//		//if (m_pd3dDevice)
//		//{
//		//	if (wParam == SIZE_MINIMIZED)
//		//	{
//		//		m_AppPaused = true;
//		//		m_Minimized = true;
//		//		m_Maximized = false;
//		//	}
//		//	else if (wParam == SIZE_MAXIMIZED)
//		//	{
//		//		m_AppPaused = false;
//		//		m_Minimized = false;
//		//		m_Maximized = true;
//		//		OnResize();
//		//	}
//		//	else if (wParam == SIZE_RESTORED)
//		//	{
//
//		//		// Restoring from minimized state?
//		//		if (m_Minimized)
//		//		{
//		//			m_AppPaused = false;
//		//			m_Minimized = false;
//		//			OnResize();
//		//		}
//
//		//		// Restoring from maximized state?
//		//		else if (m_Maximized)
//		//		{
//		//			m_AppPaused = false;
//		//			m_Maximized = false;
//		//			OnResize();
//		//		}
//		//		else if (m_Resizing)
//		//		{
//		//			// If user is dragging the resize bars, we do not resize 
//		//			// the buffers here because as the user continuously 
//		//			// drags the resize bars, a stream of WM_SIZE messages are
//		//			// sent to the window, and it would be pointless (and slow)
//		//			// to resize for each WM_SIZE message received from dragging
//		//			// the resize bars.  So instead, we reset after the user is 
//		//			// done resizing the window and releases the resize bars, which 
//		//			// sends a WM_EXITSIZEMOVE message.
//		//		}
//		//		else // API call such as SetWindowPos or m_pSwapChain->SetFullscreenState.
//		//		{
//		//			OnResize();
//		//		}
//		//	}
//		//}
//		return 0;
//
//		// WM_EXITSIZEMOVE is sent when the user grabs the resize bars.
//	case WM_ENTERSIZEMOVE:
//		/*m_AppPaused = true;
//		m_Resizing = true;
//		m_Timer.Stop();*/
//		return 0;
//
//		// WM_EXITSIZEMOVE is sent when the user releases the resize bars.
//		// Here we reset everything based on the new window dimensions.
//	case WM_EXITSIZEMOVE:
//		/*m_AppPaused = false;
//		m_Resizing = false;
//		m_Timer.Start();*/
//		//OnResize();
//		return 0;
//
//		// WM_DESTROY is sent when the window is being destroyed.
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//
//		// The WM_MENUCHAR message is sent when a menu is active and the user presses 
//		// a key that does not correspond to any mnemonic or accelerator key. 
//	case WM_MENUCHAR:
//		// Don't beep when we alt-enter.
//		return MAKELRESULT(0, MNC_CLOSE);
//
//		// Catch this message so to prevent the window from becoming too small.
//	case WM_GETMINMAXINFO:
//		((MINMAXINFO*)lParam)->ptMinTrackSize.x = 200;
//		((MINMAXINFO*)lParam)->ptMinTrackSize.y = 200;
//		return 0;
//
//	case WM_LBUTTONDOWN:
//	case WM_MBUTTONDOWN:
//	case WM_RBUTTONDOWN:
//		return 0;
//	case WM_LBUTTONUP:
//	case WM_MBUTTONUP:
//	case WM_RBUTTONUP:
//		return 0;
//	case WM_MOUSEMOVE:
//		return 0;
//	}
//
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}

//int CoreEngine::run()
//{
//	MSG msg = { 0 };
//
//	//m_Timer.Reset();
//
//	while (msg.message != WM_QUIT)
//	{
//		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//		else
//		{
//			/*m_Timer.Tick();*/
//
//			if (!m_AppPaused)
//			{
//				//CalculateFrameStats();
//				//UpdateScene(m_Timer.DeltaTime());
//				DrawScene();
//			}
//			else
//			{
//				Sleep(100);
//			}
//		}
//	}
//
//	return (int)msg.wParam;
//}

void CoreEngine::Clear(UTILS::Rgba clearcolor)
{
	//std::fill_n(m_buffer, m_width*m_heigth, clearcolor);
	memset(m_buffer, 0x00, sizeof(UTILS::uint)*m_width*m_heigth);
}

void CoreEngine::present()
{
	BitBlt(m_hDC, 0, 0, m_width, m_heigth, m_hMem, 0, 0, SRCCOPY);
}

void CoreEngine::DrawPrimitiveIndex(UTILS::Vertex* vertex, UTILS::uint* uIndex, 
	int type, int nPrimitiveCount)
{
	TNY_USEPRINTF();

	if (!vertex || !uIndex) {
#ifdef _DEBUG
		TNY_PRINTF(L"invalid paramter\n");
#endif
		return;
	}
	switch (type)
	{
	case TNY_POINT:
		m_draw.DrawPoint(vertex, uIndex, nPrimitiveCount, m_buffer);
		break;
	case TNY_LINELIST:
		m_draw.DrawLine(vertex, uIndex, nPrimitiveCount, m_buffer);
		break;
	case TNY_TRANGLELIST:
		m_draw.DrawTrangle(vertex, uIndex, nPrimitiveCount, m_buffer);
		break;
	default:
		break;
	}

}

void CoreEngine::DrawPrimitive(TNYMATH::OBJECT4DV1* pObj, int type)
{

	if (!pObj) {

		return;
	}
	switch (type)
	{
	case TNY_POINT:
		m_draw.DrawPoint(pObj->vlist_screen, pObj->vlist_index, pObj->num_polys, m_buffer);
		break;
	case TNY_LINELIST:
		m_draw.DrawLine(pObj->vlist_screen, pObj->vlist_index, pObj->num_polys, m_buffer);
		break;
	case TNY_TRANGLELIST:
		m_draw.DrawTrangle(pObj->vlist_screen, pObj->vlist_index, pObj->num_polys, m_buffer);
		break;
	default:
		break;
	}
}
