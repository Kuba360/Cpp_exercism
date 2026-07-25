#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(std::string x){
        std::string y="";
        for(int i=x.length()-1;i>=0;i--){
            y+=x[i];
        }
        return y;
    }

}  // namespace reverse_string
