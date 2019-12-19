#pragma once
#include <windows.h>
#include "CoreEngine.h"
#include "TNYScene.h"
HRESULT TNYCreateDevice(
	HWND hwnd, // windows associated with device
	std::unique_ptr<CoreEngine> &device
);

HRESULT TNYCreateScene(HWND hwnd, std::unique_ptr<TNYScene> &device);

void ReleaseScene(TNYScene* &scene);
void ReleaseDevice(CoreEngine*& device);
