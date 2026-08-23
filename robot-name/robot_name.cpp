#include "robot_name.h"
#include <random>
#include <unordered_set>

namespace robot_name {
    std::unordered_set<std::string> used;


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> letter('A','Z');
    std::uniform_int_distribution<int> digit(0,9);

    std::string generate(){
        std::string name;
        name+=letter(gen);
        name+=letter(gen);

        for(size_t i=0;i<3;i++){
            name+='0'+digit(gen);
        }

        return name;
    }
    
    std::string robot::name() const{
        return this->r_name;
    }

    robot::robot(){
        while(true){
            std::string temp=generate();
            if(used.find(temp)==used.end()){
                this->r_name=temp;
                used.emplace(temp);
                break;
            }
        }
    }

    void robot::reset(){
        used.erase(this->r_name);
        while(true){
            std::string temp=generate();
            if(used.find(temp)==used.end()){
                this->r_name=temp;
                used.emplace(temp);
                break;
            }
        }
    }

}  // namespace robot_name
