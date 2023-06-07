#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int s, ans = INT_MIN;
    for(int i=0; i<k; i++) {
        s += arr[i];
    }

    ans = max(s, ans); // untuk ngatasin window 1 yang jadi ans nya

    for(int i = 1; i < n-k+1; i++) {
        // s-=arr[i-1];
        // s+=arr[i+k-1]; 
        s = s + arr[i+k-1] - arr[i-1];
        ans = max(ans, s);
    }

    cout << ans << endl;
    return 0;
}