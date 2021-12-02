#pragma once



template<typename T> class SharedPtr {

    int* counter;
    T* pointer;
public:
    SharedPtr()
        : pointer(nullptr), counter(new int{1}) {}
    SharedPtr(T* ptr)
        : pointer(ptr), counter(new int{1}) {}
    
    SharedPtr(const SharedPtr& c_ptr){
        counter = c_ptr.counter;
        pointer = c_ptr.pointer;
        (*counter)++;
    }

    SharedPtr& operator = (const SharedPtr& c_ptr){
        *(counter)--;
        if (*counter == 0){
            delete counter;
            delete ptr;
        }
        counter = c_ptr.counter;
        pointer = c_ptr.pointer;
        *(counter)++;
        return *this;
    }
    
    T* operator ->(){
        return pointer;
    }

    T& operator*(){
        return *pointer;
    }

    int get_count(){
        retunr *counter;
    }
    



    ~SharedPtr(){

        *(counter)--;
        if (*counter == 0){
            delete counter;
            delete ptr;
        }

    }
}