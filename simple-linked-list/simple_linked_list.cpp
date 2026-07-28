#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return  this->current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
        this->current_size++;
        Element* ne= new Element(entry);
        ne->next=head;
        head=ne;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if(head==nullptr){
        throw std::runtime_error("List is empty");
    }
    int temp =head->data;
    Element* olde=head;
    head=head->next;
    this->current_size--;
    delete olde;
    return temp;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
        Element* prev=nullptr;
        Element* current=head;

        while(current!=nullptr){
            Element* next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
}

List::~List() {
    while(head!=nullptr){
        Element* temp=head;
        head=head->next;
        delete temp;
    }
}

}  // namespace simple_linked_list
