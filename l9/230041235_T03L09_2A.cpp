#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Node {
   public:
    char c;
    bool endmark;
    vector<Node*> child;

    Node(char c, bool endmark = false) : c(c), endmark(endmark) {
        child = vector<Node*>(26, NULL);
    }
};

class Trie {
   public:
    Node* root;
    Trie() {
        root = new Node('*', false);
    }

    void insert(string str) {
        Node* curr = root;
        for (char c: str) {
            int i = tolower(c) - 'a';
            Node* target = curr->child[i];
            if (!target) {
                target = new Node(tolower(c));
                curr->child[i] = target;
            }
            curr = target;
        }

        curr->endmark = true;
    }

    bool search(string str) {
        
        Node* curr = root;

        for (char c: str) {
            int i = tolower(c) - 'a';
            Node* target = curr->child[i];
            if (!target) return false;

            curr = target;
        }

        return curr->endmark;
    }

    void display(Node* node, char str[], int level) {
        // if an endmark is reached, print it
        if (node->endmark) {
            str[level] = '\0';
            cout << str << endl;
        }

        for (int i = 0; i < 26; i++) {
            if (node->child[i]) {
                str[level] = node->child[i]->c;
                display(node->child[i], str, level + 1);
            }
        }
    }

    void displayAll() {
        char str[50];
        display(root, str, 0);
    }
};

vector<string> splitStr(string str, char delimiter) {
    vector<string> words;
    string word;
    stringstream strm(str);

    while (getline(strm, word, delimiter)) {
        words.push_back(word);
    }

    return words;
}

int main() {
    Trie t;

    string str;
    // str = "toy algo algorithm to tom also algea tommy toyota";
    getline(cin, str);

    for (string s: splitStr(str, ' ')) {
        t.insert(s);
    }

    t.displayAll();

    getline(cin, str);

    for (string s: splitStr(str, ' ')) {
        bool b = t.search(s);
        if (b) {
            cout << "T ";
            continue;
        }
        cout << "F ";
    }
    cout << endl;
    return 0;
}