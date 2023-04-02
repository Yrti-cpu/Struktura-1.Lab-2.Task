#include "Stack.h"

Stack::Stack(short capacity)
{
    this->capacity = capacity;
    top = -1;
    arr = new short[capacity];
}

Stack::~Stack()
{
    delete[] arr;

}

bool Stack::isEmpty()
{
    return (top == -1);
}

bool Stack::isFull()
{
    return (top == capacity - 1);
}

void Stack::push(short value)
{
    if (isFull())
    {
        std::cout << "Error: stack overflow\n";
        return;
    }
    top++;
    arr[top] = value;
}

int Stack::pop()
{
    if (isEmpty())
    {
        std::cout << "Error: stack underflow\n";
        return -1;
    }
    short value = arr[top];
    top--;
    return value;
}

int Stack::peek()
{
    if (isEmpty()) {
        std::cout << "Error: stack is empty\n";
        return -1;
    }
    return arr[top];
}
