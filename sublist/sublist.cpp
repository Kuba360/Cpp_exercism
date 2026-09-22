#include "sublist.h"
#include <algorithm>
namespace sublist {

    bool is_sublist(std::vector<int> sub, std::vector<int> sup){
        if(sub.empty())return true;
        if(sub.size()>sup.size())return false;
        return std::search(sup.begin(),sup.end(),sub.begin(),sub.end())!=sup.end();
    }
    List_comparison sublist(std::vector<int> a, std::vector<int> b){
        if(a==b){
            return List_comparison::equal;
        }
        if(is_sublist(a,b)){
            return List_comparison::sublist;
        }
        if(is_sublist(b,a)){
            return List_comparison::superlist;
        }
        return List_comparison::unequal;
    }

}  // namespace sublist
