#include "isbn_verifier.h"
#include <cctype>
namespace isbn_verifier {

    bool is_valid(const std::string &s){
        std::string ns;
        for(auto c:s){
            if(c=='-')continue;
            if(std::isdigit(static_cast<unsigned char>(c)) || c=='X'){
                ns+=c;
            }else{
                return false;
            }

        }

        if(ns.size()!=10)return false;

        int sum=0;
        int val=10;
        for( auto c:ns){
            if(c=='X'){
                if(val==1){
                    sum+=10;
                    break;
                }else{
                    return false;
                }
            }
            sum+=(c-'0')*val;
            val--;
        }
        return sum%11==0;

    }

}  // namespace isbn_verifier
