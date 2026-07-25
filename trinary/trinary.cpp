#include "trinary.h"
#include <cmath>
namespace trinary {

    int to_decimal(std::string s){
        size_t l=s.length();
        int decimal=0;
        for(int i=l-1;i>=0;i--){
            if(s[i]<'0' || s[i]>'9') return 0;
            int digit =s[i]-'0';
            decimal+=digit*static_cast<int>(pow(3,(l-1)-i));
        }
        return decimal;
    }

}  // namespace trinary
