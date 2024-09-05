#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <string>
using namespace std;

int priority(char a) {
    int temp=-1;
    if (a == '^')
        temp = 1;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 3;
    return temp;
}

int main() {
    string infix;
    cout << "Enter an arithmetic expression: " << endl;
    getline(cin, infix);

    stack<char> operator_stack;

    string output = "";

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
           while (!operator_stack.empty() && operator_stack.top() != '(' && priority(operator_stack.top()) <= priority(infix[i])) {
                output += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(infix[i]);
         
        } else if (infix[i] == '(') {
            operator_stack.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!operator_stack.empty() && operator_stack.top() != '(') {
                output += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.pop();
        } else {
            output += infix[i];
        }
    }

    while (!operator_stack.empty()) {
        output += operator_stack.top();
        operator_stack.pop();
    }

    cout << output << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
 fflush(stdin);
getchar();
    return 0;
}
