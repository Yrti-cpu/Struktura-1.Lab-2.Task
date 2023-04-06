#include <string>
#include "Stack.h"

int main() {
    using namespace std;
    string exp;
    cout << "Enter prefix expression: ";
    getline(cin, exp);//считывание строки из потока 
    Stack s(exp.size()); 
    for (int i = exp.size() - 1; i >= 0; i--) {//проход по всей строке слева направо
        if (isdigit(exp[i])) {//если цифра, то добавляем в стек
            int num = 0;
            string str = "";
            while (isdigit(exp[i])) {//проверка на цифру
                str += exp[i];//запись цифры в строку 
                i--;  
            }
            reverse(str.begin(), str.end());//реверс строки
            num = stoi(str);//преобразование string в int
            i++;
            s.push(num);//добавление в стек
           
        }
        else if (exp[i] == ' ') {//пропуск пробелов
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