// BANK SYSTEM — Pointers Complete Reference
// Every point from the checklist covered in one program.
//
// Topics covered:
//   1.  Memory Locations and Addresses
//   2.  Variable Content vs Variable Address
//   3.  Pointer Declaration and Syntax
//   4.  Pointer Types
//   5.  Address-of Operator (&)
//   6.  Dereference Operator (*)
//   7.  Null Pointers
//   8.  Pointer Arithmetic
//   9.  Pointer Subtraction
//   10. sizeof Operator
//   11. Arrays and Pointers
//   12. Indexing vs Pointer Offset Notation
//   13. Static vs Dynamic Allocation
//   14. new keyword
//   15. delete keyword
//   16. Dangling Pointers
//   17. Dynamic Arrays with Runtime Sizing

#include <iostream>
using namespace std;

// -------------------------------------------------------
// POINT 1 & 2: Memory Architecture
// -------------------------------------------------------
// Every variable you declare gets a slot in memory.
// That slot has two things:
//   CONTENT  — the actual value stored inside  (e.g. 4500)
//   ADDRESS  — the location of that slot in RAM (e.g. 0x61fe14)
//
// Think of RAM like a row of lockers in a bank.
// Each locker has a NUMBER (address) and CONTENTS (value).
// The address never changes. The content can change anytime.
//
// You already know how to read content:   cout << balance;
// The & operator lets you read the address: cout << &balance;
// -------------------------------------------------------

// -------------------------------------------------------
// POINT 3 & 4: Pointer Declaration
// -------------------------------------------------------
// A pointer is a variable that stores an ADDRESS, not a value.
//
// Syntax:   dataType * pointerName;
//
// The type matters — an int* pointer expects to point at an int.
// A double* pointer expects to point at a double.
// This is because when you dereference (read the value at the address),
// the compiler needs to know how many bytes to read.
//   int    = 4 bytes
//   double = 8 bytes
//   char   = 1 byte
//
// int*    ptr;   points to an int
// double* ptr;   points to a double
// char*   ptr;   points to a char
// -------------------------------------------------------

// -------------------------------------------------------
// POINT 7: Null Pointer
// -------------------------------------------------------
// A pointer that is not pointing at anything yet should be
// set to zero or NULL. This is called a null pointer.
// Never leave a pointer uninitialized — it will point at
// random memory and cause unpredictable crashes.
//
// int* ptr = 0;     old C style
// int* ptr = NULL;  also valid
// int* ptr = nullptr; modern C++ style (best practice)
// -------------------------------------------------------

int main()
{
    cout << "-- SECTION 1: Address vs Content --" << endl;

    // Two normal bank variables
    int balance = 4500;
    int acc_num = 2983948;

    // Content — what you normally use
    cout << "balance content : " << balance << endl;
    cout << "acc_num content : " << acc_num << endl;

    // Address — where they live in RAM
    // & is the address-of operator — gives you the memory address
    cout << "balance address : " << &balance << endl;
    cout << "acc_num address : " << &acc_num << endl;
    // Notice the addresses are different — each variable has its own locker

    cout << "\n-- SECTION 2: Pointer Declaration and Assignment --" << endl;

    // POINT 3, 4, 5: Declaring a pointer and storing an address in it
    // ptr now holds the ADDRESS of balance, not the value 4500
    int *ptr = &balance;

    cout << "ptr holds address  : " << ptr << endl;      // same as &balance
    cout << "balance address is : " << &balance << endl; // confirms they match

    cout << "\n-- SECTION 3: Dereference Operator --" << endl;

    // POINT 6: The * operator in front of a pointer means
    // "go to that address and read what is there"
    // This is called dereferencing — following the address to get the value
    cout << "value at ptr (*ptr) : " << *ptr << endl; // prints 4500

    // You can also CHANGE the value through the pointer
    // This changes balance itself — ptr is just pointing at it
    *ptr = 6000;
    cout << "balance after *ptr = 6000 : " << balance << endl; // prints 6000
    // balance changed even though we never wrote "balance = 6000"
    // because ptr was pointing at balance's memory location

    cout << "\n-- SECTION 4: Null Pointer --" << endl;

    // POINT 7: Always initialize pointers you are not using yet
    int *nullPtr = nullptr;
    cout << "nullPtr value : " << nullPtr << endl; // prints 0

    // Checking before using — good habit
    if (nullPtr == nullptr)
        cout << "nullPtr is not pointing at anything yet." << endl;

    cout << "\n-- SECTION 5: Pointer Arithmetic --" << endl;

    // POINT 8: Adding and subtracting integers from pointers
    // When you do ptr + 1, it does NOT add 1 byte.
    // It moves forward by sizeof(type) bytes.
    // For int* that is 4 bytes forward.
    // This is how arrays work internally.

    int balances[5] = {1000, 2000, 3000, 4000, 5000};
    int *arrPtr = balances; // points to first element

    cout << "arrPtr points to    : " << *arrPtr << endl;       // 1000
    cout << "arrPtr + 1 points to: " << *(arrPtr + 1) << endl; // 2000
    cout << "arrPtr + 2 points to: " << *(arrPtr + 2) << endl; // 3000
    // Each +1 jumps exactly 4 bytes (size of int) forward in memory

    // POINT 9: Pointer Subtraction
    // Subtracting two pointers tells you how many elements are between them
    int *firstPtr = &balances[0];
    int *lastPtr = &balances[4];
    cout << "distance between first and last : " << lastPtr - firstPtr << endl;
    // prints 4 — there are 4 steps between index 0 and index 4

    // POINT 10: sizeof operator
    // Tells you how many bytes a type or variable occupies
    cout << "\nsizeof(int)    : " << sizeof(int) << " bytes" << endl;  // 4
    cout << "sizeof(double) : " << sizeof(double) << " bytes" << endl; // 8
    cout << "sizeof(char)   : " << sizeof(char) << " bytes" << endl;   // 1
    cout << "sizeof(int*)   : " << sizeof(int *) << " bytes" << endl;  // 8 on 64-bit
    // All pointer types are the same size regardless of what they point to
    // because they all store a memory address, and addresses are always the same size

    cout << "\n-- SECTION 6: Arrays and Pointers --" << endl;

    // POINT 11: Array name IS a constant pointer to the first element
    // balances and &balances[0] are the same thing
    cout << "balances address    : " << balances << endl;
    cout << "&balances[0] address: " << &balances[0] << endl;
    // They print the same address — proof that the array name is a pointer

    // POINT 12: Indexing vs Pointer Offset Notation
    // These two ways of reading array elements are IDENTICAL internally
    cout << "\nReading balances array two ways:" << endl;
    for (int i = 0; i < 5; i++)
    {
        // arr[i] is just shorthand — compiler converts it to *(arr + i) anyway
        cout << "Index notation    balances[" << i << "] = " << balances[i] << endl;
        cout << "Pointer notation *(balances+" << i << ") = " << *(balances + i) << endl;
    }

    cout << "\n-- SECTION 7: Static vs Dynamic Allocation --" << endl;

    // POINT 13: Static allocation — size decided at COMPILE TIME
    // The compiler reserves exactly this much memory before the program runs.
    // You must know the size in advance. Cannot resize later.
    int fixedAccounts[5]; // always 5, no matter what
    cout << "Static array of 5 accounts created at compile time." << endl;

    // POINT 13: Dynamic allocation — size decided at RUNTIME
    // Memory is reserved while the program is running.
    // You can ask the user for the size — you do not need to know it in advance.
    // Memory comes from the HEAP (a large pool of free memory).
    // Static variables live on the STACK (smaller, auto-managed).

    cout << "\nHow many bank accounts do you want to create? ";
    int n;
    cin >> n;

    // POINT 14: new keyword
    // Allocates n integers on the heap at runtime
    // Returns a pointer to the first element
    int *accounts = new int[n];

    // Fill with sample balances
    for (int i = 0; i < n; i++)
    {
        accounts[i] = (i + 1) * 1000; // 1000, 2000, 3000 ...
    }

    cout << "\nDynamic accounts created:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Account " << i + 1 << " balance : " << accounts[i] << endl;
    }

    // POINT 15 & 16: delete keyword and Dangling Pointers
    // Heap memory is NOT released automatically — you must free it manually.
    // If you forget, that memory stays occupied for the whole program (memory leak).
    // After delete, always set pointer to nullptr.
    // If you don't, the pointer still holds the old address — this is a DANGLING POINTER.
    // Using a dangling pointer causes undefined behavior (crash or garbage values).

    delete[] accounts;  // [] because it was an array — always match new[] with delete[]
    accounts = nullptr; // immediately set to null — prevents dangling pointer

    cout << "\nMemory released. accounts set to nullptr." << endl;

    if (accounts == nullptr)
        cout << "accounts is now null — safe, no dangling pointer." << endl;

    cout << "\n-- SECTION 8: Single Object with new and delete --" << endl;

    // POINT 14 & 15: new and delete for a single variable (not array)
    // Use new without [] and delete without []
    double *salaryPtr = new double; // allocates one double on heap
    *salaryPtr = 75000.50;
    cout << "Heap salary : " << *salaryPtr << endl;

    delete salaryPtr; // no [] for single variable
    salaryPtr = nullptr;
    cout << "Single heap variable released." << endl;

    cout << "\n-- SECTION 9: Dangling Pointer Danger Demo --" << endl;

    // POINT 16: What happens if you use a pointer after delete
    // This is commented out because it is ILLEGAL and causes crashes.
    // It is here just so you can see what NOT to do.

    int *dangerPtr = new int;
    *dangerPtr = 9999;
    cout << "Before delete: " << *dangerPtr << endl;

    delete dangerPtr;
    // dangerPtr still holds the old address — it is now a dangling pointer
    // cout << *dangerPtr << endl; // ILLEGAL — memory was freed, value is garbage

    dangerPtr = nullptr; // correct fix — always do this after delete
    cout << "After delete and nullptr: dangerPtr is safe." << endl;

    return 0;
}