#include "secret_handshake.h"
#include <array>
#include <algorithm>
namespace secret_handshake {

    std::vector<std::string> commands(int x){
        std::vector<std::string> s;
        std::array<bool,5> tab{false,false,false,false,false};
        std::array<std::string,4> text{"wink","double blink","close your eyes","jump"};
        int n=0;
        while(x!=0){
            if(x&1){
                tab[n]=true;
            }
            x>>=1;
            n++;
        }
        for(int i=0;i<4;i++){
            if(tab[i]){
                s.emplace_back(text[i]);
            }
        }
        
        if(tab[4]){
            std::reverse(s.begin(),s.end());
        }

        return s;
    }

}  // namespace secret_handshake
