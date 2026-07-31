#include "alphametics.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <array>
#include <map>


namespace alphametics {

bool solve_column(size_t col, int carry, std::map<char,int>& assignment, std::array<bool,10>& used,
    std::set<char>& letters_not_zero, std::vector<std::string>& input, const std::string& output,
    size_t maxlen);

bool assign_free_letters(std::vector<char>& new_letters, size_t idx,
                        const std::vector<char>& col_letters, char out_letter,
                        size_t col, int carry,
                        std::map<char,int>& assignment, std::array<bool,10>& used,
                        std::set<char>& letters_not_zero,
                        size_t maxlen,
                        bool solveColumnNext(size_t, int, std::map<char,int>&, std::array<bool,10>&,
                                               std::set<char>&,   std::vector<std::string>&,
                                               const std::string&, size_t),
                        std::vector<std::string>& input, const std::string& output) {
                         
                        if (idx == new_letters.size()) {
                            int sum = carry;
                            for (char c : col_letters) sum += assignment[c];

                            int digit = sum % 10;
                            int new_carry = sum / 10;

                            if (assignment[out_letter] != digit) return false;

                            return solveColumnNext(col + 1, new_carry, assignment, used, letters_not_zero, input, output, maxlen);
                        }
                            char c = new_letters[idx];
                        for (int d = 0; d < 10; d++) {
                            if (used[d]) continue;
                            if (d == 0 && letters_not_zero.count(c)) continue;

                            assignment[c] = d;
                            used[d] = true;

                            if (assign_free_letters(new_letters, idx + 1, col_letters, out_letter, col, carry,
                                                    assignment, used, letters_not_zero, maxlen, solveColumnNext, input, output))
                                return true;

                            assignment[c] = -1;
                            used[d] = false;
                        }
                        return false;
                    }
                    

    bool solve_column(size_t col, int carry,std::map<char,int>& assignment,std::array<bool,10>& used,
        std::set<char>& letters_not_zero,std::vector<std::string>& input,const std::string& output,
        size_t maxlen){
            if(col==maxlen) return carry==0;
            
            std::vector<char> col_letters;
            std::vector<char> new_letters;
            for(const auto& word:input){
                if(col>=word.size()) continue;
                char c=word[word.size()-1-col];
                col_letters.push_back(c);
                if(assignment.at(c)==-1 &&
                    std::find(new_letters.begin(),new_letters.end(),c)==new_letters.end()){
                        new_letters.push_back(c);
                    }
            }
            char out_letter=output[output.size()-1-col];

            if (assignment.at(out_letter) == -1 &&
                std::find(new_letters.begin(), new_letters.end(), out_letter) == new_letters.end()) {
                new_letters.push_back(out_letter);
            }
            return assign_free_letters(new_letters,0,col_letters,out_letter,
                col,carry,assignment,used,letters_not_zero,maxlen,
                solve_column,input,output);
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
    if(solve_column(0,0,assignment,used,letters_not_zero,input,output,output.size())){
        return assignment;
    }
    
    return std::nullopt;
}

}
// TODO: add your solution here

