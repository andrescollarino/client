#pragma once

namespace FMath
{
    
template<class T>
T Lerp(const T& a,const T& b , float t)
{
    return a + (b - a) * t;
};

};