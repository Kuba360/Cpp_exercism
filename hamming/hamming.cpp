#include "hamming.h"
#include <stdexcept>
namespace hamming {

    int compute(std::string a, std::string b){
       if(a.empty() && b.empty()) return 0; 
       if(a.size()!=b.size()) throw std::domain_error("Diffrent lenghts");
       int dif=0;
       for(size_t i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            dif++;
        }
       }
        return dif;
    }

}  // namespace hamming
