#include "anagram.h"
#include <cctype>
namespace anagram {

    anagram::anagram(std::string s):target(s){
        for(char &c:target){
            c=std::tolower(c);
        }
        for(char c:s){
            t_map[std::tolower(c)]++;
        }
    };

    std::vector<std::string> anagram::matches(std::vector<std::string> candidates){
        std::vector<std::string> nv;
        std::map<char,int> nm;
        for(auto &can:candidates){
            std::string lower=can;


            for(char &c:lower){
                c=std::tolower(c);
                nm[c]++;
            }

            if(nm==t_map && target!=lower){
                nv.push_back(can);
            }

            nm.clear();
        }
        return nv;
    }

}  // namespace anagram
