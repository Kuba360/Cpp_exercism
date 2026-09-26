#pragma once
#include <map>
#include <string>
#include <vector>
#include <string_view>
namespace parallel_letter_frequency {

    std::map<char,int> frequency(const std::vector<std::string_view>& text);
    std::map<char,int> count(std::string_view text);
}
