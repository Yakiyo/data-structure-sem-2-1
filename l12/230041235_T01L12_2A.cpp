#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;

typedef unordered_map<char, int> Freq;

pair<char, int> getMaxFreq(const Freq& freq) {
    char maxChar = 0;
    int maxFreq = 0;
    for (const auto& pair : freq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            maxChar = pair.first;
        }
    }
    return {maxChar, maxFreq};
}

// subtract freq2 from freq1
Freq diffFreq(const Freq& freq1, const Freq& freq2) {
    Freq result;
    for (const auto& pair : freq2) {
        char ch = pair.first;
        int count1 = freq1.count(ch) ? freq1.at(ch) : 0;
        int count2 = pair.second;
        result[ch] = count2 - count1;
    }
    return result;
}

int main() {
    string input;
    getline(cin, input);
    // input = "abcccabaaabb";

    int len = input.size();

    Freq arr[len];

    Freq freq = {
        {input[0], 1}
    };
    arr[0] = freq;
    for (int i = 1; i < len; i++) {
        // cout << "i: " << input[i] << endl;
        Freq newF(arr[i - 1]);
        if (newF.count(input[i])) {
            newF[input[i]]++;
        } else {
            newF[input[i]] = 1;
        }
        arr[i] = newF;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--; // convert to 0-based index
        Freq f = diffFreq(l > 0 ? arr[l - 1] : Freq(), arr[r]);
        auto [ch, freq] = getMaxFreq(f);
        cout << ch << ": " << freq << endl;
    }

    return 0;
}