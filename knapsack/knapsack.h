#pragma once
#include <vector>
namespace knapsack {

struct Item {
    int weight;
    int value;
};
    int maximum_value(int max,std::vector<Item> v);

}  // namespace knapsack
