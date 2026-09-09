#include "binary.h"
#include <cctype>
namespace binary {

    int convert(std::string s){
        int x=0;
        for(auto bit:s){
            if(!std::isdigit(bit))return 0;
            x<<=1;
            if(bit=='1'){
                x+=1;
            }
        }
        return x;
    }

}  // namespace binary
