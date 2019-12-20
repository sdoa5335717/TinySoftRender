#pragma once

#define TNY_USEPRINTF() TCHAR pOutBufA[1024] = {};

#define TNY_PRINTF(...) \
	StringCchPrintf(pOutBufA,1024,__VA_ARGS__);\
	OutputDebugString(pOutBufA);

#define TNY_POINT 0x00
#define TNY_LINELIST 0x01
#define TNY_TRANGLELIST 0x02

#define TNY_PI       3.14159265358979323846   // pi
#define MAX(a,b)                ((a) > (b) ? (a) : (b))

#define TNY_WORLD 1
#define TNY_PROJ 2
// ∂®“Â—’…´
namespace UTILS
{
	typedef unsigned char           byte;
	typedef long long               int64;
	typedef unsigned short          ushort;
	typedef unsigned int            uint;
	typedef unsigned long           ulong;

	class   Rgba4Byte
	{
	public:
		Rgba4Byte(
			unsigned char r = 255,
			unsigned char g = 255,
			unsigned char b = 255,
			unsigned char a = 255
		)
		{
			_r = r;
			_g = g;
			_b = b;
			_a = a;
		}
		Rgba4Byte(uint rgba)
		{
			_color = rgba;
		}
		friend  bool    operator == (const Rgba4Byte& left, const Rgba4Byte& right)
		{
			return  left._r == right._r &&
				left._g == right._g &&
				left._b == right._b &&
				left._a == right._a;
		}
		friend  bool    operator != (const Rgba4Byte& left, const Rgba4Byte& right)
		{
			return  left._r != right._r ||
				left._g != right._g ||
				left._b != right._b ||
				left._a != right._a;
		}
		//operator unsigned()
		//{
		//	unsigned    color;
		//	char*       pColor = (char*)&color;
		//	pColor[0] = _r;
		//	pColor[1] = _g;
		//	pColor[2] = _b;
		//	pColor[3] = _a;
		//	return  color;
		//}
		//operator int()
		//{
		//	int         color;
		//	char*       pColor = (char*)&color;
		//	pColor[0] = _r;
		//	pColor[1] = _g;
		//	pColor[2] = _b;
		//	pColor[3] = _a;
		//	return  color;
		//}
		operator unsigned()
		{
			return  _color;
		}
		operator ulong()
		{
			return  toUint();
		}
		uint toUint()
		{
			return  _color;
		}
	public:
		union
		{
			struct
			{

				unsigned char   _b;
				unsigned char   _g;
				unsigned char   _r;
				unsigned char   _a;
			};
			uint    _color;
		};
	};

	using Rgba = Rgba4Byte;

	///////////////vertex///////////
	class Vertex {

	public:
		Vertex() {};
		Vertex(const int _x, const int _y, unsigned int color)
		:x(_x),y(_y),_color(color)
		{

		}
		unsigned int x = 0;
		unsigned int y = 0;

		Rgba _color;
	};
}
