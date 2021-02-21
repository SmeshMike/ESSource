#include <iostream>
#include <esmath/vec.hpp>

int main(int argc, char** argv)
{
    float data[2] = { 3.4, 0.0 };
    v2 vec(data);

    vec.normilse();

    if( vec.x() != 1.0 ) return 1;
    if( vec.y() != 0.0 ) return 1;

    return 0;
}