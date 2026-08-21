#pragma once
#include <utility>
namespace queen_attack {

    class chess_board{
        public:
            chess_board(const std::pair<int,int>& p1,
                const std::pair<int,int>& p2);

            std::pair<int,int> white() const;
            std::pair<int,int> black() const;
            bool can_attack() const;
        private:
            std::pair<int,int> w;
            std::pair<int,int> b;
    };

}  // namespace queen_attack
