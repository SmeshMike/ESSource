#include "vec.hpp"

union innervector
{
    __m128 _m;
    float _f[4];
};

class vec4
{
private:
    innervector memory;
public:
    vec4()
    {
        float a[4] = {0.0,0.0,0.0,0.0};
        memory._m = _mm_load_ps((float*)&a);
    }
    vec4(const float* a)
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

    vec4 operator=(const vec4& other)
    {
        memory = other.memory;
        return *this;
    }

    bool operator==(const vec4& a)
    {
        return (memory._f[0]==a.memory._f[0]) &&(memory._f[1]==a.memory._f[1]) &&(memory._f[2]==a.memory._f[2]) &&(memory._f[3]==a.memory._f[3]);
    }

    friend bool operator!=(vec4 a, const vec4& b)
    {
        return !(a==b);
    }

    vec4 operator+=(const vec4& other)
    {
        memory._m = _mm_add_ps(memory._m, other.memory._m);
        return *this;
    }

    vec4 operator-=(const vec4& other)
    {
        memory._m = _mm_sub_ps(memory._m, other.memory._m);
        return *this;
    }

    vec4 operator*=(const vec4& other)
    {
        memory._m = _mm_mul_ps(memory._m, other.memory._m);
        return *this;
    }

    vec4 operator/=(const vec4& other)
    {
        memory._m = _mm_div_ps(memory._m, other.memory._m);
        return *this;
    }

    friend vec4 operator+(const vec4& a, const vec4& b)
    {
        vec4 result = a;
        result += b;
        return result;
    }

    friend vec4 operator-(const vec4& a, const vec4& b)
    {
        vec4 result = a;
        result -= b;
        return result;
    }

    friend vec4 operator*(const vec4& a, const vec4& b)
    {
        vec4 result = a;
        result *= b;
        return result;
    }

    friend vec4 operator/(const vec4& a, const vec4& b)
    {
        vec4 result = a;
        result /= b;
        return result;
    }

};
