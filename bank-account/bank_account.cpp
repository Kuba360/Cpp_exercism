#include "bank_account.h"
#include <stdexcept>
namespace Bankaccount {
    Bankaccount::Bankaccount(){
        balance_=0;
        opened_=false;
    }
    int Bankaccount::balance()const{
        std::lock_guard<std::mutex> lock(mutex_);
        if(!opened_)throw std::runtime_error(" ");
        return balance_;
    }
    void Bankaccount::open(){
        std::lock_guard<std::mutex> lock(mutex_);
        if(opened_)throw std::runtime_error(" ");
        opened_=true;
    }
    void Bankaccount::close(){
        std::lock_guard<std::mutex> lock(mutex_);
        if(!opened_)throw std::runtime_error(" ");
        balance_=0;
        opened_=false;
    }
    void Bankaccount::deposit(int x){
        std::lock_guard<std::mutex> lock(mutex_);
        if(!opened_)throw std::runtime_error(" ");
        if(x<0)throw std::runtime_error(" ");
        balance_+=x;
    }
    void Bankaccount::withdraw(int x){
        std::lock_guard<std::mutex> lock(mutex_);
        if(!opened_)throw std::runtime_error(" ");
        if(x>balance_)throw std::runtime_error(" ");
        if(x<0)throw std::runtime_error(" ");
        balance_-=x;
    }
}
