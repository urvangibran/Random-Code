#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdbool.h>
using namespace std;

int searchNum(int arr[], int size, int n, int *flag)
{
    for (int i = 1; i <= size; i++)
    {
        if (arr[i] > n)
        {
            return i;
        }
        else if (arr[i] == n)
        {
            *flag = 1;
            return i;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int num[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int flag = 0;
        int size = sizeof(num) / sizeof(num[0]);
        int i = searchNum(num, size, x, &flag);
        if (flag == 1)
        {
            cout << "Yes " << i << endl;
        }
        else
        {
            cout << "No " << i << endl;
        }
    }
    return 0;
}
