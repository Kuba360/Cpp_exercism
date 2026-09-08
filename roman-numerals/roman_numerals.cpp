#include "roman_numerals.h"
#include <map>
#include <array>
#include <vector>
#include <algorithm>

namespace roman_numerals {

    std::map<int,std::string,std::greater<int>> roman={
        {1000,"M"},
        {900,"CM"},
        {500,"D"},
        {400,"CD"},
        {100,"C"},
        {90,"XC"},
        {50,"L"},
        {40,"XL"},
        {10,"X"},
        {9,"IX"},
        {5,"V"},
        {4,"IV"},
        {1,"I"},
    };

    std::string convert(int x){
        std::string ro;
        for(auto  [value, key]:roman){
            while(x>=value){
                x-=value;   
                ro+=key;
            }
        }
        return ro;
    }
    
}  // namespace roman_numerals
