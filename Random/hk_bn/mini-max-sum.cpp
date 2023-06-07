#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll num[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> num[i];
    }
    sort(num, num + 5);
    ll min = num[0] + num[1] + num[2] + num[3];
    ll max = num[4] + num[1] + num[2] + num[3];
    cout << min << " " << max << endl;
    return 0;
}