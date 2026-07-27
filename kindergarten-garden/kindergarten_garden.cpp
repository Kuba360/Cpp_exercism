#include "kindergarten_garden.h"

namespace kindergarten_garden {
    Plants convert(char c){
        switch(c){
            case 'R':
                return Plants::radishes;
            case 'C':
                return Plants::clover;
            case 'G':
                return Plants::grass;
            case 'V':
                return Plants::violets;
            default:
                return Plants::grass;
        }
    }
    std::array<std::string,12> names{
        "Alice","Bob","Charlie","David","Eve","Fred","Ginny","Harriet",
        "Ileana","Joseph","Kincaid","Larry"};

    std::array<Plants,4> 
    plants(std::string garden,std::string name)
    {
        size_t row_size=(garden.size()-1)/2;
        size_t index=0;
        for(size_t i=0;i<names.size();i++){
            if(names[i]==name){
                index=i;
                break;
            }
        }
        int place=index*2;
        std::array<Plants,4> ar{
        ar[0]=convert(garden[place]),
        ar[1]=convert(garden[place+1]),
        ar[2]=convert(garden[place+row_size+1]),
        ar[3]=convert(garden[place+row_size+2])
        };
        return ar;
    }

    
}  // namespace kindergarten_garden
