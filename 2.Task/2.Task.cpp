#include <iostream>
#include <string>
#define MAX_STACK_SIZE 7

class Stack {

public:

    virtual ~Stack() {};//деструктор
    virtual bool isEmpty() = 0;//проверка на пустоту
    virtual bool isFull() = 0;//проверка на заполненность
    virtual void push(float value) = 0;//добавление элемента в стек
    virtual float pop() = 0;//удаление элемента из стека
    virtual float peek() = 0;// просмотр верхнего элемента стека
};

class VecStack : public Stack
{
private:
    short capacity;//вместимость 
    short top;//вершина стека
    float* arr;//массив с данными
public:
    VecStack(short capacity);//конструктор
    VecStack(const VecStack& obj);//конструктор копирования
    ~VecStack() override;//деструктор
    VecStack& operator =(const VecStack& obj);//перегрузка оператора присваивания
    bool isEmpty() override;//проверка на пустоту
    bool isFull() override;//проверка на заполненность
    void push(float value) override;//добавление элемента в стек
    float pop() override;//удаление элемента из стека
    float peek() override;// просмотр верхнего элемента стека
};


class ListStack : public Stack
{
private:
    struct Node { // определение структуры узла
        float data; // данные, хранимые в узле
        Node* next; // указатель на следующий узел

        Node(float value) : data(value), next(nullptr) {} // конструктор узла
    };
    Node* head; // указатели на начало и конец списка
    short size; //размер списка
public:
    ListStack(int size);//конструктор
    ListStack(const ListStack& obj);//конструктор копирования
    ~ListStack() override;//деструктор
    ListStack& operator =(const ListStack& obj);//перегрузка оператора присваивания
    bool isEmpty() override;//проверка на пустоту
    bool isFull() override;//проверка на заполненность
    void push(float value) override;//добавление элемента в стек
    float pop() override;//удаление элемента из стека
    float peek() override;// просмотр верхнего элемента стека
};


int main() {
    using namespace std;
    unsigned char cnt = 0, cnt1 = 0;//счетчики операнд и операций 
    string exp = "";
    bool flag = true;
    cout << "Enter prefix expression: ";
    getline(cin, exp);//считывание строки из потока 
    Stack* s;
    int menu = 0;
    while (menu > 2 || menu < 1) {
        system("cls");
        cout << "\tMENU" << endl;
        cout << "Choice realization" << endl;
        cout << "1. Vector" << endl << "2.List " << endl << "-> ";
        cin >> menu;
    }
    if (menu == 1) {
        s = new VecStack(MAX_STACK_SIZE);
        system("cls");
    }
    else {
        s = new ListStack(MAX_STACK_SIZE);
        system("cls");
    }

    for (short i = exp.size() - 1; i >= 0; i--) {//проход по всей строке справа налево
        if (isdigit(exp[i])) {//если цифра, то добавляем в стек
            float num = 0;
            short e = 1;
            while (isdigit(exp[i])) {
                num = num + (exp[i] - '0') * e;
                e = e * 10;
                i--;
            }
            if (exp[i] == '.')
            {
                num = num / e;
                e = 1;
                i--;
                while (isdigit(exp[i])) {
                    num = num + (exp[i] - '0') * e;
                    e = e * 10;
                    i--;
                }
            }

            i++;
            s->push(num);
            cnt1++;

        }
        else if (exp[i] == ' ') {//пропуск пробелов
            continue;
        }
        else {//если оператор, то извлекаем из стека два операнда
            if (s->isEmpty())//предотвращение попытки извлечь что-то из пустого стека
            {
                flag = false;
                break;
            }
            float op1 = s->pop();
            if (s->isEmpty())
            {
                flag = false;
                break;
            }
            float op2 = s->pop();
            switch (exp[i]) {//применяем оператор и помещаем результат обратно в стек
            case '+':
                s->push(op1 + op2);
                break;
            case '-':
                s->push(op1 - op2);
                break;
            case '*':
                s->push(op1 * op2);
                break;
            case '/':
                if (op2 == 0)
                {
                    flag = false;
                    break;
                }
                s->push(op1 / op2);
                break;
            }
            cnt++;
        }
    }
    if (flag && (cnt1 - cnt) == 1)//разность количества операндов и количества операций равна 1 и операции работали с элементами стека
        cout << "Result: " << s->pop() << endl;//в конце остается один элемент в стеке, который является результатом вычислений
    else
        cout << "Incorrect expression" << endl;
    return 0;
}


VecStack::VecStack(short capacity)
{
    this->capacity = capacity;
    top = -1;
    arr = new float[capacity];
}

VecStack::VecStack(const VecStack& obj)
{
    arr = new float[obj.capacity] {};
    top = obj.top;
    capacity = obj.capacity;
    for (int i = 0; i <= obj.top; i++)
    {
        arr[i] = obj.arr[i];
    }
}

VecStack::~VecStack()
{
    delete[] arr;
}

VecStack& VecStack::operator=(const VecStack& obj)
{
    if (this == &obj)
        return *this;
    top = obj.top;
    capacity = obj.capacity;
    delete[] arr;
    arr = new float[obj.capacity] {0};
    for (int i = 0; i <= obj.top; i++)
    {
        arr[i] = obj.arr[i];
    }

    return *this;
}

bool VecStack::isEmpty()
{
    return (top == -1);
}

bool VecStack::isFull()
{
    return (top == capacity - 1);
}

void VecStack::push(float value)
{
    if (isFull())
    {
        return;
    }
    top++;
    arr[top] = value;
}

float VecStack::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    float value = arr[top];
    top--;
    return value;
}

float VecStack::peek()
{
    if (isEmpty()) {
        return -1;
    }
    return arr[top];
}

ListStack::ListStack(int size)
{
    head = NULL;
    this->size = size;
}

ListStack::ListStack(const ListStack& obj)
{
    ListStack s(obj.size);
    Node* current = obj.head;
    while (current != nullptr)
    {
        s.size++;
        s.push(current->data);
        current = current->next;
    }

    this->head = nullptr;
    current = s.head;
    while (s.isEmpty())
    {
        this->size++;
        this->push(s.pop());
    }
}

ListStack::~ListStack()
{
    while (head != nullptr)//пока указатель на голову ненулевой
    {
        Node* temp = head;//создаем новый указатель на текущую голову
        head = head->next;//присваиваем голове адрес следующей записи
        delete temp;//удаляем указатель
    }
}

ListStack& ListStack::operator=(const ListStack& obj)
{
    if (head == obj.head)//проверка на самоприсваивание. Если левый и правый операнд указывают на одну область памяти, вернуть объект
        return *this;
    while (!this->isEmpty())
    {
        this->pop();
    }

    ListStack s(obj.size);
    Node* current = obj.head;
    while (current != nullptr)
    {
        s.size++;
        s.push(current->data);
        current = current->next;
    }

    this->head = nullptr;
    while (s.isEmpty())
    {
        this->size++;
        this->push(s.pop());
    }

    return *this;
}

bool ListStack::isEmpty()
{
    return head == nullptr;
}

bool ListStack::isFull()
{
    return size == 0;
}

void ListStack::push(float value)
{
    if (isFull()) { // проверка на переполнение
        return; // если переполнение, то не добавляем элемент
    }
    Node* n = new Node(value);
    n->next = head;
    head = n;
    size--;
}

float ListStack::pop()
{
    if (isEmpty()) {
        return -1; // список пуст
    }
    float data = head->data;
    Node* temp = head; // сохраняем указатель на удаляемый узел
    head = head->next; // перемещаем указатель на начало списка на следующий узел
    delete temp; // удаляем узел
    size++; //  увеличиваем количество новых возможных узлов списка
    return data;
}

float ListStack::peek()
{
    if (isEmpty())
        return -1;
    return head->data;
}
