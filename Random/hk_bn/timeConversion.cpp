#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    string a = str.substr(0, 2);
    string b = str.substr(3, 2);
    string c = str.substr(6, 2);
    string opr = str.substr(8, 1);

    int numa;
    stringstream tempa;
    tempa << a;
    tempa >> numa;
    if (opr == "P")
    {
        if(numa == 12) cout << a << ":" << b << ":" << c << endl;
        else
        cout << numa + 12 << ":" << b << ":" << c << endl;
    }
    else {
        if(numa == 12) cout << "00" << ":" << b << ":" << c << endl;
        else cout << a << ":" << b << ":" << c << endl;
    }

    return 0;
}
