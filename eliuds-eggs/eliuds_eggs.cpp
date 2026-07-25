#include "eliuds_eggs.h"

namespace chicken_coop {

    int positions_to_quantity(int x){
        int n=0;
        while(x>0){
            if(x&1){
                n++;
            }
            x>>=1;
        }
        return n;
    }

}  // namespace chicken_coop
