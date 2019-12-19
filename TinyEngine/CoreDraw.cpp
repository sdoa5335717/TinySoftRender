#include "CoreDraw.h"



CoreDraw::CoreDraw()
{
}


CoreDraw::~CoreDraw()
{
}

void CoreDraw::DrawPoint(UTILS::Vertex* pVertex, UTILS::uint* uIndex, int nPrimitiveCount, UTILS::Rgba* buffer)
{
	for (int i = 0; i < nPrimitiveCount; i++)
	{
		int x = pVertex[uIndex[i]].x;
		int y = pVertex[uIndex[i]].y;
		UTILS::Rgba c = pVertex[uIndex[i]]._color;

		buffer[y*m_nWidth + x] = c;
	}
}

void CoreDraw::DrawLine(UTILS::Vertex* pVertex, UTILS::uint* uIndex, int nPrimitiveCount, UTILS::Rgba* buffer)
{
	for (int i = 0; i < 2*nPrimitiveCount; i += 2)
	{
		Line(pVertex[uIndex[i]], pVertex[uIndex[i + 1]], buffer);
	}
}

void CoreDraw::DrawTrangle(UTILS::Vertex* pVertex, UTILS::uint* uIndex, int nPrimitiveCount, UTILS::Rgba* buffer)
{
	for (int i=0; i<nPrimitiveCount*3;i+=3)
	{
		Trangle(pVertex[uIndex[i]], pVertex[uIndex[i + 1]], pVertex[uIndex[i + 2]], buffer);
	}
}

void CoreDraw::setPixel(unsigned x, unsigned y, UTILS::Rgba color, UTILS::Rgba* buffer)
{
	if (x >= m_nWidth || y >= m_nHeigth)
	{
		return;
	}
	buffer[y * m_nWidth + x] = color;
}

void CoreDraw::Line(const UTILS::Vertex& v1, const UTILS::Vertex& v2, UTILS::Rgba* buffer)
{
	if (v1.x == v2.x && v1.y == v2.y) {
		UTILS::Rgba c = v1._color;
		buffer[v1.y*m_nWidth + v1.x] = c;
	}
	else
	{
		//CPoint point;
		float x0 = v1.x, y0 = v1.y;
		float x1 = v2.x, y1 = v2.y;
		float x, y;
		float len = MAX(fabs(x1 - x0), fabs(y1 - y0));
		float delt_x = (x1 - x0) / len;
		float delt_y = (y1 - y0) / len;

		x = x0 + 0.5;
		y = y0 + 0.5;
		int i = 1;

		UTILS::Rgba c = v1._color;

		while (i <= len) {
			UTILS::Vertex v;
			v.x = x, v.y = y;
			//pDC->SetPixelV(point, cLineColor);
			setPixel(v.x, v.y, c, buffer);
			//buffer[v.y*m_nWidth + v.x] = c._color;
			x = x + delt_x;
			y = y + delt_y;
			i++;
		}
	}
}

void CoreDraw::Trangle(const UTILS::Vertex& v1, const UTILS::Vertex& v2, 
	const UTILS::Vertex& v3, UTILS::Rgba* buffer)
{
	Line(v1, v2, buffer);
	Line(v1, v3, buffer);
	Line(v2, v3, buffer);
}
