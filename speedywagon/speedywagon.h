#pragma once

#include <string>
#include <vector>
#include <array>

namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

int uv_light_heuristic(std::vector<int>* data_array);


bool connection_check(pillar_men_sensor* sensor);
int activity_counter(pillar_men_sensor* ar,size_t s);
bool alarm_control(pillar_men_sensor* ar);
bool uv_alarm(pillar_men_sensor* ar);

}  // namespace speedywagon
