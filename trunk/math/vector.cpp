#include "vector.hpp"

vector3 normalized(const vector3 &a)
{
	vector3 ret(a);
	return ret.normalize();
}

float length(const vector3 &v)
{
	return v.length();
}

vector3 abs(const vector3 &v)
{
	return vector3(fabs(v.x), fabs(v.y), fabs(v.z));
}

float dot_product(const vector3 &a, const vector3 &b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

void swap(vector3 &a, vector3 &b)
{
	vector3 tmp(a);

	a = b;
	b = tmp;
}

vector3 cross_product(const vector3 &a, const vector3 &b)
{
	  return vector3(a.y*b.z - a.z*b.y,
					 a.z*b.x - a.x*b.z,
					 a.x*b.y - a.y*b.x);
}

float triple_product(const vector3 &u, const vector3 &v, const vector3 &w)
{
	return (u.x * (v.y*w.z - v.z*w.y)) + (u.y * (-v.x*w.z + v.z*w.x)) + (u.z * (v.x*w.y - v.y*w.x));
}

bool nearly_equals(const vector3 &a, const vector3 &b, float r)
{
	vector3 diff = a - b;  // difference

	return(dot_product(diff, diff) < r*r);  // m_radius
}

vector3 reflection(const vector3& a, vector3& b)
{
	vector3 vec(normalized(a));
	return (vec - b * 2.0f * dot_product(vec, b)) * a.length();
}

float max(const vector3 &a)
{
	return a.x > a.y ? (a.x > a.z ? a.x : a.z) : (a.y > a.z ? a.y : a.z);
}

unsigned int max_idx(const vector3 &a)
{
	return a.x > a.y ? (a.x > a.z ? 0 : 2) : (a.y > a.z ? 1 : 2);
}

float min(const vector3 &a)
{
	return a.x < a.y ? (a.x < a.z ? a.x : a.z) : (a.y < a.z ? a.y : a.z);
}

unsigned int min_idx(const vector3 &a)
{
	return a.x < a.y ? (a.x < a.z ? 0 : 2) : (a.y < a.z ? 1 : 2);
}

float abs_max(const vector3 &a)
{
	return fabs(a.x) > fabs(a.y) ? (fabs(a.x) > fabs(a.z) ? a.x : a.z) : (fabs(a.y) > fabs(a.z) ? a.y : a.z);
}

unsigned int abs_max_idx(const vector3 &a)
{
	return fabs(a.x) > fabs(a.y) ? (fabs(a.x) > fabs(a.z) ? 0 : 2) : (fabs(a.y) > fabs(a.z) ? 1 : 2);
}

float abs_min(const vector3 &a)
{
	return fabs(a.x) < fabs(a.y) ? (fabs(a.x) < fabs(a.z) ? a.x : a.z) : (fabs(a.y) < fabs(a.z) ? a.y : a.z);
}

unsigned int abs_min_idx(const vector3 &a)
{
	return fabs(a.x) < fabs(a.y) ? (fabs(a.x) < fabs(a.z) ? 0 : 2) : (fabs(a.y) < fabs(a.z) ? 1 : 2);
}
