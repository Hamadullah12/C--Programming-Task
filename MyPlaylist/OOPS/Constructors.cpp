#include <iostream>
using namespace std;
class Customer
{
    string name;
    int acc_num;
    int balance;

public:
    // Default Constructor:
    Customer()
    {
        name = "Hamad";
        acc_num = 189383;
        balance = 67398;
    }
    // constructor overloading : when function names are same but taking different parameter.
    // PARAMETARIZED CONSTRUCTOR:
    // Customer(string name, int acc_num, int balance)
    // {
    //     // this mehod stores the address of main object
    //     this->name = name;
    //     this->acc_num = acc_num;
    //     this->balance = balance;
    // }
    // constructor should not have same number of parameter
    // INLINE CONSTRUCTOR
    inline Customer(string a, int ac, int b) : name(a), acc_num(ac), balance(b) {}
    void Display()
    {
        cout << name << " " << acc_num << " " << balance << endl;
    }
    // DESTRUCTOR: It is an instance member of a function that is invoked automatically whenver an object is going to be destroyed
    // Is is a last function that is going to be called before an obj is destroyed.
    // object does not delete in this it delete the dynamic allocated memory when program ends.
    // destructor will always be in reverese order .the last obj destructor will run first.
    ~Customer()
    {
        cout << "Name" << name << endl;
        cout << "Destroyed" << endl;
    }
};
int main()
{
    Customer A1;
    Customer A2("Hmd", 3345, 1987); // parametarized constructor.
    A1.Display();
    A2.Display();
    return 0;
}