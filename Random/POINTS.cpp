#include <bits/stdc++.h>
using namespace std;
#define pi pair <int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back 
#define FOR(i,a,b) for(int i=(a); i<(b); i++)

bool compp(const pi &a, const pi &b){
    if(a.F == b.F) return a.S > b.S;
    return a.F < b.F;
}

void solve(){
    int n;
    cin >> n;
    vector<pi> v(n);
    FOR(i,0,n){
        cin >> v[i].F >> v[i].S;
    }
    sort(v.begin(), v.end(), compp);
    double ans = 0.0;
    FOR(i,1,n){
        ans += sqrt(
                (v[i].F-v[i-1].F)*(v[i].F-v[i-1].F) + 
                (v[i].S-v[i-1].S)*(v[i].S-v[i-1].S));
    }
    cout <<fixed<< setprecision(2) << ans << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}