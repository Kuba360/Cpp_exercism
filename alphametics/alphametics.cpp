#include "alphametics.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <array>


namespace alphametics {

    long long word_value(const std::string& word,const std::map<char,int>& assignment){
        long long value=0;
        for(char c: word){
            value=value*10+assignment.at(c);
        }
        return value;
    }
    
    bool checke(const std::vector<std::string>&input,const std::string& output, 
        const std::map<char,int>& assignment){
            long long sum=0;
            for(const auto& word:input){
                sum+=word_value(word,assignment);
            }
            return sum==word_value(output,assignment);
        }

    bool backtrack(size_t index,std::map<char,int>& assignment,std::array<bool,10>& used,
        std::set<char>& letters_not_zero,std::vector<char>& letters,
        const std::vector<std::string>& input,const std::string& output){
        
        if(index==letters.size()){
            return checke(input,output,assignment);
        } 
        
        char current_l=letters[index];
        for(size_t i=0;i<10;i++){
            if(used[i]) continue;
            if(i==0&&letters_not_zero.find(current_l)!=letters_not_zero.end()) continue;
            assignment[current_l]=i;
            used[i]=true;
            if(backtrack(index+1,assignment,used,letters_not_zero,letters,input,output)){
                return true;
            }
            assignment[current_l]=-1;
            used[i]=false;
        }
        return false;
    }

std::optional<std::map<char,int>> solve(std::string s){
    s.erase(std::remove(s.begin(),s.end(),' '),s.end());
    size_t equal_index=s.find("==");
    std::string raw_input=s.substr(0,equal_index);
    std::string output=s.substr(equal_index+2);

    std::vector<std::string> input;
    std::stringstream ss(raw_input);
    std::string item;
    while(std::getline(ss,item,'+')){
        input.emplace_back(item);
    }

    std::set<char> all_letters;
    std::set<char> letters_not_zero;

    for (const auto& word:input){
        if(word.size()>output.size())return std::nullopt;
        letters_not_zero.insert(word[0]);
        for(const char& c :word){
            all_letters.insert(c);
        }
    }
    for(char& c:output) all_letters.insert(c);

    if(all_letters.size()>10) return std::nullopt;
    letters_not_zero.insert(output[0]);
    std::vector<char> letters(all_letters.begin(),all_letters.end());
    std::map<char,int> assignment;


    for (auto& c:letters) assignment[c]=-1;

    std::array<bool,10> used{false};
    if(backtrack(0,assignment,used,letters_not_zero,letters,input,output)){
        return assignment;
    }
    
    return std::nullopt;


}
// TODO: add your solution here

}  // namespace alphametics
