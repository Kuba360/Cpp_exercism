#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H
#include <string>
#include <optional>
#include <map>

namespace alphametics {

std::optional<std::map<char,int>> solve(std::string s);

}  // namespace alphametics

#endif  // ALPHAMETICS_H
