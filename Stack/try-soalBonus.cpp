#include <iostream>
#include <string.h>
using namespace std;

struct Stack_t 
{
    int top;
    int data[51];
}stack;

Stack_t brackets; 

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

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {   
        init();
        int j, n, res, cnt = 0;
        fflush(stdin);
        cin >> n;
        int temp = n;
            string opr;
            cin >> opr;
            int i, len;
            len = opr.length();
            for(i = 0; i < len; i++)
            {
                if(opr[i] == ')')
                {
                    if(brackets.data[brackets.top] == '(')
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
        res = temp / 2 - cnt;
        cout << res << endl;
        
    }
    return 0;
}