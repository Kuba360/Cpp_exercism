#include "raindrops.h"

namespace raindrops {

    std::string convert(int x){
        std::string sound;
        if(x%3!=0 && x%5!=0 && x%7!=0){
            sound= std::to_string(x);
        }else{
            if(x%3==0){
                sound+="Pling";
            }   
            if(x%5==0){
                sound+="Plang";
            }   
            if(x%7==0){
                sound+="Plong";
            }   
        }
        return sound;
    }

}  // namespace raindrops
