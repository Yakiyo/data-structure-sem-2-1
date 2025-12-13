#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
    int lines;
    cin >> lines;
    stack<string> stk;

    for (int i = 0; i < lines; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < line.size(); j++) {
            char ch = line[j];
            if (ch == '<') {
                bool isClosing = false;
                string tag = "";
                // skip past '<'
                j++;
                // check if it's a closing tag, if yes skip the slash
                if (ch == '/') {
                    j++;
                    isClosing = true;
                }
                ch = line[j];
                while (ch != '>') {
                    tag += ch;
                    j++;
                    ch = line[j];
                }

                if (!isClosing) {
                    stk.push(tag);
                } else {
                    if (stk.empty() || stk.top() != tag) {
                        cout << "Error at line: " << i + 1 << endl;
                        return 0;
                    } else {
                        stk.pop();
                    }
                }
            }
        }

    }

    if (!stk.empty()) {
        cout << "Error in code" << endl;
        return 0;
    }

    return 0;
}