#include <iostream>
using namespace std;

int main() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    if((n % a == 0 && n % b != 0) || n % c == 0) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}