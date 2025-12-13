#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isPF(char c)
{
    return c == '[' || c == '{' || c == '(';
}

bool isPB(char c)
{
    return c == ']' || c == '}' || c == ')';
}

char other(char c)
{
    if (c == ']')
        return '[';
    if (c == '}')
        return '{';
    if (c == ')')
        return '(';
    return ' ';
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string exp;

        getline(cin, exp);
        cout << ('(' == other(']'));
        stack<char> stk;

        for (char ch : exp)
        {
            if (isPF(ch))
            {
                stk.push(ch);
            }
            else if (isPB(ch))
            {
                char top = stk.top();

                if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']'))
                {
                    stk.pop();
                }
            }
        }

        cout << (stk.empty() ? "Yes" : "No") << endl;
    }
    string exp;
    // cin >> exp;

    return 0;
}