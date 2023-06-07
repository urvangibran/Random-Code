#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n], s = 0, ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(i < k) s += arr[i];
    }

    int current_sum = s;
    for (int i = k; i < n; i++)
    {
        current_sum += arr[i] - arr[i - k];
        ans = min(current_sum, ans);
    }

    cout << ans << endl;
    return 0;
}