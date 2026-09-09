#include "food_chain.h"
#include <array>

namespace food_chain {
    std::array<std::string,8> a={"fly","spider","bird","cat","dog","goat","cow","horse"};

    std::string one_v(int x){
        std::string ns;
        switch(x){
            case 7:
                ns+="I don't know how she swallowed a cow!\n";
                break;
            case 6:
                ns+="Just opened her throat and swallowed a goat!\n";
                break;
            case 5:
                ns+="What a hog, to swallow a dog!\n";
                break;
            case 4:
                ns+="Imagine that, to swallow a cat!\n";
                break;
            case 3:
                ns+="How absurd to swallow a bird!\n";
                break;
            case 2:
                ns+="It wriggled and jiggled and tickled insider her.\n";
                break;
            default: 
                ns+=" ";
        };
        return ns;
    }

    std::string verse(int x){
        std::string ns;
        bool one=true;
        int y=x;
        if(x==8){
            return "I know an old lady who swallowed a horse.\nShe's dead, of course!.\n";
        }

        while(y>0){
            if(y==x) ns+="I know an old lady who swallowed a " + a[y-1]+ ".\n";
            if(one && y>1){
                ns+=one_v(y);
                one=false;
            }

            if(y==3){
                ns+="She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n";
            }else if(y>1 && y<8){
                ns+="She swallowed the "+a[y-1]+"to catch the " +a[y-2]+ ".\n";
            }

            if(y==1) ns+="I don't know why she swallowed the fly. Perhaps she'll die.\n";
            y--;
        }
        return ns;
    }
    std::string verses(int begin, int end){
        std::string ns;
        while(begin<=end){
            ns+=verse(begin);
            ns+="\n";
            begin++;
        }
        return ns;
    }
    std::string sing(){
        return verses(1,8);
    }

}  // namespace food_chain
