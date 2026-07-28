#pragma once 
#include <string>

namespace star_map{
    enum class System{
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven{
    class Vessel{
        public:
            Vessel(std::string s,int x);
            Vessel(std::string s,int x,star_map::System c);
            int generation;
            std::string name;
            star_map::System current_system=star_map::System::Sol;
            int busters{0};
            Vessel replicate(std::string s);
            bool shoot_buster();
            void make_buster();
    };
    std::string get_older_bob(const Vessel& x,const Vessel& y);
    bool in_the_same_system(const Vessel& x,const Vessel& y);
}

