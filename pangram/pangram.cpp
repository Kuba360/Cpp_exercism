#include "pangram.h"
#include <algorithm>
namespace pangram {

    bool is_pangram(std::string s){
        if(s.empty()) return false;
        bool tab[26]={false};
        for(auto c:s){
            if(!isalpha(c)) continue;
            int index=tolower(c)-'a';
            if(!tab[index]) tab[index]=true;
        }
        if(std::all_of(std::begin(tab),std::end(tab),[](bool x){return x;})){
            return true;
        }
        return false;
    }

}  // namespace pangram
