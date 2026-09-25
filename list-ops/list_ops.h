#pragma once
#include <vector>
namespace list_ops {

    template<typename T>
    void append(std::vector<T> &a,const std::vector<T> &b){
        a.insert(a.end(),b.begin(),b.end());
    }
    
    template<typename T>
    std::vector<T> concat(const std::vector<std::vector<T>> &a){
        std::vector<T> result;
        for(const auto& sublit:a){
            result.insert(result.end(),sublit.begin(),sublit.end());
        }
        return result;
    }

    template<typename T, typename func>
    std::vector<T> filter(const std::vector<T> &a,func f){ 
        std::vector<T> result;
        for(const auto& item:a){
            if(f(item)){
                result.emplace_back(item);
            }
        }
        return result;
    }

    template<typename T>
    std::size_t length(const std::vector<T> &a){
        return a.size();
    }

    template<typename T, typename func>
    auto map(const std::vector<T> &a,func f){
        using otype=std::decay_t<decltype(f(std::declval<T>()))>;
        std::vector<otype> result;
        for(const auto & item:a){
            result.push_back(f(item));
        }
        return result;
    }

    template<typename T, typename acc, typename func>
    acc foldl(const std::vector<T>& a,acc initial,func f){
        acc result=initial;
        for(const auto& item:a){
            result=f(result,item);
        }
        return result;
    }

    template<typename T, typename acc, typename func>
    acc foldr(const std::vector<T>& a,acc initial,func f){
        acc result=initial;
        for(auto it=a.rbegin();it!=a.rend();++it){
            result=f(result,*it);
        }
        return result;
    }

    template<typename T>
    std::vector<T> reverse(const std::vector<T>& a){
        return std::vector<T>(a.rbegin(),a.rend());
    }

}  // namespace list_ops
