#include "allergies.h"
#include <vector>

namespace allergies {
    
    static const std::vector<std::pair<std::string, int>> a_v={
        {"eggs",1},
        {"peanuts",2},
        {"shellfish",4},
        {"strawberries",8},
        {"tomatoes",16},
        {"chocolate",32},
        {"pollen",64},
        {"cats",128}
    };


            allergy_test::allergy_test(int y){
                int index=0;
                while(index<=7){
                    if(y&1){
                        this->a.emplace(a_v[index].first);
                    }
                    index++;
                    y>>=1;
                }
                
            }
            bool allergy_test::is_allergic_to(std::string s){
                if(a.find(s)!=a.end()){
                    return true;
                }else{
                    return false;
                }
            }
            std::unordered_set<std::string> allergy_test::get_allergies(){
                return a;
            }
     
        

}  // namespace allergies
