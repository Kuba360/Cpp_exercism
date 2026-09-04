#include "say.h"
#include <stdexcept>
#include <array>
#include <vector>
#include <cstdlib>
#include <algorithm>

namespace say {
    const static std::array<std::string,10> a1{"zero","one","two","three","four","five",
                                 "six","seven", "eight","nine"};
    const static std::array<std::string,10> a2{"ten","eleven","twelve","thirteen","fourteen","fifteen"
                                    ,"sixteen","seventeen","eighteen","nineteen"};
    const static std::array<std::string,8> a3{"twenty","thirty","forty","fifty","sixty","seventy",
                                    "eighty","ninety"};
    const static std::array<std::string,4> a4{"hundred","thousand","million","billion"};

    std::string one_d(int x){
        return a1[x];
    }

    std::string two_d(int x){
        if(x < 10) return one_d(x);
        if(x < 20) return a2[x - 10];
        int t = x / 10, o = x % 10;
        return o ? a3[t - 2] + "-" + one_d(o) : a3[t - 2];
    }

    std::string three_d(int x){
        int h = x / 100, rest = x % 100;
        if(h == 0) return two_d(rest);
        std::string result = one_d(h) + " " + a4[0];
        if(rest) result += " " + two_d(rest);
        return result;
    }


 std::string in_english(long long x){
        if(x > 999'999'999'999LL || x < 0) throw std::domain_error(" ");
        if(x == 0) return "zero";

        int groups[4] = {0,0,0,0};
        int n = 0;
        while(x){
            groups[n++] = static_cast<int>(x % 1000);
            x /= 1000;
        }

        std::string result;
        result.reserve(64);

        for(int i = n - 1; i >= 0; --i){
            if(groups[i] == 0) continue;
            if(!result.empty()) result += " ";
            result += three_d(groups[i]);
            if(i > 0) result += " " + a4[i];
        }
        return result;
    }


}  // namespace say
