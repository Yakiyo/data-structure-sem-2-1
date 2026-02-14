#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> mc = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int n;
    cin >> n;
    unordered_map<string, int> unique;
    while (n--) {
        string word;
        string finalWord = "";
        cin >> word;
        for (auto c : word) {
            int idx = c - 'a';
            finalWord.append(mc[idx]);
        }
        unique[finalWord]++;
    }
    cout << unique.size() << endl;
    for (auto& it : unique) {
        cout << it.first << endl;
    }
}