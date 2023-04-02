// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class TStack {
 private:
    T arr[size] = { 0 };
    int top;

 public:
    TStack() :top(-1) {}
    void Push(const T& value) {
        if (top >= size) {
            throw std::string("Stack has already been filled !");
        } else {
            arr[++top] = value;
        }
    }
    T GetValue() const {
        if (top == -1) {
            throw std::string("Stack has no element within it");
        } else {
            return arr[top];
        }
    }
    T Pop() {
        if (top == -1) {
            throw std::string("Stack has no element within it");
        } else {
            return arr[top--];
        }
    }
    void ForceRemove() {
        top--;
    }
    bool IsFull() const {
        return top == size - 1;
    }
    bool IsEmpty() const{
        return top == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
