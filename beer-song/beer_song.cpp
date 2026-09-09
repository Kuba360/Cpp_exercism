#include "beer_song.h"

namespace beer_song {

    std::string verse(const int &b){
        std::string ns;
        std::string beers=std::to_string(b);
        std::string n_beers=std::to_string(b-1);
        if(b>2 && b<100){
            ns+=beers+" bottles of beer on the wall, " + beers+" bottles of beer.\n";
            ns+="Take one down and pass it around, " + (n_beers)+" bottles of beer on the wall.\n";
        }else if(b==2){
            ns+=beers+" bottles of beer on the wall, " + beers+" bottles of beer.\n";
            ns+="Take one down and pass it around, 1 bottle of beer on the wall.\n";
        }else if(b==1){
            ns+=beers+" bottle of beer on the wall, " + beers+" bottle of beer.\n";
            ns+="Take it down and pass it around, no more bottles of beer on the wall.\n";
        }else if(b==0){
            ns+="No more bottles of beer on the wall, no more bottles of beer.\n";
            ns+="Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        }
        return ns;
    }

    std::string sing(int b){
        std::string ns;
        while(b>=0){
            ns+=verse(b);
            b--;
            if(b>=0)ns+="\n";
        }
        return ns;
    }
    std::string sing(int b,int l){
        std::string ns;
        while(l>0 && b>=0){
            ns+=verse(b);
            l-=2;
            if(l>0)ns+="\n";
            b--;
        }
        return ns;
    }

}  // namespace beer_song
