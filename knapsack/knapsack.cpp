#include "knapsack.h"
#include <algorithm>
namespace knapsack {

    int maximum_value(int max,std::vector<Item> v){
        std::vector<int> val(max+1,0);

        for(auto item:v){
            for(int w=max;w>=item.weight;w--){
                val[w]=std::max(val[w],val[w-item.weight]+item.value);
            }
        }
        return val[max];
    }

}  // namespace knapsack
