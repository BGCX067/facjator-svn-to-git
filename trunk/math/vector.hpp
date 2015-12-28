#pragma once
#include <iostream>
#include <cassert>
#include <cmath>

class vector3;

// tolua
// tolua_begin
vector3 normalized(const vector3 &a);
float length(const vector3 &v);
vector3 abs(const vector3 &v);
float dot_product(const vector3 &a, const vector3 &b);
void swap(vector3 &a, vector3 &b);
vector3 cross_product(const vector3 &a, const vector3 &b);
float triple_product(const vector3 &u, const vector3 &v, const vector3 &w);
bool nearly_equals(const vector3 &a, const vector3 &b, float r);
vector3 reflection(const vector3& a, vector3& b);
float max(const vector3 &a);
unsigned int max_idx(const vector3 &a);
float min(const vector3 &a);
unsigned int min_idx(const vector3 &a);
float abs_max(const vector3 &a);
unsigned int abs_max_idx(const vector3 &a);
float abs_min(const vector3 &a);
unsigned int abs_min_idx(const vector3 &a);
// tolua_end

class vector3 // tolua_export
{             // tolua_export
   	public:
        // Members
   	    float x, y, z;

   	public:
       	// Constructors
       	vector3() {}
       	// Constructor with initializing float values
       	vector3(float inX, float inY, float inZ) : x(inX), y(inY), z(inZ) {}

       	vector3(const vector3& v) : x(v.x), y(v.y), z(v.z) {}

       	// tolua
       	#if 0
       	// tolua_begin
       	vector3();
       	vector3(float inX, float inY, float inZ);
       	vector3(const vector3& v);
       	// tolua_end
       	#endif

    public:
        // Array indexing
   	    inline float			&operator [] (unsigned int i)
		{
			assert (i<3);
   			return *(&this->x+i);
		}
       	// Array indexing
       	inline const float		&operator [] (unsigned int i) const
		{
    		assert (i<3);
   			return *(&this->x+i);
		}
       	// Add a vector3 to this one
       	inline vector3			&operator += (const vector3 &v)
		{
    		x += v.x;
   			y += v.y;
   			z += v.z;
   			return *this;
		}
       	// Subtract a vector3 from this one
       	inline vector3			&operator -= (const vector3 &v)
		{
    		x -= v.x;
   			y -= v.y;
   			z -= v.z;
   			return *this;
		}
       	// Multiply the vector3 by a float
       	inline vector3			&operator *= (float f)
		{
    		x *= f;
   			y *= f;
   			z *= f;
   			return *this;
		}
       	// Divide the vector3 by a float
       	inline vector3			&operator /= (float f)
		{
    		float a = 1.0f/f;
   			x *= a;
   			y *= a;
   			z *= a;
   			return *this;
		}
       	// Are these two vector3's equal?
       	inline bool				operator == (const vector3 &a)
		{
    		return((x == a.x) && (y == a.y) && (z == a.z));
		}
       	// Are these two vector3's not equal?
      	inline bool				operator != (const vector3 &a)
		{
    		return((x != a.x) || (y != a.y) || (z != a.z));
		}
       	// Negate a vector3
       	inline vector3			operator - ()
		{
    		return vector3(-x, -y, -z);
		}
       	// Add two vector3's
       	inline vector3			operator + (vector3 &a)
		{
    		return vector3(x + a.x, y + a.y, z + a.z);
		}
       	// Add two vector3's
       	inline vector3			operator + (const vector3 &a) const
		{
    		return vector3(x + a.x, y + a.y, z + a.z);
		}
       	// Subtract one vector3 from another
       	inline vector3			operator - (vector3 &a)
		{
    		return vector3(x - a.x, y - a.y, z - a.z);
		}
       	// Subtract one vector3 from another
       	inline vector3			operator - (const vector3 &a) const
		{
    		return vector3(x - a.x, y - a.y, z - a.z);
		}
       	// Multiply vector3 by a float
       	inline vector3			operator * (float f)
		{
    		return vector3(f * x, f * y, f * z);
		}
   	    // Divide vector3 by a float
       	inline vector3			operator / (float f)
		{
    		float a = 1.0f/f;
   			return vector3(x * a, y * a, z * a);
		}
        inline float* get_ptr()
		{
			return &this->x;
		}
       	friend std::ostream		&operator << (std::ostream &os, vector3 &v)
		{
    		os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
   			return os;
		}

		// tolua
		#if 0
		// tolua_begin
   	    float &operator [] (unsigned int i);
       	const float &operator [] (unsigned int i) const;
//       	vector3 &operator += (const vector3 &v);
//       	vector3 &operator -= (const vector3 &v);
//       	vector3 &operator *= (float f);
//       	vector3 &operator /= (float f);
//       	vector3 operator - ();
       	vector3 operator + (vector3 &v);
       	vector3 operator + (const vector3 &v) const;
       	vector3 operator - (vector3 &v);
       	vector3 operator - (const vector3 &v) const;
       	vector3 operator * (float f);
   	    vector3 operator / (float f);
		// tolua_end
		#endif

   	public:
        // Methods
       	// Set Values
       	inline void				set(float xIn, float yIn, float zIn)
		{
    		x = xIn;
   			y = yIn;
   			z = zIn;
		}
       	// Get length of a vector3
       	inline float			length() const
		{
    		return static_cast<float>(sqrt(x*x + y*y + z*z));
		}
       	// Get squared length of a vector3
       	inline float			length_sqr() const
       	{
    		return (x*x + y*y + z*z);
		}
       	// Does vector3 equal (0, 0, 0)?
       	inline bool				is_zero() const
		{
    		return((x == 0.0f) && (y == 0.0f) && (z == 0.0f));
		}

       	// Normalize a vector3
       	inline vector3			&normalize()
		{
    		float m = length();
   			if (m > 0.0f)
        		m = 1.0f / m;
   			else
        		m = 0.0f;
   			x *= m;
   			y *= m;
   			z *= m;
   			return *this;
		}
       	// reflection
       	inline vector3			&reflection(vector3 &normal)
		{
    		vector3 vec(*this);
   			*this = (vec + normal * 2.0f * dot_product(-vec, normal)); // * this->length();
   			return *this;
		}
       	// angle
       	inline float			angle(vector3 &v)
		{
    		return static_cast<float>(acos(dot_product(*this, v)));
		}

       	// tolua
       	#if 0
       	// tolua_begin
       	void    set(float xIn, float yIn, float zIn);
       	float   length() const;
       	float   length_sqr() const;
       	bool    is_zero() const;
       	vector3 &normalize();
       	vector3 &reflection(vector3 &normal);
       	float    angle(vector3 &v);
       	// tolua_end
       	#endif
}; // tolua_export
