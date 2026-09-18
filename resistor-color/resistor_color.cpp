#include "resistor_color.h"
#include <array>
namespace resistor_color {
    std::array<std::string,10> colors_tab={"black","brown","red","orange","yellow","green",
                                "blue","violet","grey","white"};

    int color_code(std::string s){
        for( int i=0;i<10;i++){
            if(colors_tab[i]==s)return i;
        }
        return -1;
    }

    std::vector<std::string> colors(){
        std::vector<std::string> nv;
        for(int i=0;i<10;i++){
            nv.emplace_back(colors_tab[i]);
        }
        return nv;
    }

}  // namespace resistor_color
