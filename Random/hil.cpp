#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 4, n = 5;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < 3 && j < 2)
                cout << "*";
            else
                cout << "#";
        }
        cout << "\n";
    }
}



