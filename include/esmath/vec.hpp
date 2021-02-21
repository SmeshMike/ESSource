
#ifndef __ESVEC_H__
#define __ESVEC_H__

class v2 
{
private:
    float mem[2] = { 0.0, 0.0 };
public:
    
    // Initializatiors
    v2() {};
    v2(const float const vector[2]);
    
    // Operators
    void x(float);
    float x();

    void y(float);
    float y();

    // Algs
    void normilse();
};

#endif __ESVEC_H__