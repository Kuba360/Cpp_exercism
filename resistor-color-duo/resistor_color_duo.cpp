#include "resistor_color_duo.h"
#include <array>
namespace resistor_color_duo {
    std::array<std::string,10> colors_tab={"black","brown","red","orange","yellow","green",
                                "blue","violet","grey","white"};

    int value(std::vector<std::string> v){
        int val=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<10;j++){
                if(colors_tab[j]==v[i]){
                    val=val*10+j;
                    break;
                }
            }
        }
        return val;
    }

}  // namespace resistor_color_duo
