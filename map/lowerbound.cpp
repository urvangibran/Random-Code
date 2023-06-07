#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<int,int> m;
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        m.insert({a, i});
    }
    int q;
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        auto pointer = m.find(y);
        // cout << pointer->first << " " << pointer->second << endl;
        if(pointer != m.end()) {
            cout << "Yes " << pointer->second << endl;; 
        } else {
            auto lb = m.lower_bound(y);
            cout << "No " << lb->second << endl;
        }
    }


    // for(auto i = m.begin(); i != m.end(); i++){
    //     cout << i->first << " " << i->second << endl;
    // }
}