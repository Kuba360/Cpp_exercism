#include "armstrong_numbers.h"
#include <cmath>
#include <vector>



namespace armstrong_numbers {

    bool is_armstrong_number(unsigned int x){
        unsigned int temp=x;
        std::vector<int> v;
        unsigned int y=0;
        while(temp>0){
            int digit=temp%10;
            v.push_back(digit);
            temp/=10;
        }
        size_t s=v.size();
        for(size_t i=0;i<s;i++){
            y+=std::round(std::pow(v[i],s));
        }

        return y==x;
    }

}  // namespace armstrong_numbers
