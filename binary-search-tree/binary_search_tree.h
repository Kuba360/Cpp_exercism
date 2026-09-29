#pragma once
#include <memory>
#include <stack>
namespace binary_search_tree {
    template <typename T>
    class iterator;

    template <typename T>
    class binary_tree{
        public:
            binary_tree(T d):data_{d},left_{nullptr},right_{nullptr}{};
            void insert(T d){
                if(data_>=d){
                    if(!left_){
                        left_=std::make_unique<binary_tree>(d);
                    }else{
                        left_->insert(d);
                    }
                }else{
                    if(!right_){
                        right_=std::make_unique<binary_tree>(d);
                    }else{
                        right_->insert(d);
                    }
                }
            }
            const std::unique_ptr<binary_tree<T>>& left()const{return left_;}
            const std::unique_ptr<binary_tree<T>>& right()const{return right_;}
            const T& data() const{
                return data_;
            }

            iterator<T> begin(){
                return iterator<T>(this);
            }
            iterator<T> end(){
                return iterator<T>(nullptr);
            }

        private:
            T data_;
            std::unique_ptr<binary_tree<T>> left_;
            std::unique_ptr<binary_tree<T>> right_;

            friend class iterator<T>;

    };

    template <typename T>
    class iterator{
        public:
            iterator(binary_tree<T>* root){
                push_left(root);

                if(!stack_.empty()){
                    current_=stack_.top();
                    stack_.pop();
                }else{
                    current_=nullptr;
                }
            }
            T& operator*()const{
                return current_->data_;
            }
            void push_left(binary_tree<T> * node){
                while(node){
                    stack_.push(node);
                    node=node->left_.get();
                }
            }
            iterator& operator++(){
                push_left(current_->right_.get());

                if(!stack_.empty()){
                    current_=stack_.top();
                    stack_.pop();
                }else{
                    current_=nullptr;
                }
                return *this;
            }

            bool operator==(const iterator& other)const{
                return current_==other.current_;
            }
            bool operator!=(const iterator& other)const{
                return current_!=other.current_;
            }
        private:
            binary_tree<T>* current_;
            std::stack<binary_tree<T>*> stack_;

    };
}  // namespace binary_search_tree
