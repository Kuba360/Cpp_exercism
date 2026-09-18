#include "scrabble_score.h"
#include <array>
#include <cctype>
namespace scrabble_score {
    std::array<int,26> points={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int score(std::string s){
        int sum=0;
        for(auto c:s){
            sum+=points[std::tolower(c)-'a'];
        }
        return sum;
    }

}  // namespace scrabble_score
