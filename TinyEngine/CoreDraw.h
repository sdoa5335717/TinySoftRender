#pragma once
#include "utils.h"
#include <math.h>
#include <stdlib.h>
class CoreDraw
{
public:
	CoreDraw();
	~CoreDraw();

	void SetDrawSize(int w, int h) {
		m_nWidth = w;
		m_nHeigth = h;
	}
	void DrawPoint(UTILS::Vertex* pVertex, 
		UTILS::uint* uIndex, int nPrimitiveCount, UTILS::Rgba* buffer);

	void DrawLine(UTILS::Vertex* pVertex,
		UTILS::uint* uIndex, int nPrimitiveCount, UTILS::Rgba* buffer);

	void DrawTrangle(UTILS::Vertex* pVertex,
		UTILS::uint* uIndex, int nPrimitiveCount, UTILS::Rgba* buffer);

	void Trangle(const UTILS::Vertex& v1, const UTILS::Vertex& v2, const UTILS::Vertex& v3, UTILS::Rgba* buffer);
private:
	void setPixel(unsigned x, unsigned y, UTILS::Rgba color, UTILS::Rgba* buffer);
	void Line(const UTILS::Vertex& v1, const UTILS::Vertex& v2, UTILS::Rgba* buffer);
	//void Trangle(const UTILS::Vertex& v1, const UTILS::Vertex& v2, const UTILS::Vertex& v3, UTILS::Rgba* buffer);
private:
	int m_nWidth;
	int m_nHeigth;
};

