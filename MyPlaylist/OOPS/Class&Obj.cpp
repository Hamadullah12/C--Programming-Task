// CLASS : IT IS A USER DEFINED CUSTOM DATA TYPE IN WHICH DIFFERENT TYPE OF DATA ARE STROED UNDER A SINGLE NAME.
#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int rollNum;
    float gpa;
    string grade;
    // getter and setter functions
    // using set functionn we have been set teh values .
    // using getter functions we will get the valuesss .
    // To access the private values outside from the class we use getter and setter functions
public:
    void setName(string n)
    {
        name = n; // here string n has now the value of name as n will be stored in name
    }
    void setRoll(int r)
    {
        rollNum = r;
    }
    void setGpa(float m)
    {
        gpa = m;
    }
    void setGrade(string g)
    {
        grade = g;
    }
    // getter function
    void getName()
    {
        cout << name << endl;
    }
    void getRoll()
    {
        cout << rollNum << endl;
    }
    void getGpa()
    {
        cout << gpa << endl;
    }
    void getGrade()
    {
        cout << grade << endl;
    }
};
int main()
{
    Student S1; // here Student is the data type and S1 is the object means real thing is S1 while student is a blueprint.
    //    now here we will access the value using getter and setter function of class private
    S1.setName("Hamad");
    S1.setRoll(13);
    S1.setGpa(3.55);
    S1.setGrade("A-");
    S1.getName();
    S1.getRoll();
    S1.getGrade();
    S1.getGpa();
    return 0;
}