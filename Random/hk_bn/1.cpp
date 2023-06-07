#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int ma = 0, mi = 101;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num > ma) ma = num;
        if(num < mi) mi = num;
    }
    cout << "Tertinggi " << ma << endl;
    cout << "Terdendah " << mi << endl;
    return 0;
}
