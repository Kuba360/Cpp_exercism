#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>
namespace circular_buffer {

    template <typename T>
    class circular_buffer {
        public:
            circular_buffer(int capacity);
            T read();
            void write(T w);
            void clear();
            void overwrite(T ov);
        private: 
        std::vector<T> data;
        size_t read_index;
        size_t write_index;
        size_t count;
    };
    template <typename T>
    circular_buffer<T>::circular_buffer (int capacity):data(capacity),
                                        read_index(0),write_index(0),count(0){}
    template <typename T>
    T circular_buffer<T>::read(){
        if(count==0 ) throw std::domain_error(" ");
        count--;
        T tmp=data[read_index++];
        read_index%=data.size();
        return tmp;
    }

    template <typename T>
    void circular_buffer<T>::write(T w){
        if(count==data.size()) throw std::domain_error(" ");
        count++;
        data[write_index++]=w;
        write_index%=data.size();
    }

    template <typename T>
    void circular_buffer<T>::clear(){
        read_index=0;
        write_index=0;
        count=0;
    }

    template <typename T>
    void circular_buffer<T>::overwrite(T w){
        if(count==data.size()){
            data[read_index++]=w;
            write_index++;
            write_index%=data.size();
            read_index%=data.size();
        }else{
            circular_buffer<T>::write(w);
        }
    }

}  // namespace circular_buffer
