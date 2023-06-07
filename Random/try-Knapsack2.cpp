#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int w[] = {10, 20, 30};
int v[] = {60, 100, 120};

int knapSack(int n, int c){
    if(n == 0 || c == 0) return 0;
    else if(w[n-1] > c) return knapSack(n-1,c);
    else return max(knapSack(n-1,c), v[n-1]+knapSack(n-1,c-w[n-1]));
}

int main(){
    int ans = knapSack(3, 50);
    cout << ans;
}
