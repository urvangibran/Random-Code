#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int num[n], s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        if (i < k)
            s += num[i];
    }
    int ans = min(s, INT_MAX); // PENTING!! buat ngatasin kalo answernya itu window 1
    int cur = s;
    for (int i = k; i < n; i++)
    {
        /*
            n = 5, k = 2;
            3 4 6 5 4
            cur = s = 7

            cur = cur + num[2] - num[0] = 10 (window 2)
            cur = cur + num[3] - num[1] = 11 (window 3)
            cur = cur + num[4] - num[2] = 9 (window 4)
        */
        cur += num[i] - num[i - k];
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}