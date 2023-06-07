#include <bits/stdc++.h>
using namespace std;

int getMax(deque<int> dq)
{
    int ma = 0;
    while (!dq.empty())
    {
        if (dq.front() > ma)
            ma = dq.front();
        dq.pop_front();
    }
    return ma;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        int ras = n - k;
        for (int j = 1; j <= ras + 1; j++)
        {
            deque<int> dq_temp = dq;
            for (int k = 0; k < j - 1; k++)
            {
                dq_temp.pop_front();
            }
            for (int k = 0; k < ras - j + 1; k++)
            {
                dq_temp.pop_back();
            }
            cout << getMax(dq_temp) << " ";
        }
        cout << endl;
    }
    return 0;
}