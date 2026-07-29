#include "alphametics.h"
#include <vector>
#include <sstream>
#include <algorithm>


namespace alphametics {

std::optional<std::map<char,int>> solve(std::string s){
    s.erase(std::remove(s.begin(),s.end(),' '),s.end());
    size_t equal_index=s.find("==");
    std::string raw_input=s.substr(0,equal_index);
    std::string output=s.substr(equal_index+2);

    std::vector<std::string> input;
    std::stringstream ss(raw_input);
    std::string item;
    while(std::getline(ss,item,'+')){
        input.emplace_back(item);
    }
    

    std::optional<std::map<char,int>> result;

    return result;
}
// TODO: add your solution here

}  // namespace alphametics
