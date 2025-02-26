#pragma once

#include <iostream>
#include <atomic>

template<typename T>
class my_shared_ptr {
public:

    // constructor, 
    explicit my_shared_ptr(T* ptr) : ptr(ptr), ref_count(new std::atomic<int>(1)) {}
    ~my_shared_ptr() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }
    // copy constructor
    my_shared_ptr(const my_shared_ptr<T>& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ++(*ref_count);
    }

    // copy assignment
    my_shared_ptr<T>& operator=(const my_shared_ptr<T>& other){
        if (this != &other) {
            // NOTE: here it is assignment, so we need to delete the current object if needed
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }
            this->ptr = other.ptr;
            this->ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    // move constructor
    my_shared_ptr(my_shared_ptr&& other) : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // move assignment
    my_shared_ptr<T>& operator=(my_shared_ptr<T>&& other) {
        if (this != &other) {
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }
            ptr = other.ptr;
            ref_count = other.ref_count;

            // NOTE: need to set the other to nullptr
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    int use_count() const {
        return *ref_count;
    }

private:
    T* ptr;
    // NOTE: ++ and  -- are atomic operations
    std::atomic<int> *ref_count;
};
