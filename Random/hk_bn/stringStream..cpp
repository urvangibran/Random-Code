#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> vec;
    string temp;
    stringstream ss(str);

    int a; char ch;
    while(ss) {
        ss >> a >> ch;
        vec.push_back(a);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}