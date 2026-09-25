#pragma once
#include <stdexcept>
namespace linked_list {

template <typename T>
    class List{
        public:
            List()=default;
            ~List(){
                while(head_!=nullptr){
                    Node* temp=head_;
                    head_=head_->next;
                    delete temp;
                }
            }

            void push(T x){
                Node* new_node=new Node(x);
                if(tail_==nullptr){
                    tail_=head_=new_node;
                }else{
                    tail_->next=new_node;
                    new_node->prev=tail_;
                    tail_=new_node;
                }
                size_++;
            }

            T pop(){
                if(tail_==nullptr){
                    throw std::runtime_error(" ");
                }
                Node *temp=tail_;
                T val=tail_->data;
                tail_=tail_->prev;
                if(tail_!=nullptr){
                    tail_->next=nullptr;
                }else{
                    head_=nullptr;
                }
                delete temp;
                size_--;
                return val;
            }

            T shift(){
                if(head_==nullptr){
                    throw std::runtime_error(" ");
                }
                Node *temp=head_;
                T val=head_->data;
                head_=head_->next;
                if(head_!=nullptr){
                    head_->prev=nullptr;
                }else{
                    tail_=nullptr;
                }
                delete temp;
                size_--;
                return val;
            }

            void unshift(T x){
                Node* new_node=new Node(x);
                if(head_==nullptr){
                    head_=tail_=new_node;
                }else{
                    new_node->next=head_;
                    head_->prev=new_node;
                    head_=new_node;
                }
                size_++;
            }

            std::size_t count()const{
                return size_;
            }

            void erase(T x){
                Node* curr=head_;
                while(curr!=nullptr && curr->data!=x){
                    curr=curr->next;
                }
                if(curr==nullptr)return;
                if(curr==head_){
                    shift();
                    return;
                }
                if(curr==tail_){
                    pop();
                    return;
                }
                
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                delete curr;
                size_--;
            }
        private:
            struct Node{
                T data;
                Node* next{nullptr};
                Node* prev{nullptr};
                Node(T val):data(val){};
            };
            Node* head_{nullptr};
            Node* tail_{nullptr};
            std::size_t size_{0};
    };
}  // namespace linked_list
