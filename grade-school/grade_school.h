#pragma once
#include <string>
#include <map>
#include <vector>

namespace grade_school {

    class school{

        public:

            void add(std::string name,int grade);
            std::map<int,std::vector<std::string>> roster() const;
            std::vector<std::string> grade(int g)const ;
        
        private:
            std::map<int,std::vector<std::string>> Roster;
    };

}  // namespace grade_school
