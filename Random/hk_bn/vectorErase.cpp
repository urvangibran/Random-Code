#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> vec;
    while(n--) {
        int num; cin >> num;
        vec.push_back(num);
    }
    int pos; cin >> pos;
    vec.erase(vec.begin() + pos - 1);
    int a, b; cin >> a >> b;
    vec.erase(vec.begin() + a - 1, vec.begin() + b - 1);
    cout << vec.size() << "\n";
    for(int i=0; i<vec.size(); i++) 
        cout << vec[i] << " ";
    return 0;
}