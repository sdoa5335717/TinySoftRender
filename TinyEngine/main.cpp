#include "EngineApp.h"
#include <crtdbg.h>
int WINAPI WinMain(_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// ��Щ������ʹ��
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nShowCmd);
	// ������Debug�汾��������ʱ�ڴ�����й©���
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	EngineApp app(hInstance);
	
	if (!app.init(800, 600))
	{
		return 0;
	}

	return app.run();
}