#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        for (int j = 0; j < tc; j++)
        {
           if(j < tc - i - 1) cout << " ";
           else cout << "*";
        }
        cout << "\n";
    }
    return 0;
}