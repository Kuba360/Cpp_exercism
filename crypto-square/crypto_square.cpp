#include "crypto_square.h"
#include <cctype>
#include <cmath>
#include <iostream>

namespace crypto_square {

    std::string cipher::normalized_cipher_text(){
        if(this->x.size()==0)return "";
        std::string normal;
        for(auto c:this->x){
            if(std::isalnum(static_cast<unsigned char>(c))){
                normal+=static_cast<unsigned char>(std::tolower(c));
            }
        }
        int len=normal.size();
        std::cout<<len<<std::endl;
        if(len==0)return "";
        int c=std::ceil(std::sqrt(len));
        int r=std::ceil(static_cast<double>(len)/c);
        std::cout<<r<<" "<<c<<std::endl;

        std::string result;
        int size=0;
        int pos=0;
        for(int i=0;i<c;i++){
            pos=i;
            for(int j=0;j<r;j++){
                if(pos<len){
                    result+=normal[pos];
                }else{
                    result+=' ';
                }
                size++;
                if(size%r==0 && size!=r*c)result+=' ';
                pos+=c;
            }
        }
        return result;
    }

}  // namespace crypto_square
