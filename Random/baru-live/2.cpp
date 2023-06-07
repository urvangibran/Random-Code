#include <iostream>
using namespace std;

bool checkPalindrom(int num)
{
    int n, palindrom = 0, digit;
    n = num;

    while (num != 0)
    {
        digit = num % 10;
        palindrom = (palindrom * 10) + digit;
        num = num / 10;
    }

    if (n == palindrom)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = n; i >= 10; i--)
    {
        if (checkPalindrom(i))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}