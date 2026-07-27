#include "sieve.h"

namespace sieve {

    const std::vector<int> primes(size_t x){
       std::vector<bool> p(x+1,true);
       std::vector<int> nv;
       p[0]=false;
       p[1]=false;
       for(size_t i=2;i<x+1;i++){
            if(p[i]){
                nv.emplace_back(i);
                for(size_t j=i;j<x+1;j+=i){
                    p[j]=false;
                }
            }
       }
       return nv;
    }

}  // namespace sieve
