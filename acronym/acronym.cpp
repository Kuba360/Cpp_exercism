#include "acronym.h"
#include <cctype>
namespace acronym {

    std::string acronym(std::string s){
        std::string ns;
        
        for(int i=0;i<(int)s.size();i++){
            if(ns.empty() && std::isalpha(s[i])){
                ns+=std::toupper(s[i]);
            }

            if(i-1>=0 && std::isalpha(s[i]) && (std::isspace(s[i-1]) || s[i-1]=='-' 
                || s[i-1]=='_') ){
                ns+=std::toupper(s[i]);
            }
        }
        return ns;
    }

}  // namespace acronym
