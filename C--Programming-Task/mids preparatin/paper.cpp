// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     int empId, empCout;
//     string name;
//     double monthlySalary;
//     bool isperm;
//     char grade;
//     cout << "hwo many emplu" << endl;
//     cin >> empCout;

//     for (int i = 1; i <= empCout; i++)
//     {
//         cout << "id" << endl;
//         cin >> empId;
//         cout << "name" << endl;
//         cin >> name;
//         cout << "monthly salary" << endl;
//         cin >> monthlySalary;
//         cout << "is perm" << endl;
//         cin >> isperm;
//         cout << "grade" << endl;
//         cin >> grade;
//     }
//     cout << empId << name << monthlySalary << isperm << grade << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int temp;
    int cold = 0;
    int hot = 0;
    int normal = 0;

    for (int i = 1; i <= 7; i++)
    {
        cout << "temperatur" << endl;
        cin >> temp;
        if (temp < 20)
        {
            cout << "cold" << endl;
            cold++;
        }
        else if (temp > 20 && temp < 30)
        {
            cout << "normal" << endl;
            normal++;
        }
        else if (temp > 30)
        {
            cout << "hot" << endl;
            hot++;
        }
    }
    cout << cold << hot << normal << endl;
}