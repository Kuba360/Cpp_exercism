#include "perfect_numbers.h"
#include <stdexcept>
namespace perfect_numbers {

    classification classify(int x){
        if(x<1) throw std::domain_error(" ");
        int divider=1;
        int sum=0;
        int range=x>>1;
        while(divider<=range){
            if(x%divider==0){
                sum+=divider;
            }
            divider++;
        }
        if(sum==x)return perfect;
        if(sum>x)return abundant;
        if(sum<x)return deficient;
        return perfect;
        
    }
}  // namespace perfect_numbers
