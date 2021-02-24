#include <xmmintrin.h>

void Add(float *a, float *b, float *c)
{
    __m128 tmpA, tmpB;
    tmpA = _mm_load_ps(a);
    tmpB = _mm_load_ps(b);
    tmpA = _mm_add_ps(tmpA, tmpB);
    _mm_store_ps(c, tmpA);
}

void Subtract(float *a, float *b, float *c)
{
    __m128 tmpA, tmpB;
    tmpA = _mm_load_ps(a);
    tmpB = _mm_load_ps(b);
    tmpA = _mm_sub_ps(tmpA, tmpB);
    _mm_store_ps(c, tmpA);
}

void Multiply(float *a, float *b, float *c)
{
    __m128 tmpA, tmpB;
    tmpA = _mm_load_ps(a);
    tmpB = _mm_load_ps(b);
    tmpA = _mm_mul_ps(tmpA, tmpB);
    _mm_store_ps(c, tmpA);
}

void Multiply(float *a, float *b, float *c)
{
    __m128 tmpA, tmpB;
    tmpA = _mm_load_ps(a);
    tmpB = _mm_load_ps(b);
    tmpA = _mm_div_ps (tmpA, tmpB);
    _mm_store_ps(c, tmpA);
}

