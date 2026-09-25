#include "pig_latin.h"
#include <sstream>
namespace pig_latin {

    std::string translate(std::string s){
        std::stringstream ss(s);
        std::string word;
        std::string output;
        while(ss>>word){
            if(!output.empty()){
                output+=' ';
            }
            output+=translate_word(word);
        }
        return output;
    }

    std::string translate_word(std::string word){
       std::size_t pos_v=word.find_first_of("aeiou");
       if(pos_v==0 || word.substr(0,2)=="xr" || word.substr(0,2)=="yt"){
        return word+"ay";
       }
       std::size_t pos_qu=word.find("qu");
       std::size_t pos_y=word.find("y");

       if(pos_qu!=std::string::npos && (pos_v==std::string::npos || pos_qu<pos_v)){
            return word.substr(pos_qu+2)+word.substr(0,pos_qu+2)+"ay";
       }

       if(pos_y!=std::string::npos && pos_y>0){
            if(pos_v==std::string::npos || pos_y<pos_v){
                return word.substr(pos_y)+word.substr(0,pos_y)+"ay";
            }
       }

        if(pos_v!=std::string::npos){
            return word.substr(pos_v)+word.substr(0,pos_v)+"ay";
        }
        return word+"ay";
    }



}  // namespace pig_latin
