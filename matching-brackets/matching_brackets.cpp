#include "matching_brackets.h"
#include <algorithm>
#include <vector>
#include <map>

namespace matching_brackets {

    bool check(std::string s){
        s.erase(std::remove(s.begin(),s.end(),' '),s.end());
        std::vector<char> stack;
        std::map<char,char> brackets={
            {'{','}'},
            {'[',']'},
            {'(',')'}};
        for(const char& c:s){
            for(auto& a:brackets){
                if(a.first==c){
                    stack.emplace_back(c);
                    break;
                }else if(a.second==c){
                    if(stack.size()==0) return false;
                    if(brackets.at(stack.back())==a.second){
                        stack.pop_back();
                    }else{
                        return false;
                    }
                    break;
                }
            }
        }
        return stack.size()==0;
    }

}  // namespace matching_brackets
