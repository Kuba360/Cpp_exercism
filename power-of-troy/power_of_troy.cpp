#include "power_of_troy.h"

namespace troy {


void give_new_artifact(human& h,std::string& s){
    h.possession=std::make_unique<artifact>(s);
}
void exchange_artifacts(std::unique_ptr<artifact>& p, std::unique_ptr<artifact>& p2){
    auto p3=std::move(p);
    p=std::move(p2);
    p2=std::move(p3);
}
void manifest_power(human& h, const std::string& s){
    h.own_power=std::make_shared<power>(s);
}
void use_power(human& h, human& h2){
    h2.influenced_by=h.own_power;
}
int power_intensity(human& h){
    if(h.own_power==nullptr){
        return 0;
    }else{
        return h.own_power.use_count();
    }
}

}  // namespace troy
