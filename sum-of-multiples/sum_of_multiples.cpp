#include "sum_of_multiples.h"
#include <set>
namespace sum_of_multiples {

    long long to(std::vector<int> v,int l){
        std::set<int> s;
        for(auto& c:v){
            int x=c;
            while(x<l){
                s.emplace(x);
                x+=c;
            }
        }
        long long a=0;
        for(auto& b:s){
            a+=b;
        }
        return a;
    }

}  // namespace sum_of_multiples
