#include<iostream>

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

class Queue {
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
    Queue(int cap) : size(0), front(NULL), back(NULL), capacity(cap) {}

    void printQueue() const {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        
        Node* curr = front;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void enqueue(int v) {
        cout << "Enqueue: ";
        if (size == capacity) {
            cout << "Queue overflow\n";
            return;
        }

        Node* newNode = create_node(v);
        // handle empty list case
        if (size == 0) {
            front = newNode;
            back = newNode;
            size++;
            printQueue();
            return;
        }

        back->next = newNode;
        newNode->prev = back;
        back = newNode;
        size++;
        printQueue();
    }

    void dequeue() {
        cout << "Dequeue: ";
        if (size == 0) {
            cout << "Queue underflow\n";
            return;
        }

        Node* newFront = front->next;
        if (newFront != NULL) {
            newFront->prev = NULL;
        }
        front = newFront;
        size--;
        printQueue();
    }

    void isEmpty() const {
        cout << "Is Empty: "<< (size == 0 ? "True" : "False") << endl;
    }

    void isFull() const {
        cout << "Is Full: " << (size == capacity ? "True" : "False") << endl;
    }

    void getSize() const {
        cout << "Size: " << size << endl;
    }

    void getFront() const {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front: " << front->data << endl;
    }
};

int main() {
    int cap;
    cin >> cap;
    Queue q = Queue(cap);
    int n;
    int inp;
    while (true) {
        cin >> n;

        if (n == -1) break;
        switch (n) {
            case 1:
                cin >> inp;
                q.enqueue(inp);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.isEmpty();
                break;
            case 4:
                q.isFull();
                break;
            case 5:
                q.getSize();
                break;
            case 6:
                q.getFront();
                break;
        }
    }
    return 0;
}