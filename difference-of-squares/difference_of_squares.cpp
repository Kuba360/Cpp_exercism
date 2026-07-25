#include "difference_of_squares.h"
#include <cmath>

namespace difference_of_squares {

    int square_of_sum(int x){
        int y=0;
        while(x!=0){
            y+=x;
            x--;
        }
        return static_cast<int>(pow(y,2));
    }
    int sum_of_squares(int x){
        int y=0;
        while(x!=0){
            y+=static_cast<int>(pow(x,2));
            x--;
        }
        return y;
    }
    int difference(int x){
        return square_of_sum(x)-sum_of_squares(x);
    }

}  // namespace difference_of_squares
