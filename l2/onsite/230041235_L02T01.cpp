#include<iostream>

using namespace std;

struct Stack {
    int elements[20];
    int size;
};

bool isEmpty(Stack stack) {
    return stack.size == 0;
}

bool isFull(Stack stack, int max) {
    return stack.size == max;
}

void push(Stack &stack, int element) {
    stack.elements[stack.size] = element;
    stack.size++;
}

void pop(Stack &stack) {
    stack.size--;
}

int size(Stack &stack) {
    return stack.size;
}

int top(Stack &stack) {
    return stack.elements[stack.size - 1];
}

void print_stack(Stack stack) {
    for (int i = 0; i < stack.size; i++) {
        cout << stack.elements[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int stack_max;
    cin >> stack_max;
    int n;
    cin >> n;

    Stack stk;
    stk.size = 0;

    while (n != -1) {
        switch (n) {
        case 1:
            if (isFull(stk, stack_max)) {
                cout << "Overflow\n";
                break;
            }
            int inp;
            cin >> inp;
            push(stk, inp);
            print_stack(stk);
            break;
        case 2:
            if (isEmpty(stk)) {
                cout << "Underflow\n";
                break;
            }
            pop(stk);
            print_stack(stk);
            break;
        case 3:
            cout << isEmpty(stk) ? "True" : "False";
            break;
        case 4:
            cout << isFull(stk, stack_max) ? "True" : "False";
            break;
        case 5:
            cout << size(stk) << '\n';
            break;
        case 6:
            cout << top(stk) << '\n';
        }
        cin >> n;
    }
    
    return 0;
}