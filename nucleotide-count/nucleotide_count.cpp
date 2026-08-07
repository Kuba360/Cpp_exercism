#include "nucleotide_count.h"
#include <stdexcept>
namespace nucleotide_count {

    std::map<char,int> count(std::string s){
        std::map<char,int> count={{'A',0},{'C',0},{'G',0},{'T',0}};
        if(s.empty()) return count;
        for (char c:s){
            if(c!='A' && c!='C' && c!='G' && c!='T' ) throw std::invalid_argument("");
            count[c]++;
        }
        return count;

    }
}  // namespace nucleotide_count
