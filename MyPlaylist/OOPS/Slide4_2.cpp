// BANK SYSTEM — Pointers Complete Reference (Set 04 + Set 05)
//
// HOW TO READ THIS FILE:
// Read it top to bottom like a story. Every section builds on the previous one.
// Run it, observe the output, then re-read the comments for that section.
//
// MENTAL MODEL TO KEEP IN MIND THROUGHOUT:
// RAM is like a street of numbered houses (addresses).
// Every variable you declare gets a house on that street.
// The house NUMBER is the address. What is INSIDE the house is the value.
// A pointer is a piece of paper that has a house number written on it.
// Dereferencing means: go to that house and look inside.

#include <iostream>
using namespace std;

class BankAccount
{
private:
    string ownerName;
    int accNumber;
    double balance;

public:
    // Default constructor — used when no values are given at creation
    BankAccount()
    {
        ownerName = "Unknown";
        accNumber = 0;
        balance = 0.0;
        cout << "  [constructor called] default — " << ownerName << endl;
    }

    // Parameterized constructor
    BankAccount(string name, int accNum, double bal)
    {
        ownerName = name;
        accNumber = accNum;
        balance = bal;
        cout << "  [constructor called] " << ownerName << " account created." << endl;
    }

    // Destructor
    ~BankAccount()
    {
        cout << "  [destructor called] " << ownerName << " account destroyed." << endl;
    }

    void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
    }

    void display() const
    {
        cout << "  Owner   : " << ownerName << endl;
        cout << "  Acc No  : " << accNumber << endl;
        cout << "  Balance : " << balance << endl;
    }

    string getName() const { return ownerName; }
    double getBalance() const { return balance; }
};

int main()
{
    // ===========================================================
    // SLIDE SET 04 — THE ABSOLUTE BASICS
    // ===========================================================

    cout << "\n--- 1. Variable Content vs Address ---" << endl;
    // Every variable has two things:
    //   CONTENT  — the value you store        e.g. 4500
    //   ADDRESS  — where it lives in RAM       e.g. 0x61fe14
    //
    // Addresses are shown in HEXADECIMAL (base 16: 0-9 then A-F).
    // You will see things like 0x7ffd... — that is just a RAM location number.
    // The 0x prefix means "this number is in hex."

    double balance = 4500.0;
    int accNum = 101;

    cout << "balance content  : " << balance << endl;
    cout << "balance address  : " << &balance << endl; // & gives address
    cout << "accNum  content  : " << accNum << endl;
    cout << "accNum  address  : " << &accNum << endl;
    // Notice addresses are in hex and different for each variable

    cout << "\n--- 2. Pointer Declaration and the * Symbol ---" << endl;
    // A pointer is a variable whose content IS an address.
    // Syntax:  dataType * pointerName;
    // The * in a declaration means "this is a pointer variable"
    //
    // WHY type-specific?
    // int*    — knows to read 4 bytes when dereferencing
    // double* — knows to read 8 bytes when dereferencing
    // char*   — knows to read 1 byte  when dereferencing
    // The type tells the compiler HOW MUCH memory to read at that address.
    //
    // INDIRECTION means going through an address to reach a value.
    // Instead of working with the value directly, you work through a middle step:
    //   direct:    balance = 4500   (you touch the value itself)
    //   indirect:  *ptr    = 4500   (you go through the address to reach the value)

    double *ptr = &balance; // ptr now holds the ADDRESS of balance

    cout << "ptr content (address it holds) : " << ptr << endl;
    cout << "balance address (&balance)     : " << &balance << endl;
    // They are identical — ptr is storing balance's address

    cout << "\n--- 3. The Dereference Operator ---" << endl;
    // * in front of a pointer means "go to that address and read what is there"
    // This is called DEREFERENCING — following the pointer to its destination.
    //
    // Declaration:    double* ptr   — * means "ptr is a pointer"
    // Dereferencing:  *ptr          — * means "go to the address ptr holds"
    // Same symbol, two different meanings depending on context.

    cout << "value at ptr (*ptr) : " << *ptr << endl; // reads balance = 4500

    *ptr = 7500.0; // goes to balance's address and writes 7500 there
    cout << "balance after *ptr = 7500 : " << balance << endl;
    // balance changed even though we wrote *ptr not balance
    // because ptr was pointing at balance's exact memory location

    cout << "\n--- 4. Uninitialized and Null Pointers ---" << endl;
    // UNINITIALIZED POINTER — declared but not assigned any address.
    // It holds a random garbage address leftover in memory.
    // Using it causes crashes or corrupts other variables.
    // NEVER do this:  int* badPtr;  then use *badPtr
    //
    // NULL POINTER — a pointer explicitly set to zero.
    // It means "I am not pointing at anything right now."
    // Safe to check. Unsafe to dereference (will crash with clear error).
    //
    // Three ways to write null:
    //   int* p = 0;        old C style
    //   int* p = NULL;     also valid
    //   int* p = nullptr;  modern C++ — best practice

    double *safePtr = nullptr;
    cout << "null pointer value : " << safePtr << endl; // prints 0

    if (safePtr == nullptr)
        cout << "safePtr is null — not pointing at anything yet." << endl;

    safePtr = &balance; // now give it a real address before using
    cout << "safePtr after assignment : " << *safePtr << endl;

    cout << "\n--- 5. Pointer Arithmetic ---" << endl;
    // Adding or subtracting an integer from a pointer moves it
    // by that many ELEMENTS, not that many bytes.
    // Moving by 1 on an int* jumps 4 bytes (sizeof int).
    // Moving by 1 on a double* jumps 8 bytes (sizeof double).
    // This is why the type matters — it controls the step size.

    double bankBalances[5] = {1000, 2500, 3750, 4200, 9000};
    double *aPtr = bankBalances; // points to first element

    cout << "aPtr     (index 0) : " << *aPtr << endl;       // 1000
    cout << "aPtr + 1 (index 1) : " << *(aPtr + 1) << endl; // 2500
    cout << "aPtr + 2 (index 2) : " << *(aPtr + 2) << endl; // 3750

    // Pointer subtraction — distance between two pointers in elements
    double *firstPtr = &bankBalances[0];
    double *lastPtr = &bankBalances[4];
    cout << "distance (last - first) : " << lastPtr - firstPtr << endl; // 4

    // sizeof operator — how many bytes each type occupies
    cout << "\nsizeof(int)     : " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(double)  : " << sizeof(double) << " bytes" << endl;
    cout << "sizeof(char)    : " << sizeof(char) << " bytes" << endl;
    cout << "sizeof(double*) : " << sizeof(double *) << " bytes" << endl;
    // All pointer types are the same size — they all store an address
    // and addresses are always 8 bytes on a 64-bit system

    cout << "\n--- 6. Array Names as Constant Pointers ---" << endl;
    // The array name IS the address of the first element.
    // bankBalances and &bankBalances[0] are the same thing.
    // The difference: you cannot reassign the array name (it is constant).
    // You CAN reassign a regular pointer.

    cout << "bankBalances        : " << bankBalances << endl;
    cout << "&bankBalances[0]    : " << &bankBalances[0] << endl;
    // Identical addresses — confirms array name is a pointer

    // Indexing vs Pointer Offset Notation — both do exactly the same thing
    // arr[i]      is just shorthand for      *(arr + i)
    // The compiler converts arr[i] to *(arr+i) internally anyway
    cout << "\nTwo ways to read the same array:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "bankBalances[" << i << "] = " << bankBalances[i]
             << "  |  *(bankBalances+" << i << ") = " << *(bankBalances + i) << endl;
    }

    cout << "\n--- 7. Static vs Dynamic Allocation ---" << endl;
    // STATIC (compile-time):
    //   Size must be known before the program runs.
    //   Memory comes from the STACK — small, fast, auto-managed.
    //   Automatically freed when the variable goes out of scope.
    //   Example: int accounts[10]; — always 10, decided by you the programmer.
    //
    // DYNAMIC (runtime):
    //   Size can be decided while the program is running.
    //   Memory comes from the HEAP — large pool, manually managed.
    //   You must free it yourself with delete. If you forget — memory leak.
    //   Example: int* accounts = new int[n]; — n entered by user at runtime.

    cout << "How many transaction records to store? ";
    int n;
    cin >> n;

    // new keyword — allocates n doubles on the heap, returns pointer to first
    double *transactions = new double[n];

    for (int i = 0; i < n; i++)
        transactions[i] = (i + 1) * 500.0;

    cout << "Transactions stored:" << endl;
    for (int i = 0; i < n; i++)
        cout << "  transactions[" << i << "] = " << transactions[i] << endl;

    // delete[] — frees the heap array. [] because it was allocated with new[]
    // Always match:  new[]  with  delete[]
    //                new    with  delete
    delete[] transactions;
    transactions = nullptr; // immediately null — prevents dangling pointer
    cout << "Heap memory released. transactions = nullptr." << endl;

    cout << "\n--- 8. Dangling Pointer ---" << endl;
    // After delete, the pointer still holds the old address.
    // That memory has been returned to the heap — it may be reused by anything.
    // Using that pointer now is ILLEGAL and causes crashes or garbage output.
    // The fix is always: set to nullptr immediately after delete.

    double *danglingDemo = new double;
    *danglingDemo = 9999.99;
    cout << "Before delete : " << *danglingDemo << endl;
    delete danglingDemo;
    // *danglingDemo here would be ILLEGAL — memory is gone
    danglingDemo = nullptr;
    cout << "After delete + nullptr — pointer is safe." << endl;

    // ===========================================================
    // SLIDE SET 05 — OBJECTS AND POINTERS
    // ===========================================================

    cout << "\n\n========== SLIDE SET 05 ==========" << endl;

    cout << "\n--- 9. Automatic Object vs Dynamic Object ---" << endl;
    // AUTOMATIC OBJECT — declared normally, lives on the stack.
    //   Created when the line is reached.
    //   Destroyed automatically when its block { } ends.
    //   You have no control over when it dies.
    //
    // DYNAMIC OBJECT — created with new, lives on the heap.
    //   Created exactly when YOU say new.
    //   Destroyed exactly when YOU say delete.
    //   This is "on-demand" existence — you control the lifecycle.

    cout << "\nAutomatic object (stack):" << endl;
    {
        BankAccount autoAcc("Hamad", 201, 5000); // constructor runs here
        autoAcc.display();
    } // destructor runs HERE automatically — block ended

    cout << "\n--- 10. Dynamic Object Lifecycle ---" << endl;
    // new  triggers the constructor automatically
    // delete triggers the destructor automatically
    // Parameterless constructor: new BankAccount  OR  new BankAccount()
    // Both are identical — () is optional when no arguments needed.

    cout << "\nDynamic object (heap) — parameterless constructor:" << endl;
    BankAccount *ptr1 = new BankAccount(); // constructor called by new
    ptr1->display();
    delete ptr1; // destructor called by delete
    ptr1 = nullptr;

    cout << "\nDynamic object (heap) — parameterized constructor:" << endl;
    BankAccount *ptr2 = new BankAccount("Ahmed", 202, 8000);
    ptr2->display();
    delete ptr2;
    ptr2 = nullptr;

    cout << "\n--- 11. Stack vs Heap Memory Regions ---" << endl;
    // THE STACK:
    //   Where automatic variables and objects live.
    //   Grows and shrinks automatically as functions are called and return.
    //   Small in size. Fast to allocate. No manual management needed.
    //   When a block ends — everything in it is gone.
    //
    // THE HEAP:
    //   Where dynamic (new) variables and objects live.
    //   Large pool of memory. Slow to allocate. Must manage manually.
    //   Stays alive until YOU call delete — does not matter which block you are in.
    //   If you never delete — memory leak (wasted RAM for entire program run).

    cout << "Stack object dies at end of its block." << endl;
    cout << "Heap object lives until delete is called." << endl;

    cout << "\n--- 12. Accessing Members via Pointer ---" << endl;
    // When you have a pointer to an object, you cannot use . directly.
    // You have two options:
    //
    // Option A: Dereference then dot  (*ptr).member
    //   The () are required — without them . has higher priority than *
    //   and the compiler tries to do ptr.member first which is wrong.
    //
    // Option B: Arrow operator  ptr->member
    //   Shorthand for (*ptr).member — does exactly the same thing.
    //   Cleaner to read. This is what everyone uses in practice.
    //   -> literally means "go to the object this pointer points at, then access member"

    BankAccount *accPtr = new BankAccount("Zara", 203, 12000);

    cout << "\nUsing (*ptr).member syntax:" << endl;
    cout << "  Name    : " << (*accPtr).getName() << endl;
    cout << "  Balance : " << (*accPtr).getBalance() << endl;

    cout << "\nUsing ptr->member syntax (same result):" << endl;
    cout << "  Name    : " << accPtr->getName() << endl;
    cout << "  Balance : " << accPtr->getBalance() << endl;

    accPtr->deposit(3000);
    cout << "  After deposit(3000) : " << accPtr->getBalance() << endl;

    delete accPtr;
    accPtr = nullptr;

    cout << "\n--- 13. Dynamic Array of Objects ---" << endl;
    // new BankAccount[n] — creates n BankAccount objects on the heap.
    // Default constructor is called for EACH object automatically.
    // Access elements with [] just like a normal array.
    // delete[] calls the destructor for EACH object then frees memory.

    int count = 3;
    cout << "\nCreating dynamic array of " << count << " accounts:" << endl;
    BankAccount *bankArray = new BankAccount[count]; // 3 default constructors called

    // Use arrow with array index to access members
    // bankArray[i] gives you the object, then -> or . accesses the member
    // Since bankArray[i] is the object itself (not a pointer), use . here
    bankArray[0].deposit(1000);
    bankArray[1].deposit(2000);
    bankArray[2].deposit(3000);

    cout << "\nDisplaying all accounts in dynamic array:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "Account " << i << ":" << endl;
        bankArray[i].display();
    }

    cout << "\nDeleting dynamic array (destructors called for each):" << endl;
    delete[] bankArray; // destructor called for each of the 3 objects
    bankArray = nullptr;

    cout << "\n--- 14. Array of Pointers to Objects ---" << endl;
    // This is different from a dynamic array of objects.
    // Here the array stores POINTERS, and each pointer points to its own object.
    // Each object is created independently with its own new.
    //
    // Built-in array (int, double) — array name is a constant pointer, no ->needed
    // Object array with pointers  — each element is a pointer, use -> to access
    //
    // Syntax:  BankAccount* ptrArray[3];
    // This is an array of 3 pointers. Each pointer needs its own new and delete.

    cout << "\nCreating array of pointers to objects:" << endl;
    BankAccount *ptrArray[3];

    ptrArray[0] = new BankAccount("Ali", 301, 5000);
    ptrArray[1] = new BankAccount("Bilal", 302, 7500);
    ptrArray[2] = new BankAccount("Sara", 303, 3200);

    // ptrArray[i] is a POINTER — so use -> to access members
    cout << "\nAccessing members via pointer array:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Account " << i << " owner   : " << ptrArray[i]->getName() << endl;
        cout << "Account " << i << " balance : " << ptrArray[i]->getBalance() << endl;
    }

    // Each pointer needs its own delete
    cout << "\nDeleting each object individually:" << endl;
    for (int i = 0; i < 3; i++)
    {
        delete ptrArray[i];
        ptrArray[i] = nullptr;
    }

    cout << "\n--- 15. Construction and Destruction Order ---" << endl;
    // Construction order  — objects are created in the order new is called.
    // Destruction order   — objects are destroyed in the order delete is called.
    // For automatic objects in the same block — destroyed in REVERSE order.
    // For heap objects — destroyed exactly when YOU call delete, in YOUR order.
    //
    // This matters when predicting console output in exam questions.
    // Always trace: when does new run? when does delete run?
    // Constructor prints when new runs. Destructor prints when delete runs.

    cout << "\nTracing construction and destruction order:" << endl;
    BankAccount *first = new BankAccount("First", 401, 100);
    BankAccount *second = new BankAccount("Second", 402, 200);
    BankAccount *third = new BankAccount("Third", 403, 300);

    // Destroying in a different order than creation
    cout << "\nDeleting second first, then third, then first:" << endl;
    delete second;
    second = nullptr;
    delete third;
    third = nullptr;
    delete first;
    first = nullptr;
    // Destructor messages confirm the exact order

    cout << "\n--- end of main ---" << endl;
    return 0;
}