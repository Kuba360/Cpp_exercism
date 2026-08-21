#include "queen_attack.h"
#include <stdexcept>
#include <cmath>

namespace queen_attack {

    std::pair <int,int> chess_board::white()const {
        return this->w;
    }
    std::pair <int,int> chess_board::black()const {
        return this->b;
    }
    chess_board::chess_board(const std::pair<int,int>& p1,
            const std::pair<int,int>& p2){
                if((p1.first>7||p1.first<0)||(p2.first>7||p2.first<0)||
                    (p1.second>7||p1.second<0)||(p2.second>7||p2.second<0)||
                    (p1.first==p2.first&&p1.second==p2.second)){
                        throw std::domain_error("bad input");
                    }
                this->w=p1;
                this->b=p2;
            }
    bool chess_board::can_attack()const {
        return w.first==b.first||w.second==b.second ||
            std::abs(w.first-b.first)==std::abs(w.second-b.second);
    }


}  // namespace queen_attack
