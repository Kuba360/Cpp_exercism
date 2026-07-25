#include "bob.h"
#include <algorithm>

namespace bob {

    std::string hey(std::string x){
        if(x.empty()){return "Fine. Be that way!";}
        bool whitespace=std::all_of(x.begin(),x.end(),[](char c){
            return std::isspace(c);
        });
        bool question=false;
        if(!whitespace){
            size_t last = x.find_last_not_of(" \t\n\r");
            question=x[last]=='?';
        }
        bool yell=std::all_of(x.begin(),x.end(),[](char c){
            return !std::isalpha(c) || std::isupper(c);
        });
        bool has_letter = std::any_of(x.begin(), x.end(), [](char c) {
            return std::isalpha(c);
        });
        bool YELL=yell&&has_letter;

        if(YELL&&question){
            return "Calm down, I know what I'm doing!";
        }else if(YELL){
            return "Whoa, chill out!";
        }else if(question){
            return "Sure.";
        }else if(whitespace){
            return "Fine. Be that way!";
        }else{
            return "Whatever.";
        }
    }

}  // namespace bob
