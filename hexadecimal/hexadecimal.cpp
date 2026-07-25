#include "hexadecimal.h"
#include <algorithm>
#include <cmath>

namespace hexadecimal {

    int convert(std::string s){
        size_t l=s.length();
        int sum=0;
        for(int i=l-1;i>=0;i--){
            if((!isdigit(s[i])&&s[i]<'a')||(!isdigit(s[i])&&s[i]>'f')){
                return 0;
            }
            if(isdigit(s[i])){
                sum+=(s[i]-'0')*static_cast<int>(pow(16,l-1-i));
            }else{
                //87 because 'a' is equal to 97 
                // so if s[i]='a' then it gives value 97-87=10
                sum+=(s[i]-87)*static_cast<int>(pow(16,l-1-i));
            }

        }
        return sum;
    }

}  // namespace hexadecimal
