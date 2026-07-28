#include "lasagna_master.h"
#include <algorithm>

namespace lasagna_master {
    

    int preparationTime(std::vector<std::string> s, int l){
        return s.size()*l;
    }
    amount quantities(std::vector<std::string> s){
        amount am;
        size_t n=std::count(s.begin(),s.end(),"noodles");
        size_t ns=std::count(s.begin(),s.end(),"sauce");
        am.noodles=n*50;
        am.sauce=ns*0.2;
        return am;
    }
    void addSecretIngredient(
        std::vector<std::string>& mylist,
        const std::vector<std::string>& firendlist){
            mylist.back()=firendlist.back();
        }

    std::vector<double> scaleRecipe(const std::vector<double>& quantities, int x){
        std::vector<double> nv;
        for (size_t i=0;i<quantities.size();i++){
            nv.emplace_back()=quantities[i]/2*x;
        }
        return nv;
    }


    void addSecretIngredient(std::vector<std::string>& mylist,
        const std::string& ai){
            mylist.back()=ai;
        }
// TODO: add your solution here

}  // namespace lasagna_master
