#include "diamond.h"
#include <cstdlib>
namespace diamond {

std::vector<std::string> rows(char c){
    int num=(c-'A')*2+1;
    std::vector<std::string> nv(num,std::string(num,' '));
    int eq=num>>1;

    for(int i=0;i<num;i++){
        int distance=std::abs(i-eq);
        char letter='A'+(eq-distance);
            nv[i][distance]=letter;
            nv[i][num-1-distance]=letter;
    }

    return nv;
}


}  // namespace diamond
