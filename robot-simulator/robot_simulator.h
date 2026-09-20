#pragma once
#include <utility>
#include <string>


namespace robot_simulator {
    typedef enum{
        NORTH=0,
        EAST=1,
        SOUTH=2,
        WEST=3
    }Bearing;

    class Robot{
        public:
            Robot();
            Robot(std::pair<int,int> pos,Bearing bear);
            std::pair<int,int> get_position()const;
            Bearing get_bearing()const;
            void turn_right();
            void turn_left();
            void advance();
            void execute_sequence(std::string s);
        private:
            int x,y;
            Bearing b;
    };

}  
