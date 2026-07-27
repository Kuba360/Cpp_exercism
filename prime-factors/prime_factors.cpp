#include "prime_factors.h"

namespace prime_factors {

    std::vector<long long> of(long long x){
        std::vector<long long> nv;
        int n=2;
        while(x!=1){
            while(x%n==0){
                nv.emplace_back(n);
                x/=n;
            }
            n++;
        }
        return nv;
    }

}  // namespace prime_factors
