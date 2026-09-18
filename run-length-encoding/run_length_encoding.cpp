#include "run_length_encoding.h"

namespace run_length_encoding {

    std::string encode(std::string s){
        if(s.size()==0)return "";
        std::string ns;
        int count=1;

        for(size_t i=1;i<=s.size();i++){
            if(i<s.size() && s[i]==s[i-1]){
                count++;
            }else{
                if(count>1){
                    ns+=std::to_string(count);
                }
                ns+=s[i-1];
                count=1;
            }
        }
        return ns;
    }
    std::string decode(std::string s){
        std::string ns;
        int num=0;
        for(size_t i=0;i<s.size();i++){
            if(std::isdigit(static_cast<unsigned char>(s[i]))){
                num=num*10+(s[i]-'0');
            }else if(std::isalpha(static_cast<unsigned char>(s[i]))|| s[i]==' '){
                if(num==0)num=1;
                while(num){
                    ns+=s[i];
                    num--;
                }
            }

        }
        return ns;
    }

}  // namespace run_length_encoding
