#include "phone_number.h"
#include <algorithm>
#include <stdexcept>

namespace phone_number {

// TODO: add your solution here
    phone_number::phone_number(std::string x){
        x.erase(std::remove_if(x.begin(),x.end(),[](char c){
            return !isdigit(c);
        }),x.end());
        size_t l=x.size();
        
        if(l>11 || l<10){
            throw std::domain_error(" ");
        }
        
        if(l==11){
            if(x[0]=='1'){
                x.erase(x.begin());
            }else{
                throw std::domain_error(" ");
            }
        }

        if(x[0]=='0'||x[0]=='1' || x[3]=='0'||x[3]=='1') throw std::domain_error("");

        this->num=x;
    }
    std::string phone_number::number(){
        return this->num;
    }
}  // namespace phone_number
