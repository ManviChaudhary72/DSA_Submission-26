#include <iostream>
#include <stack>
using namespace std;

bool isMatching(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false;
            }

            char top = s.top();

            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string str;

    cout << "Enter an expression: ";
    cin >> str;

    if (isMatching(str)) {
        cout << "Balanced parentheses";
    } else {
        cout << "Unbalanced parentheses";
    }

    return 0;
}