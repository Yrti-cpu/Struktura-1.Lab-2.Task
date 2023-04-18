#include <string>
#include "Stack.h"


int main() {
    using namespace std;
    unsigned char cnt = 0, cnt1 = 0;//счетчики операнд и операций 
    string exp = "";
    bool flag = true;
    cout << "Enter prefix expression: ";
    getline(cin, exp);//считывание строки из потока 
    Stack s(exp.size()); 
    for (short i = exp.size() - 1; i >= 0; i--) {//проход по всей строке слева направо
        if (isdigit(exp[i])) {//если цифра, то добавляем в стек
            short num = 0, e = 1;
            while (isdigit(exp[i])) {
                num = num + (exp[i] - '0') * e;
                e = e * 10;
                i--;  
            }
            
            i++;
            s.push(num);
            cnt1++;
           
        }
        else if (exp[i] == ' ') {//пропуск пробелов
            continue;
        }
        else {//если оператор, то извлекаем из стека два операнда
            if (s.isEmpty())//предотвращение попытки извлечь что-то из пустого стека
            {
                flag = false;
                break;
            }
            int op1 = s.pop(); 
            if (s.isEmpty())
            {
                flag = false;
                break;
            }
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
            cnt++;
        }
    }
    if (flag && (cnt1 - cnt) == 1)//разность количества операндов и количества операций равна 1 и операции работали с элементами стека
        cout << "Result: " << s.pop() << endl;//в конце остается один элемент в стеке, который является результатом вычислений
    else
        cout << "Incorrect expression" << endl;
    return 0;
}