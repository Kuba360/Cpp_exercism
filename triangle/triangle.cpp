#include "triangle.h"
#include <stdexcept>

namespace triangle {


    flavor kind(double a,double b, double c){
        if(a<=0 || b<=0 || c<=0 || a+b<c || a+c<b || b+c<a){
            throw std::domain_error("error");
        }
        if(a==b && b==c && a==c) return equilateral;
        if(a==b || b==c || a==c) return isosceles;
        return scalene;
    }

}  // namespace triangle
