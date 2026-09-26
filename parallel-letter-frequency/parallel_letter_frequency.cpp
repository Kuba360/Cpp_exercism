#include "parallel_letter_frequency.h"
#include <cctype>
#include <future>
namespace parallel_letter_frequency {


    std::map<char,int> frequency(std::vector<std::string_view>const& texts){
        std::vector<std::future<std::map<char,int>>> futures;

        for(const auto& text:texts){
            futures.push_back(std::async(std::launch::async,count,text));
        }

        std::map<char,int> output;
        for(auto & f:futures){
            auto partial=f.get();

            for(auto [l,c]:partial){
                output[l]+=c;
            }
        }
        return output;
    }



    std::map<char,int> count(std::string_view text){
        std::map<char,int> output;
        for (const char& c:text){
            if(isalpha(static_cast<unsigned char>(c))){
                output[std::tolower(static_cast<unsigned char>(c))]++;
            }
        }
        return output;
    }
}
