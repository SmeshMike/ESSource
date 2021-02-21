#include "vec.hpp"
#include <cmath>

void v2::normilse() 
{
    float len = sqrtf(mem[0] * mem[0] + mem[1] + mem[1]);
    mem[0] = mem[0] / len;
    mem[1] = mem[1] / len;
}

v2::v2(const float const vec[2])
{
    mem[0] = vec[0];
    mem[1] = vec[1];
}

float v2::x() { return mem[0]; }
float v2::y() { return mem[1]; }

void v2::x(float nx) { mem[0] = nx; }
void v2::y(float ny) { mem[1] = ny; }

