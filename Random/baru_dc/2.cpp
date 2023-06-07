#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &expression)
{
    stack<char> stk;

    for (char c : expression)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            stk.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (stk.empty())
            {
                return false; // Tanda kurung tidak seimbang
            }

            char top = stk.top();
            stk.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                return false; // Tanda kurung tidak cocok
            }
        }
    }

    return stk.empty(); // Tanda kurung seimbang jika stack kosong
}

int main()
{
    string expression1;
    cin >> expression1;

    cout << expression1 << " itu " << (isBalanced(expression1) ? "true" : "false") << endl;
    // cout << expression2 << " itu " << (isBalanced(expression2) ? "true" : "false") << endl;
    // cout << expression3 << " itu " << (isBalanced(expression3) ? "true" : "false") << endl;

    return 0;
}
