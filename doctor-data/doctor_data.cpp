#include "doctor_data.h"


heaven::Vessel::Vessel(std::string s,int x):generation(x),name(s){}

heaven::Vessel::Vessel(std::string s,int x, star_map::System c):
generation(x),name(s),current_system(c){}

heaven::Vessel heaven::Vessel::replicate(std::string s){
    heaven::Vessel nv(s,this->generation+1);
    return nv;
}


void heaven::Vessel::make_buster(){
    this->busters++;
}
bool heaven::Vessel::shoot_buster(){
    if(this->busters>0){
        this->busters--;
        return true;
    }else{
        return false;
    }
}
std::string heaven::get_older_bob(const heaven::Vessel& x,const heaven::Vessel& y){
    if(x.generation>y.generation){
        return y.name;
    }else{
        return x.name;
    }
}
bool heaven::in_the_same_system(const heaven::Vessel& x,const heaven::Vessel& y){
    return x.current_system==y.current_system;
}
