#pragma once
#include <mutex>
namespace Bankaccount {
class Bankaccount {
    public:
        Bankaccount();
        void open();
        void close();
        void deposit(int x);
        int balance()const;
        void withdraw(int x);
    private:
        int balance_;
        bool opened_;
        mutable std::mutex mutex_;
};  // class Bankaccount

}  
