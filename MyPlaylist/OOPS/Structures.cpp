// Structures: It is user defined contiguous data type that group variables of different type under a single name..

#include <iostream>
using namespace std;
struct Employee // here employe is a data type just like int and double and char..
{
    int id;
    double salary;
    string department;
};

int main()
{
    Employee Manager;
    Manager.id = 234;
    Manager.salary = 25000.0;
    Manager.department = "Mineral";
    cout << "Employee id         :" << Manager.id << endl;
    cout << "Employee Salary     :" << Manager.salary << endl;
    cout << "Employee Department :" << Manager.department << endl;
    return 0;
}