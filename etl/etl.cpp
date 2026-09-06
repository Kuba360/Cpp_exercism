#include "etl.h"
#include <string>
namespace etl {

    std::map<char,int> transform(const std::map<int,std::vector<char>>& old){
        std::map<char,int> nm;
        for(auto ex:old){
            for(auto in:ex.second){
                nm.emplace(std::tolower(in),ex.first);
            }
        }
        return nm;
    }

}  // namespace etl
