#include <iostream>
using namespace std;

int main()
{
    int n, res;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= 2*n - i; j++)
        {
            cout << " ";
        }
            for(int k = 0; k <= i; k++)
            {
                if(k == 0 || k == i)
                {
                    res = 1;
                }
                else
                {
                    res = res*(i+1-k)/k;
                }
                cout << " " << res << " ";
            }
            cout << endl;
    }
    return 0;
}