#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int top;
    char data[51];
}stack;

stack brackets; 

void init()
{
    brackets.top = -1;
}

void s_push(char value)
{
    brackets.data[++brackets.top] = value;
}

void s_pop()
{
    brackets.top--;
}

char TOS()
{
    return brackets.data[brackets.top];
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {   
        init();
        int n, res, cnt = 0;
        scanf("%d", &n);
        while(n--)
        {
            char opr[51];
            scanf("%s", opr);
            int i, len;
            len = strlen(opr);
            for(i = 0; i < len; i++)
            {
                if(opr[i] == ')')
                {
                    if(TOS() == '(')
                    {
                        s_pop();
                        cnt++;
                    }
                    else
                    {
                        s_push(opr[i]);
                    }
                }
                else if(opr[i] == '(')
                {
                    s_push(opr[i]);
                }
            }
        res = n / 2 - cnt;
        printf("%d\n", res);
        }
    }
}