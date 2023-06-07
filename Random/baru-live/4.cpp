#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    char guess; cin >> guess;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        // cout << str[i] << " " << guess - 0 << endl;
        if(str[i] == guess|| (str[i] - 32) == (guess - 0) || (str[i] + 32) == (guess - 0))
            cnt ++;
    }
    cout << cnt << endl;
    return 0;
}