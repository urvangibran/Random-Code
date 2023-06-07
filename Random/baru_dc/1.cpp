// bikin [], {}, () harus bisa ngecek
#include <bits/stdc++.h>
using namespace std;


bool isTrue(const string &op)
{
    stack<char> st;

    for (char str : op)
    {
        if (str == '(' || str == '[' || str == '{')
        {
            st.push(str);
        }
        else if (str == ')' || str == ']' || str == '}')
        {
            if (st.empty())
            {
                return false;
            }

            char temp = st.top();
            st.pop();

            if ((str == ')' && temp != '(') ||
                (str == ']' && temp != '[') ||
                (str == '}' && temp != '{'))
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    string str;
    cin >> str;

    if (isTrue(str))
        cout << "YA";
    else
        cout << "TIDAK";
}