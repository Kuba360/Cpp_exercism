#include "dnd_character.h"
#include <cmath>
#include <random>
#include <algorithm>
#include <array>

namespace dnd_character {
    std::array<int,4> ar;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> d(1,6);

    int ability(){
        return d(gen);
    }

    int modifier(int x){
        return std::floor((x-10)/2.0);
    }
    Character::Character(){
        rolling();
        strength=ar[1]+ar[2]+ar[3];
        rolling();
        dexterity=ar[1]+ar[2]+ar[3];
        rolling();
        constitution=ar[1]+ar[2]+ar[3];
        rolling();
        intelligence=ar[1]+ar[2]+ar[3];
        rolling();
        wisdom=ar[1]+ar[2]+ar[3];
        rolling();
        charisma=ar[1]+ar[2]+ar[3];
        hitpoints=modifier(constitution)+10;
    }
    void rolling(){
        ar[0]=ability();
        ar[1]=ability();
        ar[2]=ability();
        ar[3]=ability();
        std::sort(ar.begin(),ar.end());
    }


}  // namespace dnd_character
