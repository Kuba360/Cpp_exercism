#include "darts.h"
#include "cmath"

namespace darts {

    int score(float x, float y){
        float r=std::sqrt(std::pow(x,2)+std::pow(y,2));
        if(r>10){
            return 0;
        }else if(r>5){
            return 1;
        }else if(r>1){
            return 5;
        }else{
            return 10;
        }
    }

}  // namespace darts
