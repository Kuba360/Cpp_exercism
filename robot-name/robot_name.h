#pragma once
#include <string>
namespace robot_name {
    std::string generate();

    class robot{
        
        public:
            robot();
            std::string name() const;
            void reset();
        private:
            std::string r_name;
    };

}  
