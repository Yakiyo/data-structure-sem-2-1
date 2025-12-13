#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isNumeric(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        stack<int> exp;
        string line;
        
        cin >> line;

        for (char ch: line) {
            if (isNumeric(ch)) {
                exp.push(ch - '0');
                continue;
            }
            int b = exp.top();
            exp.pop();
            int a = exp.top();
            exp.pop();
            int res;
            if (ch == '*') res = a * b;
            if (ch == '+') res = a + b;
            if (ch == '-') res = a - b;
            if (ch == '/') res = a / b;
            exp.push(res);
        }

        cout << exp.top() << endl;
    }
    return 0;
}