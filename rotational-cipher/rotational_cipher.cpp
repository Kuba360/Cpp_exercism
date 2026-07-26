#include "rotational_cipher.h"

namespace rotational_cipher {

    std::string rotate(std::string s, int x){
        std::string ns;
        for(char &c: s){
            if(!std::isalpha(c)){
                ns+=c;
                continue;
            }else{
                if(c>96){
                    unsigned char nc=c+x;
                    if(nc>122) nc-=26;
                    ns+=nc;
                }else{
                    unsigned char nc=c+x;
                    if(nc>90) nc-=26;
                    ns+=nc;
                }
            }

        }
        return ns;
    }

}  // namespace rotational_cipher
