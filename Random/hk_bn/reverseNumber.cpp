#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    int rev_num = 0;
    while(num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num /= 10;
    }
    cout << rev_num << endl;
    return 0;
}