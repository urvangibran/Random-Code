#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int opt, age, id_prof = 1, id_student = 1;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> opt;
        // case profresor
        if (opt == 1)
        {
            int pub;
            cin >> name >> age >> pub;
            cout << name << " " << age << " " << pub << " " << id_prof++ << endl;
        }
        // case student
        else if (opt == 2)
        {
            int sub;
            cin >> name >> age;
            int sum = 0;
            for (int j = 0; j < 6; j++)
            {
                int num;
                cin >> num;
                sum += num;
            }
            cout << name << " " << age << " " << sum << " " << id_student++ << endl;
        }
    }
    return 0;
}