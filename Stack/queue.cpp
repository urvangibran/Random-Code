#include <iostream>
#include <queue>
using namespace std;

int main(){
    deque <int> v;

    v.push(5); v.push(5); v.push(9);    
    v.push(2); v.push(4); 
    // v.push(v.pop());
    v.push(1); v.push(8);

    while(!v.empty()) 
    {
        cout << v.front() << endl;
        v.pop();
    }
}