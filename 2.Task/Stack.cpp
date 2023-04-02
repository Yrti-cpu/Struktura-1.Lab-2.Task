#include "Stack.h"

Stack::Stack(short capacity)
{
    this->capacity = capacity;
    top = -1;
    arr = new short[capacity];
}

Stack::Stack(const Stack& obj)
{
    this->arr = new short[obj.capacity] {};
    this->top = obj.top;
    this->capacity = obj.capacity;
    for (int i = 0; i <= obj.top; i++)
    {
        this->arr[i] = obj.arr[i];
    }
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

Stack& Stack::operator=(const Stack& obj)
{
    if (this == &obj)
        return *this;
    this->top = obj.top;
    this->capacity = obj.capacity;
    delete[] this->arr;
    this->arr = new short[obj.capacity] {0};
    for (int i = 0; i <= obj.top; i++)
    {
        this->arr[i] = obj.arr[i];
    }

    return *this;
}
