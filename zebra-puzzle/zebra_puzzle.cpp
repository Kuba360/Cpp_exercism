#include "zebra_puzzle.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
namespace zebra_puzzle {
    
    enum Color {RED,GREEN,IVORY,YELLOW,BLUE};
    enum Nation {ENGLISH,SPANISH,UKRAINIAN,NORWEGIAN,JAPANESE};
    enum Beverage {COFFEE,TEA,MILK,JUICE,WATER};
    enum Hobby {DANCING,PAINTING,READING,FOOTBALL,CHESS};
    enum Pet {DOG,SNAIL,FOX,HORSE,ZEBRA};

    Solution solve(){
        std::vector<std::string> nations={"Eneglishman","Spaniard","Ukrainian","Norwegian",
                            "Japanese"};
        std::vector<int> house_color(5), house_nation(5),house_beverage(5),house_hobby(5),house_pet(5);
        std::iota(house_color.begin(),house_color.end(),0);
        std::iota(house_nation.begin(),house_nation.end(),0);
        std::iota(house_beverage.begin(),house_beverage.end(),0);
        std::iota(house_hobby.begin(),house_hobby.end(),0);
        std::iota(house_pet.begin(),house_pet.end(),0);

        auto is_next_to=[](int a, int b){
            return std::abs(a-b)==1;
        };


        do{
            if(house_nation[NORWEGIAN]!=0)continue;
            do{
                if(house_nation[ENGLISH]!=house_color[RED])continue;
                if(house_color[GREEN]!=house_color[IVORY]+1)continue;
                if(!is_next_to(house_nation[NORWEGIAN],house_color[BLUE]))continue;
                do{
                    if(house_color[GREEN]!=house_beverage[COFFEE])continue;
                    if(house_nation[UKRAINIAN]!=house_beverage[TEA])continue;
                    if(house_beverage[MILK]!=2)continue;
                    do{
                        if(house_color[YELLOW]!=house_hobby[PAINTING])continue;
                        if(house_beverage[JUICE]!=house_hobby[FOOTBALL])continue;
                        do{
                            if(house_nation[SPANISH]!=house_pet[DOG])continue;
                            if(house_hobby[DANCING]!=house_pet[SNAIL])continue;
                            if(!is_next_to(house_hobby[READING],house_pet[FOX]))continue;
                            if(!is_next_to(house_hobby[PAINTING],house_pet[HORSE]))continue;
                            
                            std::string water_drinker, zebra_owner;
                            for(int i=0;i<5;i++){
                                if(house_nation[i]==house_beverage[WATER]){
                                    water_drinker=nations[i];
                                }
                                if(house_nation[i]==house_pet[ZEBRA]){
                                    zebra_owner=nations[i];
                                }
                            }
                            return Solution{water_drinker,zebra_owner};

                        }while(std::next_permutation(house_pet.begin(),house_pet.end()));
                    }while(std::next_permutation(house_hobby.begin(),house_hobby.end()));
                }while(std::next_permutation(house_beverage.begin(),house_beverage.end()));
            }while(std::next_permutation(house_color.begin(),house_color.end()));
        }while(std::next_permutation(house_nation.begin(),house_nation.end()));

        return Solution{};
    }

}  // namespace zebra_puzzle
