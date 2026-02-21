// Structures: It is user defined contiguous data type that group variables of different type under a single name..

#include <iostream>
using namespace std;
struct Employee // here employe is a data type just like int and double and char..
{
    int id;
    double salary;
    string department;
};
void printData(Employee emp)
{
    cout << "Employee id         : " << emp.id << endl;
    cout << "Employee salary     : " << emp.salary << endl;
    cout << "Employee id         : " << emp.department << endl;
}

int main()
{

   // SIMPLEE ASSIGNING DATA WITHOUT ARRAYS
    // Employee Manager;
    // Manager.id = 234;
    // Manager.salary = 25000.0;
    // Manager.department = "Mineral";
    // cout << "Employee id         :" << Manager.id << endl;
    // cout << "Employee Salary     :" << Manager.salary << endl;
    // cout << "Employee Department :" << Manager.department << endl;
    // handling data of more than one employee using array
    // Employee team[3];
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

    // ASSIGNING DATA TO EMPLOYESS USING FOR LOOP
    Employee team[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Your Id ?" << endl;
        cin >> team[i].id;
        cout << "Enter your salary ? " << endl;
        cin >> team[i].salary;
        cout << "Enter your department" << endl;
        cin >> team[i].department;
    }
    for (int j = 0; j < 3; j++)
    {
        printData(team[j]);
    }
    return 0;
}