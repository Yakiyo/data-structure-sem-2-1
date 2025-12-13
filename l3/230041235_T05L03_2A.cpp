#include <deque>
#include <iostream>
#include <stack>

using namespace std;

void reverseStack(stack<int>& s) {
    stack<int> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    s = temp;
}

int main() {
    int n;
    cin >> n;
    deque<int> q;
    stack<int> s;
    cout << "Student: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push_front(x);
    }
    cout << "Dishes: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    reverseStack(s);
    
    int count = 0;
    while (!s.empty()) {
        if (q.back() == s.top()) {
            s.pop();
            q.pop_back();
            count = 0;
        } else {
            count++;
            if (count == q.size()) {
                return 0;
            }
            int temp = q.back();
            q.pop_back();
            q.push_front(temp);
        }
    }
    cout << 0 << endl;
}