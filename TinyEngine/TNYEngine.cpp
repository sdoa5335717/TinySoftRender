#include "TNYEngine.h"

HRESULT TNYCreateDevice(HWND hwnd, /* windows associated with device */ std::unique_ptr<CoreEngine> &device)
{
	device = std::unique_ptr<CoreEngine>(new CoreEngine(hwnd));  //new CoreEngine(hwnd);
	if (device) {
		return S_OK;
	}
	return E_FAIL;
}

HRESULT TNYCreateScene(HWND hwnd, std::unique_ptr<TNYScene> &scene)
{
	scene = std::unique_ptr<TNYScene>(new TNYScene(hwnd));
	if (scene) {
		return S_OK;
	}
	return E_FAIL;
}

void ReleaseScene(TNYScene* &scene)
{
	if (scene)
	{
		delete scene;
		scene = nullptr;
	}
}

void ReleaseDevice(CoreEngine*& device)
{
	if (device)
	{
		delete device;
		device = nullptr;
	}
}

