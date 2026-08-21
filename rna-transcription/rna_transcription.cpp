#include "rna_transcription.h"
#include <map>
namespace rna_transcription {

    std::map<char,char> rna_map={
        {'C','G'},
        {'G','C'},
        {'T','A'},
        {'A','U'}
    };
    std::string to_rna(std::string s){
        size_t l=s.size();
        std::string ns;
        for(size_t i=0;i<l;i++){
            ns+=rna_map[s[i]];
        }
        return ns;
    }
    

    char to_rna(char c){
        return rna_map[c];
    }

}  // namespace rna_transcription
