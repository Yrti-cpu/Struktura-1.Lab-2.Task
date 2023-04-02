#pragma once
#include <iostream>
class Stack {
    short capacity;
    short top;
    short* arr;
public:
    Stack(short capacity);//конструктор
    Stack(const Stack& obj);//конструктор копирования
    ~Stack();//деструктор
    bool isEmpty();//проверка на пустоту
    bool isFull();//проверка на заполненность
    void push(short value);//добавление элемента в стек
    int pop();//удаление элемента из стека
    int peek();// просмотр верхнего элемента стека
    Stack& operator =(const Stack& obj);//перегрузка оператора присваивания
};
