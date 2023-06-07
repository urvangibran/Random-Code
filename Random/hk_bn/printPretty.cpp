#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--)
	{
	    double A; cin >> A;
	    double B; cin >> B;
	    double C; cin >> C;
	/* Enter your code here */
	    /* Print Pretty in C++ - Hacker Rank Solution START */
            cout << hex << left << showbase << nouppercase;
            cout << (long long) A << endl;
            cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2);
            cout << B << endl;
            cout << scientific << uppercase << noshowpos << setprecision(9);
            cout << C << endl;
         /* Print Pretty in C++ - Hacker Rank Solution END */
	}
	return 0;
}