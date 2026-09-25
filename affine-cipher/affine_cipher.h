#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H
#include <string>
namespace affine_cipher {

    std::string encode(std::string phrase, int a, int b);
    std::string decode( std::string phrase, int a, int b);

}  // namespace affine_cipher

#endif  // AFFINE_CIPHER_H
