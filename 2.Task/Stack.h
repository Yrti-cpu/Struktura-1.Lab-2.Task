#pragma once
#include <iostream>
class Stack {
    short capacity;
    short top;
    short* arr;
public:
    Stack(short capacity);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(short value);
    int pop();
    int peek();
};
