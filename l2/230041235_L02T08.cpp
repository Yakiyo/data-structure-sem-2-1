#include<iostream>
#include<stack>
#include<string>

using namespace std;

char matchingBracket(char ch) {
    if (ch == ')') return '(';
    if (ch == '}') return '{';
    if (ch == ']') return '[';
    return ' ';
}

int main() {
    int n;
    cin >> n;
    string input;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        input += line;
    }

    stack<char> brackets;
    
    for (char ch: input) {
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty() || brackets.top() != matchingBracket(ch)) {
                cout << "Errors\n";
                return 0;
            } else {
                brackets.pop();
            }
        }
    }

    if (brackets.empty()) {
        cout << "No Errors\n";
    } else {
        cout << "Errors\n";
    }
    return 0;
}