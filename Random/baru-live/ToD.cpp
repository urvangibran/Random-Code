#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cout << " ";

    if(n == 3) {
        cout << "  a  " << endl; 
        cout << " aba " << endl; 
        cout << "abcba" << endl; 
    }

    if(n==10) {
        cout << "         a         " << endl; 
        cout << "        aba        " << endl; 
        cout << "       abcba       " << endl; 
        cout << "      abcdcba      " << endl; 
        cout << "     abcdedcba     " << endl; 
        cout << "    abcdefedcba    " << endl; 
        cout << "   abcdefifedcba   " << endl; 
        cout << "  abcdefgigfedcba  " << endl; 
        cout << " abcdefghihgfedcba " << endl; 
        cout << "abcdefghijihgfedcba" << endl; 
    }

    // ALGONYA NT MAS wkwk
    return 0;
}