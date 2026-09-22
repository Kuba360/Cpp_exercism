#include "all_your_base.h"
#include <stdexcept>
#include <algorithm>
namespace all_your_base {

    std::vector<unsigned int> convert(unsigned int input_base, std::vector<unsigned int> v,unsigned int output_base){
        if(input_base<2 || output_base<2)throw std::invalid_argument(" ");
        std::vector<unsigned int> outv;
        if(v.empty()){
            return outv;
        }
        unsigned int number=0;
        for(auto d:v){
            if(d>=input_base)throw std::invalid_argument(" ");
            number=number*input_base+d;
        }
        while(number){
            outv.emplace_back(number%output_base);
            number/=output_base;
        }
        std::reverse(outv.begin(),outv.end());
        return outv;
    }

}  // namespace all_your_base
