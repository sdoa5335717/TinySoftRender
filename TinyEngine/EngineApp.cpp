#include "EngineApp.h"
#include "utils.h"
#include <vector>
using namespace UTILS;
using namespace std;
EngineApp::EngineApp(HINSTANCE hins)
	:CoreEngine(hins)
{
}


EngineApp::~EngineApp()
{
}

void EngineApp::DrawScene()
{
	CoreEngine::Clear(0xff000000);
	vector<Vertex> vec;
	vector<uint> vi;
	// test draw point;
	// test draw line
	// draw a circle
	/*int r = 200;
	Vertex c;
	c.x = 400, c.y = 300;
	Vertex v[100] = {};
	uint vi[100] = {};

	for (int i=0; i< 360;i+=10)
	{
		Vertex v;
		v.x = c.x + r * cos(i* TNY_PI / 180.0f);
		v.y = c.y - r * sin(i* TNY_PI / 180.0f);
		v._color = 0xffffffff;
		vec.push_back(v);
	}

	int nCount = 0;
	for (int i=0;i< (vec.size()-1)*2;i+=2)
	{
		vi[i] = nCount;
		vi[i + 1] = nCount + 1;

		nCount++;
	}*/
	////////////////////
	//test trangle list
	Vertex v;
	v.x = 100, v.y = 200, v._color = 0xffff0000;
	vec.push_back(v);
	v.x = 200, v.y = 200, v._color = 0xffff0000;
	vec.push_back(v);
	v.x = 100, v.y = 400, v._color = 0xffff0000;
	vec.push_back(v);
	v.x = 200, v.y = 400, v._color = 0xffff0000;
	vec.push_back(v);

	vi.push_back(0);
	vi.push_back(1);
	vi.push_back(3);

	vi.push_back(0);
	vi.push_back(2);
	vi.push_back(3);

	DrawPrimitiveIndex(vec.data(), vi.data(), TNY_TRANGLELIST, 2);
	//m_draw.DrawPoint(v, vi, 100, GetBuffer());
	CoreEngine::present();
}
