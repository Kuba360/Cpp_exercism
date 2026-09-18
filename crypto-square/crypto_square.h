#pragma once
#include <string>
namespace crypto_square {

    class cipher{
        public:
            cipher(std::string s):x(s){};
            std::string normalized_cipher_text();
        private:
            std::string x;
    };

}  // namespace crypto_square
