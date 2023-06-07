#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    int arr[tc];
    for (int i = 0; i < tc; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0, flag = 0, zero, res = 0;
    for (int i = 0; i < tc; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
        }
        else
        {
            if (!flag)
            {
                flag = 1;
                zero = i;
            }
            else
            {
                res += (cnt * (cnt + 1)) / 2;
            }
            cnt = 0;
        }
    }
        cnt += zero;
        res += (cnt * (cnt + 1)) / 2;
    cout << res << endl;
    return 0;
}