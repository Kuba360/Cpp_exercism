#include "atbash_cipher.h"
#include <algorithm>
#include <cmath>


namespace atbash_cipher {

    std::string encode(std::string s){
        std::string ns;
        size_t l=s.length();
        size_t ne=0;
        for(size_t i=0;i<l;i++){
            if(!std::isalpha(s[i]) && !std::isdigit(s[i])){continue;}
            if(std::isdigit(s[i])){
                ns.push_back(s[i]);
            }else if(std::isalpha(s[i])){
                if(std::tolower(s[i])>'m'){
                    ns.push_back(('z'-std::tolower(s[i]))+'a');
                }else{
                    ns.push_back(('a'-std::tolower(s[i]))+'z');
                }
            }
            ne++;
            if(ne%5==0){
                ns.push_back(' ');
            }
        }
        if (!ns.empty() && ns.back() == ' ') {
            ns.pop_back();
        }
        return ns;
    }
    std::string decode(std::string s){
        size_t l=s.length();
        std::string ns;
        for(size_t i=0;i<l;i++){
            if(std::isspace(s[i])){continue;}
            if(std::isdigit(s[i])){
                ns.push_back(s[i]);
            }else if(std::isalpha(s[i])){
                if(s[i]>'m'){
                    ns.push_back(('z'-s[i])+'a');
                }else{
                    ns.push_back(('a'-s[i])+'z');
                }
            }
        }
        return ns;
    }

}  // namespace atbash_cipher
