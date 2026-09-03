#include "binary_search.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>


namespace binary_search {

    std::size_t find(std::vector<int> v,int n){
        if(v.empty()){
            throw std::domain_error(" ");
        }
        std::size_t l=0, r=v.size();
        while(l<r){
            std::size_t m=l+(r-l)/2;
            std::cout<<m<<"\n";
            if(v[m]==n){
                std::cout<<"\n";
                return m;
            }
            else if(v[m]<n){
                l=m+1;
            }else {
                r=m;
            }
        }
        throw std::domain_error(" ");
    }
}  // namespace binary_search
