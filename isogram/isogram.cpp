#include "isogram.h"
#include <array>
#include <cctype>
namespace isogram {

    bool is_isogram(std::string s){
        std::array<bool,26> ar={0};
        int index=0;
        for(auto c:s){
            if(isalpha(c)){
                index=std::tolower(c)-'a';
                if(ar[index])return false;
                ar[index]=true;
            }
        }
        return true;
    }

}  // namespace isogram
