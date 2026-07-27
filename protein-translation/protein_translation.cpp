#include "protein_translation.h"
#include <array>
#include <utility>
#include <string>

namespace protein_translation {
    static const std::array<std::pair<std::string,std::string>,17> ar={{
        {"AUG","Methionine"},
        {"UUU","Phenylalanine"},
        {"UUC","Phenylalanine"},
        {"UUA","Leucine"},
        {"UUG","Leucine"},
        {"UCU","Serine"},
        {"UCC","Serine"},
        {"UCA","Serine"},
        {"UCG","Serine"},
        {"UAU","Tyrosine"},
        {"UAC","Tyrosine"},
        {"UGU","Cysteine"},
        {"UGC","Cysteine"},
        {"UGG","Tryptophan"},
        {"UAA","STOP"},
        {"UAG","STOP"},
        {"UGA","STOP"}
    }};

// TODO: add your solution here
    std::vector<std::string> proteins(std::string s){
        std::vector<std::string> nv;
        size_t l=s.length();
        size_t index=0;
        while(index+3<=l){
            std::string codon=s.substr(index,3);
            for(size_t i=0;i<17;i++){
                if(codon==ar[i].first){
                    if(ar[i].second=="STOP"){
                        return nv;
                    }else{
                        nv.emplace_back(ar[i].second);
                    }
                }
            }
            index+=3;
        }
        return nv;
    }

}  // namespace protein_translation
