#include <xmmintrin.h>

void Add(const __m128 &a, const __m128 &b, __m128 &c)
{
    c = _mm_add_ps(a, b);
}

void Subtract(const __m128 &a, const __m128 &b, __m128 &c)
{
    c = _mm_sub_ps(a, b);
}

void Multiply(const __m128 &a, const __m128 &b, __m128 &c)
{
    c = _mm_mul_ps(a, b);
}

void Division(const __m128 &a, const __m128 &b, __m128 &c)
{
    c = _mm_div_ps (a, b);
}

void Normalize(const __m128 &a, const __m128 &b, __m128 &c)
{
    c = _mm_div_ps (a, _mm_rsqrt_ps (b));
}

