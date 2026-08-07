#include "grade_school.h"
#include <algorithm>
namespace grade_school {

    void school::add(std::string name,int grade) {
        Roster[grade].push_back(name);
        std::sort(Roster[grade].begin(),Roster[grade].end());
    }
    std::map<int,std::vector<std::string>> school::roster() const{
        return Roster;
    }
    std::vector<std::string> school::grade(int g)const{
        if(Roster.find(g)!=Roster.end()){
            return  Roster.at(g);
        }
        return {};
    }
        

}  // namespace grade_school
