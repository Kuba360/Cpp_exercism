#include "series.h"
#include <stdexcept>

namespace series {

    std::vector<std::string> slice(std::string s, int l){
        int len=static_cast<int>(s.size());
        if(l<1 || l>len || s.empty()) throw std::domain_error(" ");
        
        std::vector<std::string> nv;
        int begin=0;
        while(begin+l<=len){
            nv.push_back(s.substr(begin,l));
            begin++;
        }
        return nv;
    }

}  // namespace series
