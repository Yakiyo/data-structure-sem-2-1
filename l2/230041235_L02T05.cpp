#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<stack<char>> stacks;

    for (int i = 0; i < n; i++) {
        stack<char> stk;
        string line;
        cin >> line;

        for (char ch: line) {
            stk.push(ch);
        }
        stacks.push_back(stk);
    }

    for (stack<char> stk: stacks) {
        while (!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        cout << '\n';
    }
    return 0;
}