#include "luhn.h"
#include <algorithm>

namespace luhn {

    bool valid(std::string s){
        s.erase(std::remove_if(s.begin(),s.end(),[](unsigned char c) {
            return std::isspace(c); }),s.end());
        bool isnotdigit=std::any_of(s.begin(),s.end(),[](char x){
            return !isdigit(x);});
        if(s.length()<=1 || isnotdigit){return false;}
        
        int sum=0;
        size_t n=1;
        for (int i=s.length()-1;i>=0;i--){
            if(n%2==0){
                int digit=2*(s[i]-'0');
                if(digit>9){digit-=9;}
                sum+=digit;
            }else{
                sum+=(s[i]-'0');
            }
            n++;
        }
        return sum%10==0;
    }

}  // namespace luhn
