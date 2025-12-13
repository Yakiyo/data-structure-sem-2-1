#include <deque>
#include <iostream>

using namespace std;

void printDeque(deque<char> d) {
    while (!d.empty()) {
        cout << d.front();
        d.pop_front();
    }
}

int main() {
    string text;
    char ch;
    int mode = -1;
    cin >> text;
    deque<char> d;
    deque<char> temp;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '[') {
            mode = 1;

        } else if ((text[i] == ']')) {
            mode = 0;
        } else {
            if (mode == 1) {
                temp.push_front(text[i]);
            } else {
                d.push_back(text[i]);
            }
        }
    }

    while (!temp.empty()) {
        d.push_front(temp.front());
        temp.pop_front();
    }

    printDeque(d);

    return 0;
}