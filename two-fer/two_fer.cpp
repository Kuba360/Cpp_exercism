#include "two_fer.h"
#include <format>


namespace two_fer {

    std::string two_fer(const std::string s){
            return "One for "+s+", one for me.";
    }
    std::string two_fer(){
        return  "One for you, one for me.";
    }

}  // namespace two_fer
