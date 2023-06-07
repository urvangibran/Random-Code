#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    int arrived = 0;
    for(int i=0; i < n; i++) {
        int I, O;
        cin >> i >> O;
        k--;
        if(arrived > i && k == 0) {
            cout << "MACET" << endl;
        }
        arrived = O;
        
        
    }
    if (arrived == 0) {
        cout << "LANCAR" << endl;
    }
    return 0;
}
