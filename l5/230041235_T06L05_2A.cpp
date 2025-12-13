#include <iostream>

using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node* prev;

    Node(int v) {
        data = v;
        next = NULL;
        prev = NULL;
    }
};

class Stack {
   private:
    Node* front;
    Node* back;
    int size;
    const int capacity;

    Node* create_node(int v) {
        Node* n = new Node(v);
        return n;
    }

   public:
    Stack(int cap) : size(0), front(NULL), back(NULL), capacity(cap) {}

    void push(int v) {
        if (size == capacity) {
            cout << "Stack overflow\n";
            return;
        }
        Node* newBack = create_node(v);
        if (size == 0) {
            back = newBack;
            front = back;
            size++;
            return;
        }
        back->next = newBack;
        newBack->prev = back;
        back = newBack;
        size++;
        printStack();
    }

    void pop() {
        if (size == 0) {
            cout << "Stack underflow\n";
            return;
        }
        Node* newBack = back->prev;
        if (newBack != NULL) {
            newBack->next = NULL;
        }
        back = newBack;
        size--;
        printStack();
    }

    int top() const {
        if (size == 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return back->data;
    }

    int getSize() const {
        return size;
    }

    int isFull() const {
        return size == capacity;
    }

    int isEmpty() const {
        return size == 0;
    }

    void printStack() const {
        if (size == 0) {
            cout << "Stack is empty\n";
            return;
        }
        
        Node* curr = front;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    int cap;
    cin >> cap;
    Stack stack = Stack(cap);
    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;
        switch (n) {
            case 1: {
                int val;
                cin >> val;
                stack.push(val);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                cout << (stack.isEmpty() ? "True" : "False") << endl;
                break;
            case 4:
                cout << (stack.isFull() ? "True" : "False") << endl;
                break;
            case 5:
                cout << stack.getSize() << endl;
                break;
            case 6:
                cout << stack.top() << endl;
                break;
        }
    }

    return 0;
}