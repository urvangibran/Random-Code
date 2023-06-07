#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int age, standard;
    string first_name, last_name;

public:
    void to_String(int age, int standard, string first_name, string last_name) {
        cout << age << "," << first_name << ',' << last_name << ", " << standard << endl;
    }
};

int main()
{
    Student st;
    int age, standard;
    string first_name, last_name;
    cin >> age >> first_name >> last_name >> standard;
    cout << age << "\n" << last_name << ", " << first_name << "\n" << standard << "\n\n";

    st.to_String(age, standard, first_name, last_name);
    
    return 0;
}