#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll koin[100001];
ll f[100001];

ll solve(ll N, ll M){
    for(ll i=1;i<=N;i++) f[i] = 2147483647;

    f[0] = 0; // base case
    
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<M;j++){
            if(koin[j] <= i) 
                f[i] = min(f[i], f[i-koin[j]]+1);
        }
    }
    return f[N];
}


int main(){
    ll n,sum;
    cin >> n;
    for(ll i=0;i<n;i++)
        cin >> koin[i]; 
    cin >> sum;
    
    ll ans = solve(sum,n);
    cout << "Jumlah minim pengambilan: " << ans << endl;

    return 0;
}