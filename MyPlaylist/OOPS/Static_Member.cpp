// ============================================================
//  BANK MANAGEMENT SYSTEM — OOP CONCEPTS PRACTICE
//  Topics covered:
//    1. Classes & Objects
//    2. Access Modifiers (private / public)
//    3. Constructor & this-> pointer
//    4. Getter Functions
//    5. Setter Functions
//    6. Static Member Variables
//    7. Static Member Functions
//    8. Const Functions
//    9. Const Object
//   10. Const Parameters
// ============================================================

#include <iostream>
using namespace std;

// ============================================================
//  CLASS DEFINITION
// ============================================================
class Customer
{
    // --------------------------------------------------------
    //  PRIVATE SECTION
    //  These variables are locked inside the class.
    //  Nobody outside can read or change them directly.
    //  We use getters to READ them and setters to CHANGE them.
    // --------------------------------------------------------
private:
    string name;
    int acc_num;
    int balance;

    // STATIC MEMBERS — shared across ALL objects (one copy in memory)
    // Think of these as "bank-wide" records, not per-customer records.
    static int totalBalance;  // sum of all customer balances
    static int totalCustomer; // count of all customers created

    // --------------------------------------------------------
    //  PUBLIC SECTION
    //  Everything here is accessible from outside the class.
    // --------------------------------------------------------
public:
    // --------------------------------------------------------
    //  CONSTRUCTOR
    //  Called automatically when an object is created.
    //  "this->" is used to separate the parameter name from
    //  the private variable name when they are the same.
    // --------------------------------------------------------
    Customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;

        totalCustomer++;         // one more customer added to the bank
        totalBalance += balance; // add their balance to the bank total
    }

    // --------------------------------------------------------
    //  GETTER FUNCTIONS
    //  Like a window — you can SEE the value but NOT touch it.
    //  Always marked const because they never modify the object.
    // --------------------------------------------------------
    string getName() const { return name; }
    int getAccNum() const { return acc_num; }
    int getBalance() const { return balance; }

    // --------------------------------------------------------
    //  SETTER FUNCTIONS
    //  Like a guarded door — you can CHANGE the value
    //  but only if it passes the security check (validation).
    //  Return type is void because we are saving, not returning.
    // --------------------------------------------------------

    // Setter for name — rejects empty strings
    void setName(string newName)
    {
        if (!newName.empty()) // security check: name must not be empty
        {
            name = newName;
        }
        else
        {
            cout << "Invalid: name cannot be empty." << endl;
        }
    }

    // Setter for balance — directly overwrites the balance.
    // Uses diff trick to keep totalBalance accurate:
    //   diff = newBalance - oldBalance
    //   totalBalance += diff  (adds only the actual change)
    void setBalance(int newBalance)
    {
        if (newBalance >= 0) // security check: balance cannot be negative
        {
            int diff = newBalance - balance; // calculate actual change
            totalBalance += diff;            // update bank total by the diff
            balance = newBalance;            // overwrite individual balance
            cout << "Balance updated successfully." << endl;
        }
        else
        {
            cout << "Invalid: balance cannot be negative." << endl;
        }
    }

    // --------------------------------------------------------
    //  DEPOSIT & WITHDRAW
    //  These are NOT setters — they add/subtract incrementally.
    //  Setters do a direct overwrite; these do a relative change.
    //  const parameter: amount cannot be modified inside the function.
    // --------------------------------------------------------
    void deposit(const int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            totalBalance += amount;
            cout << "Deposit of " << amount << " successful." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(const int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            totalBalance -= amount;
            cout << "Withdrawal of " << amount << " successful." << endl;
        }
        else
        {
            cout << "Invalid withdrawal: insufficient funds or bad amount." << endl;
        }
    }

    // --------------------------------------------------------
    //  DISPLAY — const function
    //  Marked const because it only reads data, never changes it.
    //  A const object can call this safely.
    // --------------------------------------------------------
    void display() const
    {
        cout << "-----------------------------" << endl;
        cout << "Name           : " << name << endl;
        cout << "Account Number : " << acc_num << endl;
        cout << "Balance        : " << balance << endl;
        cout << "-----------------------------" << endl;
    }

    // --------------------------------------------------------
    //  STATIC FUNCTION
    //  Belongs to the CLASS, not to any one object.
    //  Can ONLY access static variables (totalBalance, totalCustomer).
    //  Called using:  Customer::accessStatic()
    // --------------------------------------------------------
    static void accessStatic()
    {
        cout << "=============================" << endl;
        cout << "Total Customers : " << totalCustomer << endl;
        cout << "Total Balance   : " << totalBalance << endl;
        cout << "=============================" << endl;
    }
};

// ============================================================
//  STATIC VARIABLE DEFINITIONS (outside the class)
//  Must be defined once here; initial value is zero.
// ============================================================
int Customer::totalCustomer = 0;
int Customer::totalBalance = 0;

// ============================================================
//  MAIN FUNCTION — Testing all concepts
// ============================================================
int main()
{
    // --- Creating regular customer objects ---
    Customer C1("Hamad", 2983948, 4500);
    Customer C2("Ahmed", 3948, 8900);
    Customer C3("Jawad", 248, 10);
    Customer C4("Ali", 2983948, 8000);
    Customer C5("Hadi", 1900, 3000);

    // --- Testing deposit and withdraw (const parameters) ---
    C5.deposit(2000);
    C2.withdraw(5000);

    // --- Testing getter functions ---
    cout << "C1 name through getter    : " << C1.getName() << endl;
    cout << "C1 balance through getter : " << C1.getBalance() << endl;

    // --- Testing setter functions ---
    C1.setName("Hamad Khan"); // valid — updates name
    C1.setName("");           // invalid — rejected, stays "Hamad Khan"
    cout << "C1 name after setName : " << C1.getName() << endl;

    C1.setBalance(6000); // updates balance using diff trick
    cout << "C1 balance after setBalance : " << C1.getBalance() << endl;

    // --- Displaying individual customers ---
    C1.display();
    C5.display();

    // --- CONST OBJECT ---
    // C6 is locked after creation. Only const functions can be called on it.
    const Customer C6("Zara", 1111, 5000);
    cout << "C6 name    : " << C6.getName() << endl;    // OK — getter is const
    cout << "C6 balance : " << C6.getBalance() << endl; // OK — getter is const
    C6.display();                                       // OK — display is const
    // C6.deposit(100);  // ERROR: deposit() is not const — cannot modify a const object

    // --- Static function — called on the class, not an object ---
    Customer::accessStatic();

    return 0;
}