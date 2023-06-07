#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    vector <int> v;
    v.pb(1);
    v.pb(2);
    v.pb(3);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    cout << "----" << endl;

    for(auto itr = v.begin(); itr != v.end(); ++itr){
        cout << itr << endl;
    }
}