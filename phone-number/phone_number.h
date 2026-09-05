#pragma once
#include <string>

namespace phone_number {

    class phone_number{
        public:
            phone_number(std::string x);
            std::string number();
        private:
            std::string num;
    };
}  // namespace phone_number
