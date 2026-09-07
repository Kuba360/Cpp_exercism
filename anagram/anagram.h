#pragma once
#include <string>
#include <vector> 
#include <map>

namespace anagram {

    class anagram{
        public:
            anagram(std::string s);
            std::vector<std::string> matches(std::vector<std::string> candidates);
        private:
           std::string target;
           std::map<char,int> t_map;
    };

}  // namespace anagram
