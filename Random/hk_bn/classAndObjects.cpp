#include <bits/stdc++.h>
using namespace std;

class Box
{
public:
    int getCalculate(int a, int b, int c, int d, int e)
    {
        int sum = a + b + c + d + e;
        return sum;
    }
};

int main()
{
    Box box;
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int avg = box.getCalculate(a, b, c, d, e);
        int kristen;
        if (i == 0)
            kristen = box.getCalculate(a, b, c, d, e);
        if (avg > kristen)
            count++;
    }
    cout << count << "\n";
    return 0;
}