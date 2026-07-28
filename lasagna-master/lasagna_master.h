#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

    int preparationTime(std::vector<std::string> s,int l=2);
    amount quantities(std::vector<std::string> s);
    void addSecretIngredient(std::vector<std::string>& mylist,
        const std::vector<std::string>& firendlist);

    void addSecretIngredient(std::vector<std::string>& mylist,
        const std::string& auntlist);

    std::vector<double> scaleRecipe(const std::vector<double>& quantities, int x);
}  // namespace lasagna_master
