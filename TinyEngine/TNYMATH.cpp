#include "TNYMATH.h"
using namespace TNYMATH;
void TNYMATH::VECTOR2D_ZERO(VECTOR2D_PTR v)
{
	v->x = v->y = 0.0;
}

void TNYMATH::VECTOR3D_ZERO(VECTOR3D_PTR v)
{
	v->x = v->y = v->z = 0.0;
}

void TNYMATH::VECTOR4D_ZERO(VECTOR4D_PTR v)
{
	v->x = v->y = v->z = 0.0; v->w = 1.0;
}

void TNYMATH::VECTOR2D_INITXY(VECTOR2D_PTR v, float x, float y)
{
	v->x = x; v->y = y;
}

void TNYMATH::VECTOR3D_INITXYZ(VECTOR3D_PTR v, float x, float y, float z)
{
	v->x = x; v->y = y; v->z = z;
}

void TNYMATH::VECTOR4D_INITXYZ(VECTOR4D_PTR v, float x, float y, float z)
{
	v->x = x; v->y = y; v->z = z; v->w = 1.0;
}

void TNYMATH::VECTOR2D_INIT(VECTOR2D_PTR vdst, VECTOR2D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y;
}

void TNYMATH::VECTOR3D_INIT(VECTOR3D_PTR vdst, VECTOR3D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y; vdst->z = vsrc->z;
}

void TNYMATH::VECTOR4D_INIT(VECTOR4D_PTR vdst, VECTOR4D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y;
	vdst->z = vsrc->z; vdst->w = vsrc->w;
}

void TNYMATH::VECTOR2D_COPY(VECTOR2D_PTR vdst, VECTOR2D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y;
}

void TNYMATH::VECTOR3D_COPY(VECTOR3D_PTR vdst, VECTOR3D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y; vdst->z = vsrc->z;
}

void TNYMATH::VECTOR4D_COPY(VECTOR4D_PTR vdst, VECTOR4D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y;
	vdst->z = vsrc->z; vdst->w = vsrc->w;
}

void TNYMATH::POINT2D_INIT(POINT2D_PTR vdst, POINT2D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y;
}

void TNYMATH::POINT3D_INIT(POINT3D_PTR vdst, POINT3D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y; vdst->z = vsrc->z;
}

void TNYMATH::POINT4D_INIT(POINT4D_PTR vdst, POINT4D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y;
	vdst->z = vsrc->z; vdst->w = vsrc->w;
}

void TNYMATH::POINT2D_COPY(POINT2D_PTR vdst, POINT2D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y;
}

void TNYMATH::POINT3D_COPY(POINT3D_PTR vdst, POINT3D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y; vdst->z = vsrc->z;
}

void TNYMATH::POINT4D_COPY(POINT4D_PTR vdst, POINT4D_PTR vsrc)
{
	vdst->x = vsrc->x; vdst->y = vsrc->y;
	vdst->z = vsrc->z; vdst->w = vsrc->w;
}

void TNYMATH::MAT_TRANSPOSE_3X3(MATRIX3X3_PTR m)
{
	MATRIX3X3 mt;
	mt.M00 = m->M00; mt.M01 = m->M10; mt.M02 = m->M20;
	mt.M10 = m->M01; mt.M11 = m->M11; mt.M12 = m->M21;
	mt.M20 = m->M02; mt.M21 = m->M12; mt.M22 = m->M22;
	MAT_COPY_3X3(m, &mt);
}

void TNYMATH::MAT_TRANSPOSE_3X3(MATRIX3X3_PTR m, MATRIX3X3_PTR mt)
{
	mt->M00 = m->M00; mt->M01 = m->M10; mt->M02 = m->M20;
	mt->M10 = m->M01; mt->M11 = m->M11; mt->M12 = m->M21;
	mt->M20 = m->M02; mt->M21 = m->M12; mt->M22 = m->M22;
}

void TNYMATH::MAT_TRANSPOSE_4X4(MATRIX4X4_PTR m)
{
	MATRIX4X4 mt;
	mt.M00 = m->M00; mt.M01 = m->M10; mt.M02 = m->M20; mt.M03 = m->M30;
	mt.M10 = m->M01; mt.M11 = m->M11; mt.M12 = m->M21; mt.M13 = m->M31;
	mt.M20 = m->M02; mt.M21 = m->M12; mt.M22 = m->M22; mt.M23 = m->M32;
	mt.M30 = m->M03; mt.M31 = m->M13; mt.M32 = m->M23; mt.M33 = m->M33;
	MAT_COPY_4X4(m, &mt);
}

void TNYMATH::MAT_TRANSPOSE_4X4(MATRIX4X4_PTR m, MATRIX4X4_PTR mt)
{
	mt->M00 = m->M00; mt->M01 = m->M10; mt->M02 = m->M20; mt->M03 = m->M30;
	mt->M10 = m->M01; mt->M11 = m->M11; mt->M12 = m->M21; mt->M13 = m->M31;
	mt->M20 = m->M02; mt->M21 = m->M12; mt->M22 = m->M22; mt->M23 = m->M32;
	mt->M30 = m->M03; mt->M31 = m->M13; mt->M32 = m->M23; mt->M33 = m->M33;
}

void TNYMATH::MAT_COLUMN_SWAP_2X2(MATRIX2X2_PTR m, int c, MATRIX1X2_PTR v)
{
	m->M[0][c] = v->M[0]; m->M[1][c] = v->M[1];
}

void TNYMATH::MAT_COLUMN_SWAP_3X3(MATRIX3X3_PTR m, int c, MATRIX1X3_PTR v)
{
	m->M[0][c] = v->M[0]; m->M[1][c] = v->M[1]; m->M[2][c] = v->M[2];
}

void TNYMATH::MAT_COLUMN_SWAP_4X4(MATRIX4X4_PTR m, int c, MATRIX1X4_PTR v)
{
	m->M[0][c] = v->M[0]; m->M[1][c] = v->M[1];
	m->M[2][c] = v->M[2]; m->M[3][c] = v->M[3];
}

void TNYMATH::MAT_COLUMN_SWAP_4X3(MATRIX4X3_PTR m, int c, MATRIX1X4_PTR v)
{
	m->M[0][c] = v->M[0]; m->M[1][c] = v->M[1];
	m->M[2][c] = v->M[2]; m->M[3][c] = v->M[3];
}

void TNYMATH::QUAT_ZERO(QUAT_PTR q)
{
	q->x = q->y = q->z = q->w = 0.0;
}

void TNYMATH::QUAT_INITWXYZ(QUAT_PTR q, float w, float x, float y, float z)
{
	q->w = w; q->x = x; q->y = y; q->z = z;
}

void TNYMATH::QUAT_INIT_VECTOR3D(QUAT_PTR q, VECTOR3D_PTR v)
{
	q->w = 0; q->x = v->x; q->y = v->y; q->z = v->z;
}

void TNYMATH::QUAT_INIT(QUAT_PTR qdst, QUAT_PTR qsrc)
{
	qdst->w = qsrc->w; qdst->x = qsrc->x;
	qdst->y = qsrc->y; qdst->z = qsrc->z;
}

void TNYMATH::QUAT_COPY(QUAT_PTR qdst, QUAT_PTR qsrc)
{
	qdst->w = qsrc->w; qdst->x = qsrc->x;
	qdst->y = qsrc->y; qdst->z = qsrc->z;
}

float TNYMATH::Fast_Sin(float theta)
{
	return sin(theta);
	//theta = fmodf(theta, 360);
	//if (theta < 0) theta += 360.0;
	//int theta_int = (int)theta;
	//float theta_frac = theta - theta_int;
	//return (sin_look[theta_int] + theta_frac * (sin_look[theta_int + 1] - sin_look[theta_int]));
}

float TNYMATH::Fast_Cos(float theta)
{
	return cos(theta);
	//// convert angle to 0-359
	//theta = fmodf(theta, 360);

	//// make angle positive
	//if (theta < 0) theta += 360.0;

	//// compute floor of theta and fractional part to interpolate
	//int theta_int = (int)theta;
	//float theta_frac = theta - theta_int;

	//// now compute the value of sin(angle) using the lookup tables
	//// and interpolating the fractional part, note that if theta_int
	//// is equal to 359 then theta_int+1=360, but this is fine since the
	//// table was made with the entries 0-360 inclusive
	//return(cos_look[theta_int] +
	//	theta_frac * (cos_look[theta_int + 1] - cos_look[theta_int]));
}

int TNYMATH::Fast_Distance_2D(int x, int y)
{
	x = abs(x);
	y = abs(y);

	// compute the minimum of x,y
	int mn = MIN(x, y);

	// return the distance
	return(x + y - (mn >> 1) - (mn >> 2) + (mn >> 4));
}

float TNYMATH::Fast_Distance_3D(float fx, float fy, float fz)
{
	int temp;  // used for swaping
	int x, y, z; // used for algorithm

	// make sure values are all positive
	x = fabs(fx) * 1024;
	y = fabs(fy) * 1024;
	z = fabs(fz) * 1024;

	// sort values
	if (y < x) SWAP(x, y, temp)

		if (z < y) SWAP(y, z, temp)

			if (y < x) SWAP(x, y, temp)

				int dist = (z + 11 * (y >> 5) + (x >> 2));

	// compute distance with 8% error
	return((float)(dist >> 10));
}

void TNYMATH::POLAR2D_To_POINT2D(POLAR2D_PTR polar, POINT2D_PTR rect)
{
	// 将极坐标r和theta转为一个点
	// convert polar to rectangular
	rect->x = polar->r*cosf(polar->theta);
	rect->y = polar->r*sinf(polar->theta);
}

void TNYMATH::POLAR2D_To_RectXY(POLAR2D_PTR polar, float* x, float* y)
{
	// 将极坐标r和theta转为xy坐标
	// convert polar to rectangular
	*x = polar->r*cosf(polar->theta);
	*y = polar->r*sinf(polar->theta);
}

void TNYMATH::POINT2D_To_POLAR2D(POINT2D_PTR rect, POLAR2D_PTR polar)
{
	// 将直角坐标点转为极坐标点
	polar->r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
	polar->theta = atanf(rect->y / rect->x);
}

void TNYMATH::POINT2D_To_PolarRTh(POINT2D_PTR rect, float *r, float* theta)
{
	// 将要给2D极坐标转换为r和theta
	// convert rectangular to polar
	*r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
	*theta = atanf(rect->y / rect->x);
}

void TNYMATH::CYLINDRICAL3D_To_POINT3D(CYLINDRICAL3D_PTR cyl, POINT3D_PTR rect)
{
	// 将一个3D柱面坐标点转为3D直角坐标点
	// convert cylindrical to rectangular
	rect->x = cyl->r*cosf(cyl->theta);
	rect->y = cyl->r*sinf(cyl->theta);
	rect->z = cyl->z;
}

void TNYMATH::CYLINDRICAL3D_To_RectXYZ(CYLINDRICAL3D_PTR cyl, float* x, float* y, float* z)
{
	// 将一个3D柱面坐标点转为xyz坐标
	*x = cyl->r*cosf(cyl->theta);
	*y = cyl->r*sinf(cyl->theta);
	*z = cyl->z;
}

void TNYMATH::POINT3D_To_CYLINDRICAL3D(POINT3D_PTR rect, CYLINDRICAL3D_PTR cyl)
{
	// 直角坐标点转柱面坐标点
	cyl->r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
	cyl->theta = atanf(rect->y / rect->x);
	cyl->z = rect->z;
}

void TNYMATH::POINT3D_To_CylindricalRThZ(POINT3D_PTR rect, float* r, float* theta, float* z)
{
	// 将3D点转换为柱面坐标r，theta,z
	// convert rectangular to cylindrical
	*r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
	*theta = atanf(rect->y / rect->x);
	*z = rect->z;
}

void TNYMATH::SPHERICAL3D_To_POINT3D(SPHERICAL3D_PTR sph, POINT3D_PTR rect)
{
	// 球面坐标点转直角坐标点
	float r;

	// pre-compute r, and z
	r = sph->p*sinf(sph->phi);
	rect->z = sph->p*cosf(sph->phi);

	// use r to simplify computation of x,y
	rect->x = r * cosf(sph->theta);
	rect->y = r * sinf(sph->theta);
}

void TNYMATH::SPHERICAL3D_To_RectXYZ(SPHERICAL3D_PTR sph, float* x, float* y, float* z)
{
	// 球面坐标点转xyz
	float r;

	// pre-compute r, and z
	r = sph->p*sinf(sph->phi);
	*z = sph->p*cosf(sph->phi);

	// use r to simplify computation of x,y
	*x = r * cosf(sph->theta);
	*y = r * sinf(sph->theta);
}

void TNYMATH::POINT3D_To_SPHERICAL3D(POINT3D_PTR rect, SPHERICAL3D_PTR sph)
{
	// 直角坐标点转球面坐标
	// convert rectangular to spherical
	sph->p = sqrtf((rect->x*rect->x) + (rect->y*rect->y) + (rect->z*rect->z));
	sph->theta = atanf(rect->y / rect->x);
	// we need r to compute phi
	float r = sph->p*sinf(sph->phi);
	sph->phi = asinf(r / sph->p);
}

void TNYMATH::POINT3D_To_ShpericalPThPh(POINT3D_PTR rect, float* p, float* theta, float* phi)
{
	// 直角坐标转球面坐标r theta phi;
	*p = sqrtf((rect->x*rect->x) + (rect->y*rect->y) + (rect->z*rect->z));
	*theta = atanf(rect->y / rect->x);

	// we need r to compute phi
	float r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
	*phi = asinf(r / (*p));
}

void TNYMATH::VECTOR2D_Add(VECTOR2D_PTR va, VECTOR2D_PTR vb, VECTOR2D_PTR vsum)
{
	// this function adds va+vb and return it in vsum
	vsum->x = va->x + vb->x;
	vsum->y = va->y + vb->y;
}

TNYMATH::VECTOR2D TNYMATH::VECTOR2D_Add(VECTOR2D_PTR va, VECTOR2D_PTR vb)
{
	VECTOR2D vsum;

	vsum.x = va->x + vb->x;
	vsum.y = va->y + vb->y;

	// return result
	return(vsum);
}

void TNYMATH::VECTOR2D_Sub(VECTOR2D_PTR va, VECTOR2D_PTR vb, VECTOR2D_PTR vdiff)
{
	// this function subtracts va-vb and return it in vdiff
// the stack
	vdiff->x = va->x - vb->x;
	vdiff->y = va->y - vb->y;
}

VECTOR2D TNYMATH::VECTOR2D_Sub(VECTOR2D_PTR va, VECTOR2D_PTR vb)
{
	VECTOR2D vdiff;

	vdiff.x = va->x - vb->x;
	vdiff.y = va->y - vb->y;

	// return result
	return(vdiff);
}

void TNYMATH::VECTOR2D_Scale(float k, VECTOR2D_PTR va)
{
	va->x *= k;
	va->y *= k;
}

void TNYMATH::VECTOR2D_Scale(float k, VECTOR2D_PTR va, VECTOR2D_PTR vscaled)
{
	// multiply each component by scaling factor
	vscaled->x = k * va->x;
	vscaled->y = k * va->y;
}

float TNYMATH::VECTOR2D_Dot(VECTOR2D_PTR va, VECTOR2D_PTR vb)
{
	return ((va->x * vb->x) + (va->y * vb->y));
}

float TNYMATH::VECTOR2D_Length(VECTOR2D_PTR va)
{
	return(sqrtf(va->x*va->x + va->y*va->y));
}

float TNYMATH::VECTOR_Length_Fast(VECTOR2D_PTR va)
{
	return ((float)Fast_Distance_2D(va->x, va->y));
}

void TNYMATH::VECTOR2D_Normalize(VECTOR2D_PTR va)
{
	// compute length
	float length = sqrtf(va->x*va->x + va->y*va->y);

	// test for zero length vector
	// if found return zero vector
	if (length < EPSILON_E5)
		return;

	float length_inv = 1 / length;

	// compute normalized version of vector
	va->x = va->x*length_inv;
	va->y = va->y*length_inv;
}

void TNYMATH::VECTOR2D_Normalize(VECTOR2D_PTR va, VECTOR2D_PTR vn)
{
	VECTOR2D_ZERO(vn);
	// compute length
	float length = (float)sqrtf(va->x*va->x + va->y*va->y);
	// test for zero length vector
	// if found return zero vector
	if (length < EPSILON_E5)
		return;

	float length_inv = 1 / length;

	// compute normalized version of vector
	vn->x = va->x*length_inv;
	vn->y = va->y*length_inv;
}

void TNYMATH::VECTOR2D_Build(VECTOR2D_PTR init, VECTOR2D_PTR term, VECTOR2D_PTR result)
{
	result->x = term->x - init->x;
	result->y = term->y - init->y;
}

float TNYMATH::VECTOR2D_CosTh(VECTOR2D_PTR va, VECTOR2D_PTR vb)
{
	// Va Vb的夹角余弦
	// this function returns the cosine of the angle between
// two vectors. Note, we could compute the actual angle,
// many many times, in further calcs we will want ultimately
// compute cos of the angle, so why not just leave it!
	return(VECTOR2D_Dot(va, vb) / (VECTOR2D_Length(va)*VECTOR2D_Length(vb)));
}

void TNYMATH::VECTOR2D_Print(VECTOR2D_PTR va, char* name)
{

}

void TNYMATH::VECTOR3D_Add(VECTOR3D_PTR va, VECTOR3D_PTR vb, VECTOR3D_PTR vsum)
{
	// this function adds va+vb and return it in vsum
	vsum->x = va->x + vb->x;
	vsum->y = va->y + vb->y;
	vsum->z = va->z + vb->z;
}

VECTOR3D TNYMATH::VECTOR3D_Add(VECTOR3D_PTR va, VECTOR3D_PTR vb)
{
	VECTOR3D vsum;

	vsum.x = va->x + vb->x;
	vsum.y = va->y + vb->y;
	vsum.z = va->z + vb->z;

	// return result
	return(vsum);
}

void TNYMATH::VECTOR3D_Sub(VECTOR3D_PTR va, VECTOR3D_PTR vb, VECTOR3D_PTR vdiff)
{
	vdiff->x = va->x - vb->x;
	vdiff->y = va->y - vb->y;
	vdiff->z = va->z - vb->z;
}

VECTOR3D TNYMATH::VECTOR3D_Sub(VECTOR3D_PTR va, VECTOR3D_PTR vb)
{
	VECTOR3D vdiff;

	vdiff.x = va->x - vb->x;
	vdiff.y = va->y - vb->y;
	vdiff.z = va->z - vb->z;

	// return result
	return(vdiff);
}

void TNYMATH::VECTOR3D_Scale(float k, VECTOR3D_PTR va)
{
	va->x *= k;
	va->y *= k;
	va->z *= k;
}

void TNYMATH::VECTOR3D_Scale(float k, VECTOR3D_PTR va, VECTOR3D_PTR vscaled)
{
	vscaled->x = k * va->x;
	vscaled->y = k * va->y;
	vscaled->z = k * va->z;
}

float TNYMATH::VECTOR3D_Dot(VECTOR3D_PTR va, VECTOR3D_PTR vb)
{
	return((va->x * vb->x) + (va->y * vb->y) + (va->z * vb->z));
}

void TNYMATH::VECTOR3D_Cross(VECTOR3D_PTR va, VECTOR3D_PTR vb, VECTOR3D_PTR vn)
{
	vn->x = ((va->y * vb->z) - (va->z * vb->y));
	vn->y = -((va->x * vb->z) - (va->z * vb->x));
	vn->z = ((va->x * vb->y) - (va->y * vb->x));
}

VECTOR3D TNYMATH::VECTOR3D_Cross(VECTOR3D_PTR va, VECTOR3D_PTR vb)
{
	VECTOR3D vn;

	vn.x = ((va->y * vb->z) - (va->z * vb->y));
	vn.y = -((va->x * vb->z) - (va->z * vb->x));
	vn.z = ((va->x * vb->y) - (va->y * vb->x));

	// return result
	return(vn);
}

float TNYMATH::VECTOR3D_Length(VECTOR3D_PTR va)
{
	// computes the magnitude of a vector, slow

	return((float)sqrtf(va->x*va->x + va->y*va->y + va->z*va->z));
}

float TNYMATH::VECTOR3D_Length_Fast(VECTOR3D_PTR va)
{
	// very fast
	return(Fast_Distance_3D(va->x, va->y, va->z));
}

void TNYMATH::VECTOR3D_Normalize(VECTOR3D_PTR va)
{
	// normalizes the sent vector in placew

// compute length
	float length = sqrtf(va->x*va->x + va->y*va->y + va->z*va->z);

	// test for zero length vector
	// if found return zero vector
	if (length < EPSILON_E5)
		return;

	float length_inv = 1 / length;

	// compute normalized version of vector
	va->x *= length_inv;
	va->y *= length_inv;
	va->z *= length_inv;
}

void TNYMATH::VECTOR3D_Normalize(VECTOR3D_PTR va, VECTOR3D_PTR vn)
{
	VECTOR3D_ZERO(vn);

	// compute length
	float length = VECTOR3D_Length(va);

	// test for zero length vector
	// if found return zero vector
	if (length < EPSILON_E5)
		return;

	float length_inv = 1.0 / length;

	// compute normalized version of vector
	vn->x = va->x*length_inv;
	vn->y = va->y*length_inv;
	vn->z = va->z*length_inv;
}

void TNYMATH::VECTOR3D_Build(VECTOR3D_PTR init, VECTOR3D_PTR term, VECTOR3D_PTR result)
{
	result->x = term->x - init->x;
	result->y = term->y - init->y;
	result->z = term->z - init->z;
}

float TNYMATH::VECTOR3D_CosTh(VECTOR3D_PTR va, VECTOR3D_PTR vb)
{
	return (VECTOR3D_Dot(va, vb) / (VECTOR3D_Length(va)*VECTOR3D_Length(vb)));
}

void TNYMATH::VECTOR3D_Print(VECTOR3D_PTR va, char* name)
{

}

void TNYMATH::VECTOR4D_Add(VECTOR4D_PTR va, VECTOR4D_PTR vb, VECTOR4D_PTR vsum)
{
	// build a 4d vector
	vsum->x = va->x + vb->x;
	vsum->y = va->y + vb->y;
	vsum->z = va->z + vb->z;
	vsum->w = 1;
}

VECTOR4D TNYMATH::VECTOR4D_Add(VECTOR4D_PTR va, VECTOR4D_PTR vb)
{
	VECTOR4D vsum;

	vsum.x = va->x + vb->x;
	vsum.y = va->y + vb->y;
	vsum.z = va->z + vb->z;
	vsum.w = 1;

	// return result
	return(vsum);
}

void TNYMATH::VECTOR4D_Sub(VECTOR4D_PTR va, VECTOR4D_PTR vb, VECTOR4D_PTR vdiff)
{
	// this function subtracts va-vb and return it in vdiff
	// the stack
	vdiff->x = va->x - vb->x;
	vdiff->y = va->y - vb->y;
	vdiff->z = va->z - vb->z;
	vdiff->w = 1;
}

VECTOR4D TNYMATH::VECTOR4D_Sub(VECTOR4D_PTR va, VECTOR4D_PTR vb)
{
	VECTOR4D vdiff;

	vdiff.x = va->x - vb->x;
	vdiff.y = va->y - vb->y;
	vdiff.z = va->z - vb->z;
	vdiff.w = 1;

	// return result
	return(vdiff);
}

void TNYMATH::VECTOR4D_Scale(float k, VECTOR4D_PTR va)
{
	// multiply each component by scaling factor
	va->x *= k;
	va->y *= k;
	va->z *= k;
	va->w = 1;
}

void TNYMATH::VECTOR4D_Scale(float k, VECTOR4D_PTR va, VECTOR4D_PTR vscaled)
{
	vscaled->x = k * va->x;
	vscaled->y = k * va->y;
	vscaled->z = k * va->z;
	vscaled->w = 1;
}

float TNYMATH::VECTOR4D_Dot(VECTOR4D_PTR va, VECTOR4D_PTR vb)
{
	return((va->x * vb->x) + (va->y * vb->y) + (va->z * vb->z));
}

void TNYMATH::VECTOR4D_Cross(VECTOR4D_PTR va, VECTOR4D_PTR vb, VECTOR4D_PTR vn)
{
	vn->x = ((va->y * vb->z) - (va->z * vb->y));
	vn->y = -((va->x * vb->z) - (va->z * vb->x));
	vn->z = ((va->x * vb->y) - (va->y * vb->x));
	vn->w = 1;
}

VECTOR4D TNYMATH::VECTOR4D_Cross(VECTOR4D_PTR va, VECTOR4D_PTR vb)
{
	VECTOR4D vn;

	vn.x = ((va->y * vb->z) - (va->z * vb->y));
	vn.y = -((va->x * vb->z) - (va->z * vb->x));
	vn.z = ((va->x * vb->y) - (va->y * vb->x));
	vn.w = 1;

	// return result
	return(vn);
}

float TNYMATH::VECTOR4D_Length(VECTOR4D_PTR va)
{
	return(sqrtf(va->x*va->x + va->y*va->y + va->z*va->z));
}

float TNYMATH::VECTOR4D_Length_Fast(VECTOR4D_PTR va)
{
	return(Fast_Distance_3D(va->x, va->y, va->z));
}

void TNYMATH::VECTOR4D_Normalize(VECTOR4D_PTR va)
{
	float length = sqrtf(va->x*va->x + va->y*va->y + va->z*va->z);

	// test for zero length vector
	// if found return zero vector
	if (length < EPSILON_E5)
		return;

	float length_inv = 1.0 / length;

	// compute normalized version of vector
	va->x *= length_inv;
	va->y *= length_inv;
	va->z *= length_inv;
	va->w = 1;
}

void TNYMATH::VECTOR4D_Normalize(VECTOR4D_PTR va, VECTOR4D_PTR vn)
{
	VECTOR4D_ZERO(vn);

	// compute length
	float length = sqrt(va->x*va->x + va->y*va->y + va->z*va->z);

	// test for zero length vector
	// if found return zero vector
	if (length < EPSILON_E5)
		return;

	float length_inv = 1.0 / length;

	// compute normalized version of vector
	vn->x = va->x*length_inv;
	vn->y = va->y*length_inv;
	vn->z = va->z*length_inv;
	vn->w = 1;
}

void TNYMATH::VECTOR4D_Build(VECTOR4D_PTR init, VECTOR4D_PTR term, VECTOR4D_PTR result)
{
	result->x = term->x - init->x;
	result->y = term->y - init->y;
	result->z = term->z - init->z;
	result->w = 1;
}

float TNYMATH::VECTOR4D_CosTh(VECTOR4D_PTR va, VECTOR4D_PTR vb)
{
	return(VECTOR4D_Dot(va, vb) / (VECTOR4D_Length(va)*VECTOR4D_Length(vb)));
}

void TNYMATH::VECTOR4D_Print(VECTOR4D_PTR va, char* name)
{

}

void TNYMATH::Mat_Init_2X2(MATRIX2X2_PTR ma, float m00, float m01, float m10, float m11)
{
	ma->M00 = m00; ma->M01 = m01;
	ma->M10 = m10; ma->M11 = m11;
}

void TNYMATH::Print_Mat_2X2(MATRIX2X2_PTR ma, char* name)
{

}

float TNYMATH::Mat_Det_2X2(MATRIX2X2_PTR m)
{
	return(m->M00*m->M11 - m->M01*m->M10);
}

void TNYMATH::Mat_Add_2X2(MATRIX2X2_PTR ma, MATRIX2X2_PTR mb, MATRIX2X2_PTR msum)
{
	msum->M00 = ma->M00 + mb->M00;
	msum->M01 = ma->M01 + mb->M01;
	msum->M10 = ma->M10 + mb->M10;
	msum->M11 = ma->M11 + mb->M11;
}

void TNYMATH::Mat_Mul_2X2(MATRIX2X2_PTR ma, MATRIX2X2_PTR mb, MATRIX2X2_PTR mprod)
{
	mprod->M00 = ma->M00*mb->M00 + ma->M01*mb->M10;
	mprod->M01 = ma->M00*mb->M01 + ma->M01*mb->M11;
	mprod->M10 = ma->M10*mb->M00 + ma->M11*mb->M10;
	mprod->M11 = ma->M10*mb->M01 + ma->M11*mb->M11;
}

int TNYMATH::Mat_Inverse_2X2(MATRIX2X2_PTR m, MATRIX2X2_PTR mi)
{
	float det = (m->M00*m->M11 - m->M01*m->M10);

	// if determinate is 0 then inverse doesn't exist
	if (fabs(det) < EPSILON_E5)
		return(0);

	float det_inv = 1.0 / det;

	// fill in inverse by formula
	mi->M00 = m->M11*det_inv;
	mi->M01 = -m->M01*det_inv;
	mi->M10 = -m->M10*det_inv;
	mi->M11 = m->M00*det_inv;

	// return sucess
	return(1);
}

int TNYMATH::Solve_2X2_System(MATRIX2X2_PTR A, MATRIX1X2_PTR X, MATRIX1X2_PTR B)
{
	float det_A = Mat_Det_2X2(A);

	// test if det(a) is zero, if so then there is no solution
	if (fabs(det_A) < EPSILON_E5)
		return(0);

	// step 2: create x,y numerator matrices by taking A and
	// replacing each column of it with B(transpose) and solve
	MATRIX2X2 work_mat; // working matrix

	// solve for x /////////////////

	// copy A into working matrix
	MAT_COPY_2X2(A, &work_mat);

	// swap out column 0 (x column)
	MAT_COLUMN_SWAP_2X2(&work_mat, 0, B);

	// compute determinate of A with B swapped into x column
	float det_ABx = Mat_Det_2X2(&work_mat);

	// now solve for X00
	X->M00 = det_ABx / det_A;

	// solve for y /////////////////

	// copy A into working matrix
	MAT_COPY_2X2(A, &work_mat);

	// swap out column 1 (y column)
	MAT_COLUMN_SWAP_2X2(&work_mat, 1, B);

	// compute determinate of A with B swapped into y column
	float det_ABy = Mat_Det_2X2(&work_mat);

	// now solve for X01
	X->M01 = det_ABy / det_A;

	// return success
	return(1);
}

int TNYMATH::Mat_Mul_1x2_3x2(MATRIX1X2_PTR ma, MATRIX3X2_PTR mb, MATRIX1X2_PTR mprod)
{
	for (int col = 0; col < 2; col++)
	{
		float sum = 0;
		int index = 0;
		for (index = 0; index < 2; index++)
		{
			sum += (ma->M[index] * mb->M[index][col]);
		}
		sum += mb->M[index][col];
		mprod->M[col] = sum;
	}
	return 0;
}

int TNYMATH::Mat_Mul_1x3_3x3(MATRIX1X3_PTR ma, MATRIX3X3_PTR mb, MATRIX3X3_PTR mprod)
{
	return 0;
}

int TNYMATH::Mat_Mul_3x3(MATRIX3X3_PTR ma, MATRIX3X3_PTR mb, MATRIX3X3_PTR mprod)
{
	return 0;
}

int TNYMATH::Mat_Init_3x2(MATRIX3X2_PTR ma, float m00, float m01, float m10, float m11, float m20, float m21)
{
	return 0;
}

void TNYMATH::Mat_Add_3x3(MATRIX3X3_PTR ma, MATRIX3X3_PTR mb, MATRIX3X3_PTR msum)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			// insert resulting row,col element
			msum->M[row][col] = ma->M[row][col] + mb->M[row][col];
		} // end for col

	} // end for row
}

void TNYMATH::Mat_Mul_VECTOR3D_3x3(VECTOR3D_PTR va, MATRIX3X3_PTR mb, VECTOR3D_PTR vprod)
{
	for (int col = 0; col < 3; col++)
	{
		// compute dot product from row of ma 
		// and column of mb
		float sum = 0; // used to hold result

		for (int row = 0; row < 3; row++)
		{
			// add in next product pair
			sum += (va->M[row] * mb->M[row][col]);
		} // end for index

		   // insert resulting col element
		vprod->M[col] = sum;

	} // end for col
}

int TNYMATH::Mat_Inverse_3x3(MATRIX3X3_PTR m, MATRIX3X3_PTR mi)
{
	float det = m->M00*(m->M11*m->M22 - m->M21*m->M12) -
		m->M01*(m->M10*m->M22 - m->M20*m->M12) +
		m->M02*(m->M10*m->M21 - m->M20*m->M11);

	if (fabs(det) < EPSILON_E5)
		return(0);

	// compute inverse to save divides
	float det_inv = 1.0 / det;

	// compute inverse using m-1 = adjoint(m)/det(m)
	mi->M00 = det_inv * (m->M11*m->M22 - m->M21*m->M12);
	mi->M10 = -det_inv * (m->M10*m->M22 - m->M20*m->M12);
	mi->M20 = det_inv * (m->M10*m->M21 - m->M20*m->M11);

	mi->M01 = -det_inv * (m->M01*m->M22 - m->M21*m->M02);
	mi->M11 = det_inv * (m->M00*m->M22 - m->M20*m->M02);
	mi->M21 = -det_inv * (m->M00*m->M21 - m->M20*m->M01);

	mi->M02 = det_inv * (m->M01*m->M12 - m->M11*m->M02);
	mi->M12 = -det_inv * (m->M00*m->M12 - m->M10*m->M02);
	mi->M22 = det_inv * (m->M00*m->M11 - m->M10*m->M01);

	// return success
	return(1);
}

void TNYMATH::Mat_Init_3x3(MATRIX3X3_PTR ma, float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
{
	ma->M00 = m00; ma->M01 = m01; ma->M02 = m02;
	ma->M10 = m10; ma->M11 = m11; ma->M12 = m12;
	ma->M20 = m20; ma->M21 = m21; ma->M22 = m22;
}

void TNYMATH::Print_Mat_3x3(MATRIX3X3_PTR ma, char* name)
{

}

float TNYMATH::Mat_Det_3x3(MATRIX3X3_PTR m)
{
	return(m->M00*(m->M11*m->M22 - m->M21*m->M12) -
		m->M01*(m->M10*m->M22 - m->M20*m->M12) +
		m->M02*(m->M10*m->M21 - m->M20*m->M11));
}

int TNYMATH::Solve_3x3_System(MATRIX3X3_PTR A, MATRIX1X3_PTR X, MATRIX1X3_PTR B)
{
	// solves the system AX=B and computes X=A(-1)*B
// by using cramers rule and determinates

// step 1: compute determinate of A
	float det_A = Mat_Det_3x3(A);

	// test if det(a) is zero, if so then there is no solution
	if (fabs(det_A) < EPSILON_E5)
		return(0);

	// step 2: create x,y,z numerator matrices by taking A and
	// replacing each column of it with B(transpose) and solve
	MATRIX3X3 work_mat; // working matrix

	// solve for x /////////////////

	// copy A into working matrix
	MAT_COPY_3X3(A, &work_mat);

	// swap out column 0 (x column)
	MAT_COLUMN_SWAP_3X3(&work_mat, 0, B);

	// compute determinate of A with B swapped into x column
	float det_ABx = Mat_Det_3x3(&work_mat);

	// now solve for X00
	X->M00 = det_ABx / det_A;

	// solve for y /////////////////

	// copy A into working matrix
	MAT_COPY_3X3(A, &work_mat);

	// swap out column 1 (y column)
	MAT_COLUMN_SWAP_3X3(&work_mat, 1, B);

	// compute determinate of A with B swapped into y column
	float det_ABy = Mat_Det_3x3(&work_mat);

	// now solve for X01
	X->M01 = det_ABy / det_A;

	// solve for z /////////////////

	// copy A into working matrix
	MAT_COPY_3X3(A, &work_mat);

	// swap out column 2 (z column)
	MAT_COLUMN_SWAP_3X3(&work_mat, 2, B);

	// compute determinate of A with B swapped into z column
	float det_ABz = Mat_Det_3x3(&work_mat);

	// now solve for X02
	X->M02 = det_ABz / det_A;

	// return success
	return(1);
}

void TNYMATH::Mat_Add_4x4(MATRIX4X4_PTR ma, MATRIX4X4_PTR mb, MATRIX4X4_PTR msum)
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			// insert resulting row,col element
			msum->M[row][col] = ma->M[row][col] + mb->M[row][col];
		} // end for col

	} // end for row
}

int TNYMATH::Mat_Mul_4x4(MATRIX4X4_PTR ma, MATRIX4X4_PTR mb, MATRIX4X4_PTR mprod)
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			// compute dot product from row of ma 
			// and column of mb

			float sum = 0; // used to hold result

			for (int index = 0; index < 4; index++)
			{
				// add in next product pair
				sum += (ma->M[row][index] * mb->M[index][col]);
			} // end for index

	   // insert resulting row,col element
			mprod->M[row][col] = sum;

		} // end for col

	} // end for row
	return 0;
}

void TNYMATH::Mat_Mul_1x4_4x4(MATRIX1X4_PTR ma, MATRIX4X4_PTR mb, MATRIX1X4_PTR mprod)
{
	for (int col = 0; col < 4; col++)
	{
		// compute dot product from row of ma 
		// and column of mb
		float sum = 0; // used to hold result

		for (int row = 0; row < 4; row++)
		{
			// add in next product pair
			sum += (ma->M[row] * mb->M[row][col]);
		} // end for index

		   // insert resulting col element
		mprod->M[col] = sum;

	} // end for col
}

void TNYMATH::Mat_Mul_VECTOR3D_4x4(VECTOR3D_PTR va, MATRIX4X4_PTR mb, VECTOR3D_PTR vprod)
{
	for (int col = 0; col < 3; col++)
	{
		// compute dot product from row of ma 
		// and column of mb
		float sum = 0; // used to hold result
		int row = 0;
		for (; row < 3; row++)
		{
			// add in next product pair
			sum += (va->M[row] * mb->M[row][col]);
		} // end for index

		   // add in last element in column or w*mb[3][col]
		sum += mb->M[row][col];

		// insert resulting col element
		vprod->M[col] = sum;

	} // end for col
}

void TNYMATH::Mat_Mul_VECTOR3D_4x3(VECTOR3D_PTR va, MATRIX4X3_PTR mb, VECTOR3D_PTR vprod)
{
	for (int col = 0; col < 3; col++)
	{
		// compute dot product from row of ma 
		// and column of mb
		float sum = 0; // used to hold result
		int row = 0;
		for (; row < 3; row++)
		{
			// add in next product pair
			sum += (va->M[row] * mb->M[row][col]);
		} // end for index

		   // add in last element in column or w*mb[3][col]
		sum += mb->M[row][col];

		// insert resulting col element
		vprod->M[col] = sum;

	} // end for col
}

void TNYMATH::Mat_Mul_VECTOR4D_4x4(VECTOR4D_PTR va, MATRIX4X4_PTR mb, VECTOR4D_PTR vprod)
{
	for (int col = 0; col < 4; col++)
	{
		// compute dot product from row of ma 
		// and column of mb
		float sum = 0; // used to hold result

		for (int row = 0; row < 4; row++)
		{
			// add in next product pair
			sum += (va->M[row] * mb->M[row][col]);
		} // end for index

		   // insert resulting col element
		vprod->M[col] = sum;

	} // end for col
}

void TNYMATH::Mat_Mul_VECTOR4D_4x3(VECTOR4D_PTR va, MATRIX4X3_PTR mb, VECTOR4D_PTR vprod)
{
	for (int col = 0; col < 3; col++)
	{
		// compute dot product from row of ma 
		// and column of mb
		float sum = 0; // used to hold result

		for (int row = 0; row < 4; row++)
		{
			// add in next product pair
			sum += (va->M[row] * mb->M[row][col]);
		} // end for index

		   // insert resulting col element
		vprod->M[col] = sum;

	} // end for col

		 // copy back w element
	vprod->M[3] = va->M[3];
}

int TNYMATH::Mat_Inverse_4x4(MATRIX4X4_PTR m, MATRIX4X4_PTR mi)
{
	float det = (m->M00 * (m->M11 * m->M22 - m->M12 * m->M21) -
		m->M01 * (m->M10 * m->M22 - m->M12 * m->M20) +
		m->M02 * (m->M10 * m->M21 - m->M11 * m->M20));

	// test determinate to see if it's 0
	if (fabs(det) < EPSILON_E5)
		return(0);

	float det_inv = 1.0f / det;

	mi->M00 = det_inv * (m->M11 * m->M22 - m->M12 * m->M21);
	mi->M01 = -det_inv * (m->M01 * m->M22 - m->M02 * m->M21);
	mi->M02 = det_inv * (m->M01 * m->M12 - m->M02 * m->M11);
	mi->M03 = 0.0f; // always 0

	mi->M10 = -det_inv * (m->M10 * m->M22 - m->M12 * m->M20);
	mi->M11 = det_inv * (m->M00 * m->M22 - m->M02 * m->M20);
	mi->M12 = -det_inv * (m->M00 * m->M12 - m->M02 * m->M10);
	mi->M13 = 0.0f; // always 0

	mi->M20 = det_inv * (m->M10 * m->M21 - m->M11 * m->M20);
	mi->M21 = -det_inv * (m->M00 * m->M21 - m->M01 * m->M20);
	mi->M22 = det_inv * (m->M00 * m->M11 - m->M01 * m->M10);
	mi->M23 = 0.0f; // always 0

	mi->M30 = -(m->M30 * mi->M00 + m->M31 * mi->M10 + m->M32 * mi->M20);
	mi->M31 = -(m->M30 * mi->M01 + m->M31 * mi->M11 + m->M32 * mi->M21);
	mi->M32 = -(m->M30 * mi->M02 + m->M31 * mi->M12 + m->M32 * mi->M22);
	mi->M33 = 1.0f; // always 0

	// return success 
	return(1);
}

void TNYMATH::Mat_Init_4x4(MATRIX4X4_PTR ma, float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
{
	ma->M00 = m00; ma->M01 = m01; ma->M02 = m02; ma->M03 = m03;
	ma->M10 = m10; ma->M11 = m11; ma->M12 = m12; ma->M13 = m13;
	ma->M20 = m20; ma->M21 = m21; ma->M22 = m22; ma->M23 = m23;
	ma->M30 = m30; ma->M31 = m31; ma->M32 = m32; ma->M33 = m33;
}

void TNYMATH::Print_Mat_4x4(MATRIX4X4_PTR ma, char* name)
{

}

void TNYMATH::QUAT_Add(QUAT_PTR q1, QUAT_PTR q2, QUAT_PTR qaum)
{

}

void TNYMATH::QUAT_Sub(QUAT_PTR q, QUAT_PTR q2, QUAT_PTR qdiff)
{

}

void TNYMATH::QUAT_Conjuate(QUAT_PTR q, QUAT_PTR qconj)
{

}

void TNYMATH::QUAT_Scale(QUAT_PTR q, float scale, QUAT_PTR qs)
{

}

float TNYMATH::QUAT_Norm(QUAT_PTR q)
{
	return 0.0;
}

float TNYMATH::QUAT_Norm2(QUAT_PTR q)
{
	return 0.0;
}

void TNYMATH::QUAT_Normalize(QUAT_PTR q, QUAT_PTR qn)
{

}

void TNYMATH::QUAT_Normalize(QUAT_PTR q)
{

}

void TNYMATH::QUAT_Unit_Inverse(QUAT_PTR q, QUAT_PTR qi)
{

}

void TNYMATH::QUAT_Unit_Inverse(QUAT_PTR q)
{

}

void TNYMATH::QUAT_Mul(QUAT_PTR q1, QUAT_PTR q2, QUAT_PTR q3, QUAT_PTR qprod)
{

}

void TNYMATH::QUAT_Triple_Product(QUAT_PTR q1, QUAT_PTR q2, QUAT_PTR q3, QUAT_PTR qprod)
{

}

void TNYMATH::VECTOR3D_Theta_To_QUAT(QUAT_PTR q, VECTOR3D_PTR v, float theta)
{

}

void TNYMATH::VECTOR4D_Theta_To_QUAT(QUAT_PTR q, VECTOR4D_PTR v, float theta)
{

}

void TNYMATH::EulerZYX_To_QUAT(QUAT_PTR q, float theta_z, float theta_y, float theta_x)
{

}

void TNYMATH::QUAT_To_VECTOR3D_Theta(QUAT_PTR q, VECTOR3D_PTR v, float* theta)
{

}

void TNYMATH::QUAT_Print(QUAT_PTR q, char* name)
{

}

void TNYMATH::Init_Parm_Line2D(POINT2D_PTR p_init, POINT2D_PTR p_term, PARMLINE2D_PTR p)
{
	// start point
	VECTOR2D_INIT(&(p->p0), p_init);

	// end point
	VECTOR2D_INIT(&(p->p1), p_term);

	// now compute direction vector from p0->p1
	VECTOR2D_Build(p_init, p_term, &(p->v));
}

void TNYMATH::Compute_Parm_Line2D(PARMLINE2D_PTR p, float t, POINT2D_PTR pt)
{
	pt->x = p->p0.x + p->v.x*t;
	pt->y = p->p0.y + p->v.y*t;
}

int TNYMATH::Intersect_Parm_Lines2D(PARMLINE2D_PTR p1, PARMLINE2D_PTR p2, float *t1, float *t2)
{
	float det_p1p2 = (p1->v.x*p2->v.y - p1->v.y*p2->v.x);
	if (fabs(det_p1p2) <= EPSILON_E5)
	{
		// at this point, the lines either don't intersect at all
		// or they are the same lines, in which case they may intersect
		// at one or many points along the segments, at this point we 
		// will assume that the lines don't intersect at all, but later
		// we may need to rewrite this function and take into 
		// consideration the overlap and singular point exceptions
		return(PARM_LINE_NO_INTERSECT);

	} // end if

	 // step 2: now compute the t1, t2 values for intersection
	 // we have two lines of the form
	 // p    = p0    +  v*t, specifically
	 // p1   = p10   + v1*t1

	 // p1.x = p10.x + v1.x*t1
	 // p1.y = p10.y + v1.y*t1

	 // p2 = p20 + v2*t2
	 // p2   = p20   + v2*t2

	 // p2.x = p20.x + v2.x*t2
	 // p2.y = p20.y + v2.y*t2
	 // solve the system when x1 = x2 and y1 = y2
	 // explained in chapter 4
	*t1 = (p2->v.x*(p1->p0.y - p2->p0.y) - p2->v.y*(p1->p0.x - p2->p0.x))
		/ det_p1p2;

	*t2 = (p1->v.x*(p1->p0.y - p2->p0.y) - p1->v.y*(p1->p0.x - p2->p0.x))
		/ det_p1p2;

	// test if the lines intersect on the segments
	if ((*t1 >= 0) && (*t1 <= 1) && (*t2 >= 0) && (*t2 <= 1))
		return(PARM_LINE_INTERSECT_IN_SEGMENT);
	else
		return(PARM_LINE_INTERSECT_OUT_SEGMENT);
}

int TNYMATH::Intersect_Parm_Lines2D(PARMLINE2D_PTR p1, PARMLINE2D_PTR p2, POINT2D_PTR pt)
{
	float t1, t2, det_p1p2 = (p1->v.x*p2->v.y - p1->v.y*p2->v.x);

	if (fabs(det_p1p2) <= EPSILON_E5)
	{
		// at this point, the lines either don't intersect at all
		// or they are the same lines, in which case they may intersect
		// at one or many points along the segments, at this point we 
		// will assume that the lines don't intersect at all, but later
		// we may need to rewrite this function and take into 
		// consideration the overlap and singular point exceptions
		return(PARM_LINE_NO_INTERSECT);

	} // end if

		 // step 2: now compute the t1, t2 values for intersection
		 // we have two lines of the form
		 // p    = p0    +  v*t, specifically
		 // p1   = p10   + v1*t1

		 // p1.x = p10.x + v1.x*t1
		 // p1.y = p10.y + v1.y*t1

		 // p2 = p20 + v2*t2
		 // p2   = p20   + v2*t2

		 // p2.x = p20.x + v2.x*t2
		 // p2.y = p20.y + v2.y*t2
		 // solve the system when x1 = x2 and y1 = y2
		 // explained in chapter 4
	t1 = (p2->v.x*(p1->p0.y - p2->p0.y) - p2->v.y*(p1->p0.x - p2->p0.x))
		/ det_p1p2;

	t2 = (p1->v.x*(p1->p0.y - p2->p0.y) - p1->v.y*(p1->p0.x - p2->p0.x))
		/ det_p1p2;

	// now compute point of intersection
	pt->x = p1->p0.x + p1->v.x*t1;
	pt->y = p1->p0.y + p1->v.y*t1;

	// test if the lines intersect on the segments
	if ((t1 >= 0) && (t1 <= 1) && (t2 >= 0) && (t2 <= 1))
		return(PARM_LINE_INTERSECT_IN_SEGMENT);
	else
		return(PARM_LINE_INTERSECT_OUT_SEGMENT);
}

void TNYMATH::Init_Parm_Line3D(POINT3D_PTR p_init, POINT3D_PTR p_term, PARMLINE3D_PTR p)
{
	// start point
	VECTOR3D_INIT(&(p->p0), p_init);

	// end point
	VECTOR3D_INIT(&(p->p1), p_term);

	// now compute direction vector from p0->p1
	VECTOR3D_Build(p_init, p_term, &(p->v));
}

void TNYMATH::Compute_Parm_Line3D(PARMLINE3D_PTR p, float t, POINT3D_PTR pt)
{
	pt->x = p->p0.x + p->v.x*t;
	pt->y = p->p0.y + p->v.y*t;
	pt->z = p->p0.z + p->v.z*t;
}

void TNYMATH::PLANE3D_Init(PLANE3D_PTR plane, POINT3D_PTR p0, VECTOR3D_PTR normal, int normalize)
{
	// copy the point
	POINT3D_COPY(&plane->p0, p0);

	// if normalize is 1 then the normal is made into a unit vector
	if (!normalize)
	{
		VECTOR3D_COPY(&plane->n, normal);
	}
	else
	{
		// make normal into unit vector
		VECTOR3D_Normalize(normal, &plane->n);
	} // end else
}

float TNYMATH::Compute_Point_In_Plane3D(POINT3D_PTR pt, PLANE3D_PTR plane)
{
	float hs = plane->n.x*(pt->x - plane->p0.x) +
		plane->n.y*(pt->y - plane->p0.y) +
		plane->n.z*(pt->z - plane->p0.z);

	// return half space value
	return(hs);
}

int TNYMATH::Intersect_Parm_Line3D_Plane3D(PARMLINE3D_PTR pline, PLANE3D_PTR plane, float* t, POINT3D_PTR pt)
{
	// this function determines where the sent parametric line 
// intersects the plane the function will project the line 
// infinitely in both directions, to compute the intersection, 
// but the line segment defined by p intersected the plane iff t e [0,1]
// also the function returns 0 for no intersection, 1 for 
// intersection of the segment and the plane and 2 for intersection 
// of the line along the segment and the plane 3, the line lies 
// in the plane

// first test of the line and the plane are parallel, if so 
// then they can't intersect unless the line lies in the plane!

	float plane_dot_line = VECTOR3D_Dot(&pline->v, &plane->n);

	if (fabs(plane_dot_line) <= EPSILON_E5)
	{
		// the line and plane are co-planer, does the line lie 
		// in the plane?
		if (fabs(Compute_Point_In_Plane3D(&pline->p0, plane)) <= EPSILON_E5)
			return(PARM_LINE_INTERSECT_EVERYWHERE);
		else
			return(PARM_LINE_NO_INTERSECT);
	} // end if

	 // from chapter 4 we know that we can solve for the t where 
	 // intersection occurs by
	 // a*(x0+vx*t) + b*(y0+vy*t) + c*(z0+vz*t) + d =0
	 // t = -(a*x0 + b*y0 + c*z0 + d)/(a*vx + b*vy + c*vz)
	 // x0,y0,z0, vx,vy,vz, define the line
	 // d = (-a*xp0 - b*yp0 - c*zp0), xp0, yp0, zp0, define the point on the plane 

	*t = -(plane->n.x*pline->p0.x +
		plane->n.y*pline->p0.y +
		plane->n.z*pline->p0.z -
		plane->n.x*plane->p0.x -
		plane->n.y*plane->p0.y -
		plane->n.z*plane->p0.z) / (plane_dot_line);

	// now plug t into the parametric line and solve for x,y,z
	pt->x = pline->p0.x + pline->v.x*(*t);
	pt->y = pline->p0.y + pline->v.y*(*t);
	pt->z = pline->p0.z + pline->v.z*(*t);

	// test interval of t
	if (*t >= 0.0 && *t <= 1.0)
		return(PARM_LINE_INTERSECT_IN_SEGMENT);
	else
		return(PARM_LINE_INTERSECT_OUT_SEGMENT);
}

FIXP16 TNYMATH::FIXP16_MUL(FIXP16 fp1, FIXP16 fp2)
{
	// this function computes the product fp_prod = fp1*fp2
	// using 64 bit math, so as not to loose precission

	FIXP16 fp_prod; // return the product

	_asm {
		mov eax, fp1      // move into eax fp2
		imul fp2          // multiply fp1*fp2
		shrd eax, edx, 16 // result is in 32:32 format 
						  // residing at edx:eax
						  // shift it into eax alone 16:16
		// result is sitting in eax
	} // end
}

FIXP16 TNYMATH::FIXP16_DIV(FIXP16 fp1, FIXP16 fp2)
{
	_asm {
		mov eax, fp1      // move dividend into eax
		cdq               // sign extend it to edx:eax
		shld edx, eax, 16 // now shift 16:16 into position in edx
		sal eax, 16       // and shift eax into position since the
						  // shld didn't move it -- DUMB! uPC
						  idiv fp2          // do the divide
						  // result is sitting in eax     
	} // end asm
}

void TNYMATH::FIXP16_Print(FIXP16 fp)
{

}

void TNYMATH::QUAT_Scale(QUAT_PTR q, float scale)
{

}
