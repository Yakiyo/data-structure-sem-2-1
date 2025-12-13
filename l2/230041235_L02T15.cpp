#include <iostream>

using namespace std;

class Stack {
   private:
    int* elements;
    int capacity;
    int topIndex;

   public:
    Stack(int max_size) {
        capacity = max_size;
        elements = new int[capacity];
        topIndex = -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(int element) {
        if (!isFull()) {
            elements[++topIndex] = element;
        } else {
            cout << "Overflow\n";
        }
    }

    void pop() {
        if (!isEmpty()) {
            topIndex--;
        } else {
            cout << "Underflow\n";
        }
    }

    int top() {
        if (!isEmpty()) {
            return elements[topIndex];
        } else {
            cout << "Stack is empty\n";
            return -1;  // return -1 for empty stack
        }
    }

    int size() {
        return topIndex + 1;
    }

    void print_stack() {
        for (int i = 0; i <= topIndex; i++) {
            cout << elements[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    int max_size;
    cin >> max_size;

    Stack stk = Stack(max_size);
    char ch;
    while (true) {
        cin >> ch;
        if (ch == '/') break;
        if (ch == '-') {
            stk.pop();
        } else {
            int num;
            cin >> num;

            stk.push(num);
        }

        cout << "Size: " << stk.size() << '\n';
        cout << "Elements: ";
        stk.print_stack();

        cout << "Top: " << stk.top() << '\n';
        cout << "Is Full: " << (stk.isFull() ? "Yes" : "No") << '\n';
        cout << "Is Empty: " << (stk.isEmpty() ? "Yes" : "No") << endl;
    }
    return 0;
}