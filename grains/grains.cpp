#include "grains.h"

namespace grains {

    unsigned long long square(int i){
        unsigned long long x=1;
        x<<=(i-1);
        return x;
    }
    unsigned long long total(){
        unsigned long long x=0;
        int n=64;
        while(n>0){
            x+=square(n);
            n--;
        }
        return x;
    }

}  // namespace grains
