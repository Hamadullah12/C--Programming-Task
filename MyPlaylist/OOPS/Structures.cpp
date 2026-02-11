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
    // handling data of more than one employee using array
    Employee team[3];
    // IDS ARE APPOINTED
    // team[0].id = 1;
    // team[1].id = 2;
    // team[2].id = 3;
    // // Now setting the salaries to employess
    // team[0].salary = 50000;
    // team[1].salary = 45000;
    // team[2].salary = 67000;
    // // now appointing to departments
    // team[0].department = "Sales";
    // team[1].department = "IT";
    // team[2].department = "Controlling";

    // SIMPLEE ASSIGNING DATA WITHOUT ARRAYS
    // Employee Manager;
    // Manager.id = 234;
    // Manager.salary = 25000.0;
    // Manager.department = "Mineral";
    // cout << "Employee id         :" << Manager.id << endl;
    // cout << "Employee Salary     :" << Manager.salary << endl;
    // cout << "Employee Department :" << Manager.department << endl;
    return 0;
}