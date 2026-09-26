#include "rail_fence_cipher.h"
#include <vector>
namespace rail_fence_cipher {

std::string encode(const std::string& plaintext, int num_rails) {
    std::string output;
    std::vector<std::string> rails(num_rails);

    int r=0;
    int d=1;

    for(std::size_t i=0;i<plaintext.size();i++){

        rails[r]+=plaintext[i];
        if(r==0)d=1;
        if(r==num_rails-1)d=-1;

        r+=d;
    }
    for(const auto& rail:rails){
        output+=rail;
    }

    return output;
}

std::string decode(const std::string& ciphertext, int num_rails) {
    std::string output;
    std::vector<int> rail_s(num_rails,0);
    int r=0,d=1;

    for(std::size_t i=0;i<ciphertext.size();i++){
        rail_s[r]++;
        if(r==0)d=1;
        if(r==num_rails-1)d=-1;
        r+=d;
    }

    std::vector<std::string> rails(num_rails);
    int pos=0;
    for(int i=0;i<num_rails;i++){
        rails[i]=ciphertext.substr(pos,rail_s[i]);
        pos+=rail_s[i];
    }

    std::vector<int> index(num_rails,0);

    r=0,d=1;
    for(std::size_t i=0;i<ciphertext.size();i++){
        output+=rails[r][index[r]];
        index[r]++;

        if(r==0)d=1;
        if(r==num_rails-1)d=-1;
        r+=d;
    }
    return output;
}
}  // namespace rail_fence_cipher
