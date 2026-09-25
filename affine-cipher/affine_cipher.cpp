#define M 26
#include "affine_cipher.h"
#include <numeric>
#include <stdexcept>
namespace affine_cipher {

    std::string encode(std::string phrase, int a, int b){
        if(std::gcd(a,M)!=1){
            throw std::invalid_argument(" ");
        }
        std::string result;
        int num=0;
        for(const char& c:phrase){
            if(std::isdigit(c)){
                result+=c;
                num++;
                continue;
            }
            if(std::isalpha(c)){
                result+=((a*(std::tolower(c)-'a')+b)%M)+'a';
                num++;
            }
            if(num%5==0 && num!=0){
                num=0;
                result+=' ';
            }
        }
        if(!result.empty() && result.back()==' '){
            result.pop_back();
        }
        return result;
    }
    std::string decode( std::string phrase, int a, int b){
        if(std::gcd(a,M)!=1){
            throw std::invalid_argument(" ");
        }
        int mmi=0;
        for(int i=1;i<M;i++){
            if((a*i)%M==1){
                mmi=i;
                break;
            }
        }
        std::string result;
        for(const char& c:phrase){
            if(isdigit(c)){
                result+=c;
            }
            if(isalpha(c)){
                int val=(mmi*(c-'a'-b))%M;
                val=(val<0)?val+M:val;
                result+=val+'a';
            }
        }
        return result;
    }

}  // namespace affine_cipher
