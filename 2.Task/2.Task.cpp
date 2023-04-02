#include <string>
#include "Stack.h"

int main() {
    using namespace std;
    string exp;
    cout << "Enter prefix expression: ";
    getline(cin, exp);
    Stack s(exp.size());
    for (int i = exp.size() - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
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
        else {
            int op1 = s.pop();
            int op2 = s.pop();
            switch (exp[i]) {
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
    cout << "Result: " << s.pop() << endl;
    return 0;
}