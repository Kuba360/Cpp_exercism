#include "collatz_conjecture.h"
#include <stdexcept>
namespace collatz_conjecture {

    int steps(int x){
        if(x<=0){throw std::domain_error("x must be positive");}
        int n=0;
        while(x!=1){
            if(x%2==0){
                x/=2;
            }else{
                x=x*3+1;
            }
            n++;
        }
        return n;
    }

}  // namespace collatz_conjecture
