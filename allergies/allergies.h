#pragma once
#include <string>
#include <unordered_set>

namespace allergies {

    class allergy_test{
        public:
            allergy_test(int x);
            bool is_allergic_to(std::string s);
            std::unordered_set<std::string> get_allergies();
        private:
            std::unordered_set<std::string> a;
    };

}  // namespace allergies
