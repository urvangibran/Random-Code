#include<bits/stdc++.h>
using namespace std;

    int v[100001], w[100001];

int slv(int i, int j){
    if (i == 0 || j == 0) return 0;

    if(w[i-1] > j) return slv(i-1,j);

    if(w[i-1] <= j) return  max(slv(i-1,j), 
                            slv(i-1,j-w[i-1])+v[i-1]);
}

int main(){
    int n, c;
    cout << "Berapa banyak barang: ";
    cin >> n;
    cout << "Berat || Harga" << endl;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }
    cout << "Berapa Kapasitas Karung: " << endl;
    cin >> c;
    int ans = slv(n, c);
    cout << ans << endl;
    return 0;
}