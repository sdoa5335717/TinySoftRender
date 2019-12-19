#pragma once
#include "CoreEngine.h"
class EngineApp : public CoreEngine
{
public:
	EngineApp(HINSTANCE hIns);
	~EngineApp();

	bool init(int width, int heigth)
	{
		return CoreEngine::init(width, heigth);
	}

	virtual void UpdateScene(float dt)
	{

	}
	virtual void DrawScene();


};

