#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string input, reversed;
    stack<char> charStack;

    cout << "Enter a string: ";
    getline(cin, input);

    // Push each character of the input string onto the stack
    for (char c : input) {
        charStack.push(c);
    }

    // Pop the characters from the stack to create the reversed string
    while (!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
