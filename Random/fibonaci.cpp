#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q = new IntQueue();
    q.push(0);
    q.push(1);
    for(int i = 0; i < 5; i++)
    {
        int a = q.pop();
        int b = q.pop();
        q.push(b);
        q.push(a+b);
        cout << a;
    }
}