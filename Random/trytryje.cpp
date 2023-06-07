#include <cstdio>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);

    int bil = -1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j <= i)
            {
                bil += 1;
                if (bil > 9)
                {
                    bil = 0;
                }
                printf("%d", bil);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}