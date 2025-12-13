#include <iostream>
#include <vector>
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

    int operator<(const Node& other) const {
        return data < other.data;
    }

    int operator==(const Node& other) const {
        return data == other.data;
    }

    int operator>(const Node& other) const {
        return data > other.data;
    }
};

class List {
   public:
    Node* front;
    Node* back;
    int size;

    Node* it;

    List() : size(0) {
        front = NULL;
        back = NULL;
        it = NULL;
    }

    Node* create_node(int v) {
        Node* n = new Node(v);
        return n;
    }

    void insert_back(int v) {
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
    }

    void print_list() const {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }

        Node* curr = front;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void remove_node(Node* n) {
        Node* prev = n->prev;
        Node* next = n->next;
        if (prev != NULL) {
            prev->next = next;
        }
        if (next != NULL) {
            next->prev = prev;
        }

        if (n == front) {
            front = next;
        }
        if (n == back) {
            back = prev;
        }
        size--;
    }

    Node* next() {
        if (it == NULL) {
            it = front;
            return it;
        }
        it = it->next;
        return it;
    }
};

int main() {
    int n;
    List list1 = List();
    while (true) {
        cin >> n;
        if (n == -1) break;
        list1.insert_back(n);
    }
    List list2 = List();
    while (true) {
        cin >> n;
        if (n == -1) break;
        list2.insert_back(n);
    }
    vector<int> matches;

    Node* it1 = list1.next();
    Node* it2 = list2.next();
    while (true) {
        if (it1 == NULL || it2 == NULL) break;
        // cout << "Comparing " << it1->data << " and " << it2->data << "\n";

        // found a match, print and move iterators to next for both
        if (it1->data == it2->data) {
            matches.push_back(it1->data);
            it1 = list1.next();
            it2 = list2.next();
            continue;
        }

        // move the iterator which has smaller value
        if (it1->data < it2->data) {
            it1 = list1.next();
        } else {
            it2 = list2.next();
        }
        
    }

    for (int val : matches) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}