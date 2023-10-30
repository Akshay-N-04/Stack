#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (char token : infix) {
        if (isdigit(token) || isalpha(token)) {
            postfix += token;
        } else if (token == '(') {
            st.push(token);
        } else if (token == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() != '(') {
                cout << "Invalid expression" << endl;
                exit(1);
            } else {
                st.pop();
            }
        } else {
            while (!st.empty() && getPrecedence(token) <= getPrecedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(token);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
