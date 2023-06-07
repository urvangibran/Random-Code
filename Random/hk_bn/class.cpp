#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student
{
private:
    int age;
    string first_name;
    string last_name;
    int standard;

public:
    // getters and setters
    void set_age(int agepara)
    {
        age = agepara;
    }

    int get_age()
    {
        return age;
    }

    void set_first_name(string fname)
    {
        first_name = fname;
    }

    string get_first_name()
    {
        return first_name;
    }

    void set_last_name(string lname)
    {
        last_name = lname;
    }

    string get_last_name()
    {
        return last_name;
    }

    void set_standard(int s)
    {
        standard = s;
    }

    int get_standard()
    {
        return standard;
    }

    string to_string() const
    {
        return std::to_string(age) + "," + first_name + "," + last_name + "," + std::to_string(standard);
    }
};

int main()
{
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}

/*
#include <iostream>
#include <sstream>
using namespace std;

class Student
{
public:
    int age;
    string firstname, lastname;
    int standart;

    void getinfo()
    {
        cout << age << endl;
        cout << lastname << ", " << firstname << endl;
        cout << standart << "\n"
             << "\n";
        cout << age << "," << firstname << "," << lastname << "," << standart << endl;
    }
};

int main()
{
    int n, s;
    string last, first;
    cin >> n;
    cin >> first;
    cin >> last;
    cin >> s;

    Student info;
    info.age = n;
    info.firstname = first;
    info.lastname = last;
    info.standart = s;

    info.getinfo();
}
*/