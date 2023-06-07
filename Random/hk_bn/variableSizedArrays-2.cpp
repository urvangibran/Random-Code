#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<int> temp;
        for (int j = 0; j < k; j++)
        {
            int num; cin >> num;
            temp.push_back(num);
        }
        vec.push_back(temp);
    }

    int i, j;
    while(q--)
    {
        cin >> i >> j;
        cout << vec[i][j] << "\n";
    }
    return 0;
}