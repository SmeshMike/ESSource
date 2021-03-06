
#ifndef __ESVEC_H__
#define __ESVEC_H__

class vector
{
private:

public:

    void Add(const __m128 &a, const __m128 &b, __m128 &c);

    void Subtract(const __m128 &a, const __m128 &b, __m128 &c);

    void Multiply(const __m128 &a, const __m128 &b, __m128 &c);

    void Divide(const __m128 &a, const __m128 &b, __m128 &c);

    void Normalize(const __m128 &a, const __m128 &b, __m128 &c);
};

#endif __ESVEC_H__