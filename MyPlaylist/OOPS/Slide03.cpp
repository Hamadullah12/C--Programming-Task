// EMPLOYEE & COMPANY — Static Concepts Complete Reference
// Every point from the checklist is covered here in order.
//
// Topics covered:
//   1.  Automatic vs Static variables
//   2.  Static local variable inside a function
//   3.  Instances of a class — each object is a separate universe
//   4.  Why you cannot access class members without an object
//   5.  Static components of a class — shared among all objects
//   6.  Static member variable — defined outside using ::
//   7.  Static member variable as a counter — constructor increments, destructor decrements
//   8.  Private static member variable — protected from outside
//   9.  Static member function — called without any object
//   10. Static function via class name — Company::HowMany()
//   11. Static function via object name — e.HowMany()
//   12. Static -> Static interaction       — always possible
//   13. Static -> Non-Static interaction   — NOT possible, syntax error
//   14. Non-Static -> Static interaction   — always possible
//   15. Non-Static -> Non-Static interaction — always possible

#include <iostream>
using namespace std;

// -- POINT 1 & 2: Automatic vs Static local variable --
// This function demonstrates the difference before we even touch classes.

void automaticExample()
{
    // Automatic variable — created fresh every call, dies at }
    // No memory between calls. Always starts from 0.
    // Note: "auto int" was the old C++ syntax. In modern C++ just write "int".
    // Every normal local variable is automatic by default.
    int x = 0;
    x++;
    cout << "Automatic x : " << x << endl;
}

void staticExample()
{
    // Static local variable — created ONCE on first call.
    // Never reset. Stays alive for the whole program.
    // This is NOT a class member — just a local static inside a function.
    static int x = 0;
    x++;
    cout << "Static x : " << x << endl;
}

// -- CLASS DEFINITION --

class Employee
{
private:
    // -- POINT 3: Instance variables — unique to each object --
    // Every Employee object gets its own copy of these.
    // Changing C1's name does not affect C2's name.
    // Each object is a completely separate universe of data.
    string name;
    int empID;
    double salary;

    // -- POINT 8: Private static member variable --
    // Static but private — shared across all objects but
    // protected from outside access. Nobody can read or change
    // it directly. We expose it only through a static function.
    static int totalEmployees;
    static double totalSalaryBudget;

public:
    // Constructor
    Employee(string name, int empID, double salary);

    // -- POINT 7: Destructor --
    // Called automatically when an object is destroyed.
    // We decrement the counter here so totalEmployees stays accurate.
    // Syntax: ~ClassName() — tilde before the class name, no parameters, no return type.
    ~Employee();

    // Instance (non-static) functions
    void display() const;
    void setSalary(double newSalary);

    // -- POINT 9: Static member function --
    // Belongs to the class itself, not any object.
    // Can be called without creating any object at all.
    // Can ONLY access static variables — it has no idea which
    // object called it, so it cannot touch name, empID, or salary.
    static void HowMany();
    static void showBudget();

    // -- POINT 13: This function is here to DEMONSTRATE the error --
    // A static function trying to access a non-static variable.
    // It is commented out below in the definition — read the comment there.
    static void illegalAccess();
};

// -- STATIC VARIABLE DEFINITIONS --
// -- POINT 6: Must be defined outside the class using :: --
// Written once here. Exist before any object is created.

int Employee::totalEmployees = 0;
double Employee::totalSalaryBudget = 0;

// -- FUNCTION DEFINITIONS --

// Constructor
// -- POINT 7: Increments counter when a new object is born --
Employee::Employee(string name, int empID, double salary)
{
    this->name = name;
    this->empID = empID;
    this->salary = salary;

    totalEmployees++;            // one more employee joined the company
    totalSalaryBudget += salary; // add their salary to company budget
    cout << name << " joined. Total employees now: " << totalEmployees << endl;
}

// Destructor
// -- POINT 7: Decrements counter when an object is destroyed --
// Called automatically — you never call ~Employee() manually.
// Runs when: object goes out of scope, or program ends.
Employee::~Employee()
{
    totalEmployees--;
    totalSalaryBudget -= salary;
    cout << name << " left. Total employees now: " << totalEmployees << endl;
}

// -- POINT 15: Non-Static -> Non-Static interaction — always possible --
// display() is non-static, name/empID/salary are non-static.
// A non-static function always knows which object called it,
// so it can freely access that object's variables.
void Employee::display() const
{
    cout << "\nName   : " << name << endl;
    cout << "ID     : " << empID << endl;
    cout << "Salary : " << salary << endl;
}

// -- POINT 14: Non-Static -> Static interaction — always possible --
// setSalary() is non-static but it updates totalSalaryBudget which is static.
// Non-static functions can always reach static variables — no restriction.
void Employee::setSalary(double newSalary)
{
    totalSalaryBudget -= salary;    // remove old salary from budget
    salary = newSalary;             // update individual salary
    totalSalaryBudget += newSalary; // add new salary to budget
    cout << name << "'s salary updated to " << salary << endl;
}

// -- POINT 9 & 12: Static -> Static interaction — always possible --
// HowMany() is static, totalEmployees is static.
// Static functions can only talk to other static things.
void Employee::HowMany()
{
    cout << "\nTotal Employees : " << totalEmployees << endl;
}

void Employee::showBudget()
{
    cout << "Total Salary Budget : " << totalSalaryBudget << endl;
}

// -- POINT 13: Static -> Non-Static interaction — NOT possible --
// A static function has no object attached to it.
// It does not know whose name, empID, or salary to access.
// The compiler will give an error: "invalid use of member in static member function"
void Employee::illegalAccess()
{
    // cout << name << endl;   // ERROR — which object's name? static has no idea.
    // cout << empID << endl;  // ERROR — same reason.
    // cout << salary << endl; // ERROR — same reason.

    // Only static variables are accessible here:
    cout << totalEmployees << endl; // fine — static can access static
}

// -- MAIN FUNCTION --

int main()
{
    // -- POINT 1 & 2: Automatic vs Static local variable demo --
    cout << "-- automatic variable (always resets) --" << endl;
    automaticExample(); // prints 1
    automaticExample(); // prints 1
    automaticExample(); // prints 1

    cout << "\n-- static local variable (remembers) --" << endl;
    staticExample(); // prints 1
    staticExample(); // prints 2
    staticExample(); // prints 3

    cout << "\n-- creating employee objects --" << endl;

    // -- POINT 3: Each object is a separate universe --
    // E1 and E2 have their own name, empID, salary.
    // Changing E1's salary does not touch E2's salary.
    Employee E1("Ali", 1001, 50000);
    Employee E2("Hamad", 1002, 60000);
    Employee E3("Ahmed", 1003, 45000);

    // -- POINT 4: You cannot access class members without an object --
    // These lines would cause a compiler error:
    // name = "test";       // ERROR — which object's name?
    // display();           // ERROR — display() needs an object to work on
    // You must always say E1.display() or E2.display()

    cout << "\n-- displaying individual employees --" << endl;
    E1.display();
    E2.display();

    cout << "\n-- testing setSalary (non-static -> static interaction) --" << endl;
    E1.setSalary(55000);

    // -- POINT 10: Static function called using class name --
    // No object needed. This is the proper professional way.
    cout << "\n-- static function via class name --" << endl;
    Employee::HowMany();
    Employee::showBudget();

    // -- POINT 11: Static function called using object name --
    // This also works — but it is misleading because it looks like
    // the function belongs to E1, when it actually belongs to the class.
    // Most programmers prefer the class name way above.
    cout << "\n-- static function via object name (same result) --" << endl;
    E1.HowMany();
    E2.HowMany();

    // -- POINT 7: Destructor demo --
    // When the block below ends, E4 goes out of scope and is destroyed.
    // The destructor runs automatically and decrements totalEmployees.
    cout << "\n-- destructor demo --" << endl;
    {
        Employee E4("Zara", 1004, 70000);
        Employee::HowMany(); // 4 employees
    } // E4 is destroyed here — destructor called automatically
    Employee::HowMany(); // back to 3 employees

    // When main ends, E1, E2, E3 are all destroyed automatically too.
    // Watch the destructor messages print at the very end.
    cout << "\n-- end of main, remaining objects destroyed --" << endl;

    return 0;
}