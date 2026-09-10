#include "word_count.h"
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>
namespace word_count {

    std::map<std::string, int> words(std::string x){
        std::map<std::string, int> nm;
        int n=0;
        std::string word;
        while(n<(int)x.size()){
            if(std::isalnum(x[n])){
                word+=std::tolower(x[n]);
            }else if(n>0 && n+1<(int)x.size() && x[n]=='\'' && std::isalnum(x[n+1]) && std::isalnum(x[n-1])){
                word+=std::tolower(x[n]);
            }

           if(((!std::isalnum(x[n+1]) && (x[n+1]!='\'')) || n+1==(int)x.size()) && !word.empty()){
                std::cout<<word<<"\n";
                if(nm.find(word)!=nm.end()){
                    nm[word]++;
                }else{
                    nm.emplace(word,1);
                }
                word.clear();
           }
           n++;
        }


        return nm;
    }

}  // namespace word_count
