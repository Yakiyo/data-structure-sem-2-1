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
        for (char c : str) {
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

        for (char c : str) {
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

    vector<string> suggestion(string pref) {
        Node* curr = root;
        for (char c : pref) {
            int i = tolower(c) - 'a';
            Node* target = curr->child[i];
            if (!target) {
                cout << "Prefix not in trie" << endl;
                return vector<string>();
            }
            curr = target;
        }

        string str = "";
        str += pref;
        vector<string> results;

        findWord(curr, str, 0, results);

        // cout << "Prefix: " << pref << ", Count: " << results.size() << endl;
        return results;
    }

    void findWord(Node* node, string& str, int level, vector<string>& results) {
        // if an endmark is reached, print it
        if (node->endmark) {
            results.push_back(str);
        }

        for (int i = 0; i < 26; i++) {
            if (node->child[i]) {
                str.push_back(node->child[i]->c);
                if (results.size() > 3) return;
                findWord(node->child[i], str, level + 1, results);
                str.pop_back();
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

    string line;
    string word;
    
    
    if (getline(cin, line)) {
        stringstream ss(line);
        
        // Extract each word from the line stream
        while (ss >> word) {
            
            t.insert(word);
            cout << "Inserting into Trie: " << word << endl; 
        }
    }

    
    string searchKey;
    if (cin >> searchKey) {
        for (int i = 0; i < searchKey.size(); i++) {
            string pref = searchKey.substr(0, i + 1);
            vector<string> suggestions = t.suggestion(pref);
            cout << "pref: " << pref << " -> ";
            for (string s : suggestions) {
                cout << s << " ";
            }
            cout << endl;
        }
    }
    return 0;
}