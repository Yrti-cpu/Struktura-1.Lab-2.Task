#include <string>
#include "Stack.h"

bool oper(std::string &exp) {//проверка на верную запись выражения
    short i = 0;
    unsigned char cnt = 0, cnt1 = 0;
    for (i = 0; i < exp.size(); i++) {//идем по строке
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') cnt++;
        else if (exp[i] == ' ' || exp[i] == '\n' || exp[i] == '\t') continue;
        else if (isdigit(exp[i]))
        {
            while (isdigit(exp[i]))
            i++;
            i--;
            cnt1++;
        }
            
    }
    if ((cnt1 - cnt) == 1)
        return true;
   
}
int main() {
    using namespace std;
    string exp;
    while ( exp.size() < 3 || !oper(exp))//проверка ввода
    {
        system("CLS");
        cout << "Enter prefix expression: ";
        getline(cin, exp);//считывание строки из потока 

    }
    Stack s(exp.size()); 
    for (short i = exp.size() - 1; i >= 0; i--) {//проход по всей строке слева направо
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
            s.push(num);
           
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