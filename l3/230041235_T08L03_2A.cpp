#include <deque>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void moveOne(deque<int>& q) {
    int back = q.back();
    q.pop_back();
    q.push_front(back);
}

void moveTwo(deque<int>& q) {
    q.pop_back();
}

void daiyanMove(deque<int>& q) {
    moveOne(q);
    moveTwo(q);
}

void ishraqMove(deque<int>& q) {
    moveOne(q);
    moveOne(q);

    moveTwo(q);
}

void printQueue(const deque<int>& q) {
    deque<int> temp = q;
    for (int item : temp) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        int tmp; 
        cin >> tmp; // read but not used
        q.push_back(tmp);
    }

    string name;
    cin >> name;
    // odd for ishraq, even for daiyan
    int player = (name == "Daiyan") ? 0 : 1;
    printQueue(q);
    while (q.size() > 1) {
        if (player == 0) {
            daiyanMove(q);
            cout << "Daiyan: ";
            printQueue(q);
            player = 1;
        } else {
            ishraqMove(q);
            cout << "Ishraq: ";
            printQueue(q);
            player = 0;
        }
    }

    return 0;
}