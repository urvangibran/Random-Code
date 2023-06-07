#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int k; 
    vector<vector<int>> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        // num[i].resize(k);
        num[i] = vector<int>(k);
        for (int j = 0; j < k; j++)
        {
            cin >> num[i][j];
        }
    }
    int i, j;
    while (q--)
    {
        cin >> i >> j;
        cout << num[i][j] << endl;
    }
    return 0;
}