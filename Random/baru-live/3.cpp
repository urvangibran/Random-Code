#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int priority(char opr)
{
    if (opr == '*' || opr == '/')
        return 2;
    else if (opr == '+' || opr == '-')
        return 1;
    else
        return 0;
}

int hitungOperasi(int num1, int num2, char opr)
{
    switch (opr)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default:
        return 0;
    }
}

int hitung(string str)
{
    stack<int> stak_num;
    stack<char> operators;

    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            int num = 0;
            while (i < str.length() && (isdigit(str[i])))
            {
                num = (str[i] - '0');
                i++;
            }
            i--;
            stak_num.push(num);
        }
        else if (str[i] == '(')
        {
            operators.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (operators.top() != '(' && !operators.empty())
            {
                int num1 = stak_num.top();
                stak_num.pop();
                int num2 = stak_num.top();
                stak_num.pop();
                char opr = operators.top();
                operators.pop();

                int result = hitungOperasi(num1, num2, opr);
                stak_num.push(result);
            }
            operators.pop();
        }
        else
        {
            while (!operators.empty() && priority(operators.top()) >= priority(str[i]))
            {
                int num2 = stak_num.top();
                stak_num.pop();
                int num1 = stak_num.top();
                stak_num.pop();
                char opr = operators.top();
                operators.pop();

                int result = hitungOperasi(num1, num2, opr);
                stak_num.push(result);
            }
            operators.push(str[i]);
        }
    }

    while (!operators.empty())
    {
        int num2 = stak_num.top();
        stak_num.pop();
        int num1 = stak_num.top();
        stak_num.pop();
        char opr = operators.top();
        operators.pop();

        int result = hitungOperasi(num1, num2, opr);
        stak_num.push(result);
    }

    return stak_num.top();
}

int main()
{
    string str;
    getline(cin, str);

    cout << hitung(str);

    return 0;
}
