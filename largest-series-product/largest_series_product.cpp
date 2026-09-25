#include "largest_series_product.h"
#include <stdexcept>
namespace largest_series_product {

    int largest_product(std::string sequence, int span){
        int len=sequence.size();
        if(len<span || sequence.empty() || span<1) throw  std::domain_error(" ");
        int largest_prod=0;
        int curr=0;
        for(int i=0;i<=len-span;i++){
            curr=one_serie(sequence.substr(i,span));
            if(curr<0) throw std::domain_error(" ");
            largest_prod=(curr>largest_prod)?curr:largest_prod;
        }
        return largest_prod;
    }

    int one_serie(std::string input){
        int output=1;
        for(char &c:input){
            if(!std::isdigit(c))return -1;
            output*=(c-'0');
        }
        return output;
    }

}  // namespace largest_series_product
