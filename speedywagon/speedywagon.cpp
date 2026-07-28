#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* sensor){
    return sensor==nullptr? false:true;
}
int activity_counter(pillar_men_sensor* ar,size_t s){
    int n=0;
    for(size_t i=0;i<s;i++){
        n+=(ar+i)->activity;
    }
    return n;
}
bool alarm_control(pillar_men_sensor* ar){
    if(!ar){
        return false;
    }else{
        return ar->activity>0?true:false;
    }
}

bool uv_alarm(pillar_men_sensor* ar){
    if(ar==nullptr) return false;
    return uv_light_heuristic(&ar->data)>ar->activity;
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
