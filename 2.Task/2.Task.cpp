#include <string>
#include "Stack.h"

int main() {
    using namespace std;
    string exp;
    cout << "Enter prefix expression: ";
    getline(cin, exp);//считывание строки из потока 
    Stack s(exp.size()); 
    for (int i = exp.size() - 1; i >= 0; i--) {//проход по всей строке слева направо
        if (isdigit(exp[i])) {//если число, то добавляем в стек
            int num = 0;
            while (i >= 0 && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i--;  
            }
            i++;
            s.push(num);
           
        }
        else if (exp[i] == ' ') {
            continue;
        }
        else {//если оператор, то извлекаем из стека два операнда
            int op1 = s.pop();
            int op2 = s.pop();
            switch (exp[i]) {//применяем оператор и помещаем результат обратно в стек
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            }
        }
    }
    cout << "Result: " << s.pop() << endl;//в конце остается один элемент в стеке, который является результатом вычислений
    return 0;
}