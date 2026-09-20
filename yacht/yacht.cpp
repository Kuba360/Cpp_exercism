#include "yacht.h"
#include <algorithm>
namespace yacht {
    std::array<std::string, 12> category{"ones","twos","threes","fours","fives","sixes",
                                        "full house","four of a kind","little straight",
                                        "big straight","choice","yacht"};

    int score(std::array<int,5> a,std::string s){
        std::array<int,6> tab={0};
        
        for(auto val:a){
            tab[val-1]++;
        }
        auto ptr=std::max_element(tab.begin(),tab.end());
        int index=ptr-tab.begin();
        int max_quantity=*ptr;

        int i=0;
        for(auto c:category){
            if(c==s)break;
            i++;
        }

        if(i<6)return tab[i]*(i+1);
        int sum=0;

        switch(i){
            case 6:
                if(max_quantity==3){
                    for(auto val:tab){
                        if(val==2){
                            for(auto v:a)sum+=v;
                            return sum;
                        }
                    }
                    return 0;
                }else{
                    return 0;
                }
                break;
            case 7:
                if(max_quantity>=4){
                    return 4*(index+1);
                }else{
                    return 0;
                }
                break;
            case 8:
                if(max_quantity>1 || tab[5]){
                    return 0;
                }else{
                    return 30;
                }
                break;
            case 9:
                if(max_quantity>1 || tab[0]){
                    return 0;
                }else{
                    return 30;
                }
                break;
            case 10:
                for(auto val:a){
                    sum+=val;
                }
                return sum;
                break;
            case 11:
                if(max_quantity==5){
                    return 50;
                }else{
                    return 0;
                }
            break;
            default:
            break;
        };
        return 0;
        
}

}  // namespace yacht
