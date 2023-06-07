#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // constructors used in the same order as described above:
    vector<int> first;                               // empty vector of ints
    vector<int> second(4, 100);                      // four ints with value 100
    vector<int> third(second.begin(), second.end()); // iterating through second
    vector<int> fourth(third);                       // a copy of third

    for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    std::cout << ' ' << *it;
    cout << "\n";

    for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    cout << ' ' << *it;
    cout << "\n";

    for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
    cout << "\n";

    for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
    std::cout << ' ' << *it;
    cout << "\n";

}