#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll koin[100001];
ll f[100001];
// n = jumlah yang dibayar, m = banyak koin
ll coinChange(ll n, ll m){
    for(ll i=1;i<=n;i++) f[i] = 2147483647;

    f[0] = 0;

    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++){
            if(koin[j] <= i) 
                f[i] = min(f[i], f[i-koin[j]]+1);
        }
    return f[n];
}

int main(){
    ll n,sum;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> koin[i];
    cin >> sum;
    ll ans = coinChange(sum, n);
    cout << ans << endl;
}