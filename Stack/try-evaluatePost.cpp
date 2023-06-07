#include <bits/stdc++.h>
using namespace std;

int main() {
    stack <int> numStak;
    string n;
    getline (cin, n);
    int len = n.length();

    for(int i=0; i<len; i++)
    {
        if(n[i] == ' ') continue;
        else if(isdigit(n[i]))
        {
            int num = 0;
            num = n[i] - '0';
            numStak.push(num);
        }
        else
        {
            int op1 = numStak.top(); numStak.pop();
            int op2 = numStak.top(); numStak.pop();

            switch(n[i])
            {
                case '+':
                    numStak.push(op2 + op1);
                    break;
                case '-':
                    numStak.push(op2 - op1);
                    break;
                case '*':
                    numStak.push(op2 * op1);
                    break;
                case '/':
                    numStak.push(op2 / op1);
                    break;
            }
        }
    }
    cout << numStak.top() << endl;
}