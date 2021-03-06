#include "vec.hpp"
#include <cmath>
#include <xmmintrin.h>

union innervector
{
    __m128 _m;
    float _f[2];
};

class vec2 : public vector
{
private:
    innervector memory;
public:
    vec2()
    {
        float a[2] = {0.0,0.0};
        memory._m = _mm_load_ps((float*)&a);
    }
    vec2(const float* a)
    {
        memory._m = _mm_load_ps(a);
    }

    void Add(const __m128 &a, const __m128 &b, __m128 &c)
    {
        memory._m = _mm_add_ps(a, b);
    }

    void Subtract(const __m128 &a, const __m128 &b, __m128 &c)
    {
        memory._m = _mm_sub_ps(a, b);
    }

    void Multiply(const __m128 &a, const __m128 &b, __m128 &c)
    {
        memory._m = _mm_mul_ps(a, b);
    }

    void Divide(const __m128 &a, const __m128 &b, __m128 &c)
    {
        memory._m = _mm_div_ps (a, b);
    }

    void Normalize(const __m128 &a, const __m128 &b, __m128 &c)
    {
        memory._m = _mm_div_ps (a, _mm_rsqrt_ps (b));
    }

    vec2 operator=(const vec2& other)
    {
        memory = other.memory;
        return *this;
    }

    bool operator==(const vec2& a)
    {
        return (memory._f[0]==a.memory._f[0]) &&(memory._f[1]==a.memory._f[1]);
    }

    friend bool operator!=(vec2 a, const vec2& b)
    {
        return !(a==b);
    }

    vec2 operator+=(const vec2& other)
    {
        memory._m = _mm_add_ps(memory._m, other.memory._m);
        return *this;
    }

    vec2 operator-=(const vec2& other)
    {
        memory._m = _mm_sub_ps(memory._m, other.memory._m);
        return *this;
    }

    vec2 operator*=(const vec2& other)
    {
        memory._m = _mm_mul_ps(memory._m, other.memory._m);
        return *this;
    }

    vec2 operator/=(const vec2& other)
    {
        memory._m = _mm_div_ps(memory._m, other.memory._m);
        return *this;
    }

    friend vec2 operator+(const vec2& a, const vec2& b)
    {
        vec2 result = a;
        result += b;
        return result;
    }

    friend vec2 operator-(const vec2& a, const vec2& b)
    {
        vec2 result = a;
        result -= b;
        return result;
    }

    friend vec2 operator*(const vec2& a, const vec2& b)
    {
        vec2 result = a;
        result *= b;
        return result;
    }

    friend vec2 operator/(const vec2& a, const vec2& b)
    {
        vec2 result = a;
        result /= b;
        return result;
    }

};

