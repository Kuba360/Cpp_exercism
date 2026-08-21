#include "nth_prime.h"
#include <stdexcept>
#include <vector>


namespace nth_prime {
    
    const int limit=105000;
    int  nth(int x){
        if(x<=0){
            throw std::domain_error("bad input");
        }
        int count=0;
        std::vector<bool> tab(limit+1,true);
        tab[0]=tab[1]=false;
        for(int i=2;i<=limit;i++){
            if(tab[i]){
                count++;
                if(count==x) return i;
                for(int j=i+i;j<limit+1;j+=i){
                    tab[j]=false;
                }
            }
        }
        return 0;
   }

}  // namespace nth_prime
