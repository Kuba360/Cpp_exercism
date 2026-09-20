#include "robot_simulator.h"

namespace robot_simulator {

    Robot::Robot():x(0),y(0),b(NORTH){};
    Robot::Robot(std::pair<int,int> pos,Bearing bear){
        x=pos.first;
        y=pos.second;
        b=bear;
    }
    std::pair<int,int> Robot::get_position()const{
        return {x,y};
    }
    Bearing Robot::get_bearing()const{
        return b;
    }
    void Robot::turn_right(){
        b=static_cast<Bearing>((b+1)%4);
    }
    void Robot::turn_left(){
        b=static_cast<Bearing>((b+3)%4);
    }
    void Robot::advance(){
        switch(b){
            case NORTH:
                y++;
                break;
            case EAST:
                x++;
                break;
            case SOUTH:
                y--;
                break;
            case WEST:
                x--;
                break;
            default:
                break;
        }
    }
    void Robot::execute_sequence(std::string s){
        for(auto command:s){
            if(command=='R'){
                turn_right();
            }else if(command=='L'){
                turn_left();
            }else if(command=='A'){
                advance();
            }
        }
    }

}  // namespace robot_simulator
