// // // #include <iostream>
// // // using namespace std;
// // // int main()
// // // {
// // //     // Printing table of 6 using do while loop

// // //     int i = 1;
// // //     // int j = 6;
// // //     do
// // //     {
// // //         // cout << "Table of 6 is " << j << " x " << i << " = " << j * i << endl;
// // //         // cout << i * 6 << endl;

// // //         i++;
// // //     } while (i <= 10);
// // // }

// // // Even And Odd number finder
// // // #include <iostream>
// // // using namespace std;
// // // int main()
// // // {
// // //     int i = 1;
// // //     do
// // //     {
// // //         if (i % 2 == 0)
// // //         {
// // //             cout << "Even" << i << endl;
// // //         }
// // //         else
// // //         {
// // //             cout << "Odd " << i << endl;
// // //         }
// // //         i++;
// // //     } while (i <= 30);
// // // }

// // // Count down
// // // #include <iostream>
// // // using namespace std;
// // // int main()
// // // {
// // //     int i = 10;
// // //     do
// // //     {
// // //         cout << " The coutdown starts .." << i << endl;
// // //         i--;
// // //     } while (i >= 1);
// // // }
// // // ========================================================================
// // // Day 2 Break and Continue
// // // Break : When we want to break the loop in runing so we use break, it will exit the loop.
// // // #include <iostream>
// // // using namespace std;
// // // int main()
// // // {
// // //     for (int i = 0; i < 5; i++)
// // //     {
// // //         if (i == 2)
// // //         {
// // //             break;
// // //         }
// // //         cout << i << endl;
// // //     }
// // //     return 0;
// // // }
// // // Continue:THe purpose of using continue keyword is that it will skip the value where continue is applied
// // // and complete the loop when the continue value condition comes true so it didnt go down and print the value
// // // it directly goes up to the loop . it will not break the loop its use to skip the value which we dont want
// // // as in the below program the even numbers are skiped without disturbing the loop
// // // #include <iostream>
// // // using namespace std;
// // // int main()
// // // {
// // //     for (int i = 0; i < 20; i++)
// // //     {
// // //         if (i % 2 == 0)
// // //         {
// // //             continue;
// // //         }
// // //         cout << i << endl;
// // //     }

// // //     return 0;
// // // }

// // // Practice program

// // // #include <iostream>
// // // using namespace std;
// // // int main()
// // // {
// // //     int num;
// // //     for (int i = 0; i < 10; i++)
// // //     {
// // //         cout << "input any number?" << endl;
// // //         cin >> num;
// // //         if (num < 0)
// // //         {
// // //             cout << "You entered negative value so this is skipped " << endl;
// // //             continue;
// // //         }
// // //         else if (num == 0)
// // //         {
// // //             cout << "You entered 0 so the loop is break" << endl;
// // //             break;
// // //         }
// // //     }
// // //     cout << "You entered" << num << endl;
// // //     return 0;
// // // }

// // // ========================================================================
// // // POINTERS : Is a data type which store the address of other data types "&" address of operator "*" is a dereference  operator

// // // #include <iostream>
// // // using namespace std;
// // // int main()
// // // {
// // //     int a = 5;
// // //     int *b = &a;
// // //     cout << "Address of a (&a): " << &a << endl;                // here the address will be same as we assign them to each other "0x5ffe94"
// // //     cout << "Value stored in b (address of a):  " << b << endl; // here the address will be same as we assign them to each other "0x5ffe94"
// // //     cout << "the value of a in b is = " << *b << endl;          // Now if we want to find the value at the addres of b we will use derefence operator  "*".

// // //     // cout << "The value of b on address a is " << *b << endl;

// // //     // POINTER TO POINTER
// // //     int **c = &b;

// // //     cout << "Address of b (&b): " << &b << endl;

// // //     cout << "Value stored in c (address of b): " << c << endl;
// // //     cout << "Value at *c (same as b, address of a): " << *c << endl;
// // //     cout << "Value at **c (value of a): " << **c << endl;

// // //     return 0;
// // // }

// // // ARRAYS AND POINTERS
// // // ARRAY :It is a collection of items of similar type stored in a contingous memory locations.

// // #include <iostream>
// // using namespace std;
// // int main()
// // {
// //     //     int marks[5] = {23, 43, 54, 23, 65};
// //     //     int mathMarks[5] = {456, 234, 554, 231, 653};
// //     //     cout << "These are math marks array" << endl;
// //     //     // Here i want to change the value of some items from array.
// //     //     // cout << "I change the value of some array  items " << endl;
// //     //     // mathMarks[0] = 1;
// //     //     // mathMarks[1] = 2;
// //     //     // mathMarks[2] = 3;
// //     //     // cout << mathMarks[0] << endl
// //     //     //      << mathMarks[1] << endl
// //     //     //      << mathMarks[2] << endl
// //     //     //      << mathMarks[3] << endl
// //     //     //      << mathMarks[4] << endl;
// //     //     //   PRINTING MATHS MARKS ITEMS ARRAY USING FOR LOOP
// //     //     for (int i = 0; i < 5; i++)
// //     //     {
// //     //         cout << "The value of maths marks " << i << " is " << mathMarks[i] << endl;
// //     //     }
// //     //     cout << "These are marks arry" << endl;

// //     //     // here i also want to change the value of some items from array.
// //     //     // cout << "I change the value of some array  items " << endl;

// //     //     // marks[0] = 4;
// //     //     // marks[1] = 5;
// //     //     // marks[2] = 6;
// //     //     // cout << marks[0] << endl
// //     //     //      << marks[1] << endl
// //     //     //      << marks[2] << endl
// //     //     //      << marks[3] << endl
// //     //     //      << marks[4] << endl;

// //     //     // PRINTING ARRAYS ITEMS OF MARKS USING DO WHILE LOOPS

// //     //     int i = 0;
// //     //     do
// //     //     {
// //     //         cout << "The value of marks " << i << " is " << marks[i] << endl;
// //     //         i++;
// //     //     } while (i < 5);
// //     // pointer arithmetic in arrays. :

// //     // int *p = marks;
// //     // cout << "The value of at addres p is " << *p << endl;
// //     // cout << "The value of at addres p+1 is " << *(++p) << endl;
// //     // cout << "The value of at addres p+2 is " << *(++p) << endl;
// //     // cout << "The value of at addres p+3 is " << *(++p) << endl;
// //     // cout << "The value of at addres p+4 is " << *(++p) << endl;

// //     return 0;
// // }

// // FUNCTION : BREAK YOUR PROGRAM INTO SMALL PIECES , DO ONCE AND USE FOREVER .
// // RETURN VALUE FUNCTION
// // We can say that when we pass values to arguments so the function copies the argurment values into function paramters
// // so always remember the fucntion will change the value of parameter not arguments as we see that we pass values to sum function and it updates in
// // the paramters .

// #include <iostream>
// using namespace std;
// int sum(int a, int b)
// {
//     int c = a + b;
//     return c;
// }
// int main()
// {
//     int num1, num2;
//     cout << "Enter two numbers " << endl;
//     cin >> num1 >> num2;
//     cout << "The sum is " << sum(num1, num2) << endl;
//     return 0; // it always means that your program is succesfully exeecuted.
// }

// // // FUCNTION PROTOTYPES : Is is used when sometimes we declared function at the end of the main so to tell
// // the compiler as the fucntion are to be executed later so we just  decalared function at the start.

// #include <iostream>
// using namespace std;
// int sumOfProto(int a, int b);
// void greet();
// int main()
// {
//     int valuea, valueb;
//     cout << "Please enter two values ?" << endl;
//     cin >> valuea >> valueb;
//     cout << "The sum of function sum of prototype is " << sumOfProto(valuea, valueb) << endl;
//     greet();
// }
// int sumOfProto(int a, int b)
// {
//     int c = a + b;
//     return c;
// }
// void greet()
// {
//     cout << "hello world" << endl;
// }
// when to use void and return function
// If the function sending the vlaue back we have to use return type
// If the function is not sending back the value use void , jsut for display output and update value through reference

// Practice problem

// #include <iostream>
// using namespace std;
// void myData(string name, string address, int num)
// {
//     cout << "My name  is " << name << endl;
//     cout << "My address is " << address << endl;
//     cout << "My number is " << num << endl;
// }
// int main()
// {
//     string myName, myAdd;
//     int myNum;
//     cout << "WHat is your name ?" << endl;
//     getline(cin, myName);
//     cout << "What is your address" << endl;
//     getline(cin, myAdd);
//     cout << "What is your mobile number ?" << endl;
//     cin >> myNum;
//     myData(myName, myAdd, myNum);
//     return 0;
// }

// CALL BY VALUE AND CALL BY REFERNCE
// If we have to modify the original values we have to use call by refernce.
// For actual swapping we have to use reference paramter and reference pointer
// #include <iostream>
// using namespace std;
// // void swap(int a, int b)//this is not the correct method to swap
// // void swapRefe(int &a, int &b)
// void swapPoin(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main()
// {
//     cout << "======================" << endl;
//     int x = 7, y = 5;
//     cout << "Value of a before swap" << x << endl
//          << "Value of b before swap" << y << endl;
//     // swap(x, y);this will not swap the values it just copies the value to the pararmeter
//     // swapRefe(x, y);this was using reference parameter
//     // swapPoin(&x, &y);this swap is performed using pointer reference nethod
//     cout << "The value of a after swapping is " << x << endl;
//     cout << "The value of b after swapping is " << y << endl;
//     return 0;
// }

// PRACTICE PROBLEM ON REFERENCE
// #include <iostream>
// using namespace std;
// void increaseNum(int &x)
// {
//     // x = x + 5;
//     x = x * 2;
// }
// int main()
// {
//     int a = 10;
//     // cout << "Value of a before adding five  =" << a << endl;
//     cout << "Value of a before doubling it  =" << a << endl;
//     increaseNum(a);
//     // cout << "Value of a after adding five = " << a << endl;
//     cout << "Value of a after doubling it= " << a << endl;

//     return 0;
// }

// INCREASING ARRAY ELEMENTS USING REFRENCE PARAMTER

// #include <iostream>
// using namespace std;
// void increaseArr(int &arrElem)
// {
//     arrElem = arrElem + 30;
// }
// int main()
// {
//     int arr[5] = {1, 34, 32, 54, 34};
//     cout << "Before updating " << endl;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << "THe value at " << i << " = " << arr[i] << endl;
//     }
//     increaseArr(arr[0]);
//     cout << "After updating array elemnt " << endl;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << "THe value at " << i << " = " << arr[i] << endl;
//     }

//     return 0;
// }
// #include <iostream>
// using namespace std;
// void arrRet(int &arrElem)
// {
//     arrElem += 30;
// }
// int main()
// {
//     int arr[3] = {23, 43, 23};
//     cout << "Before Updating " << endl;
//     for (int i = 0; i < 3; i++)
//     {
//         cout << "Array Elements" << arr[i] << endl;
//     }
//     arrRet(arr[0]);
//     arrRet(arr[1]);
//     cout << "After updating" << endl;
//     for (int i = 0; i < 3; i++)
//     {
//         cout << "Array Elements " << arr[i] << endl;
//     }
//     return 0;
// }

// default pareameter

// #include <iostream>
// using namespace std;
// double interestRate(int savings, double rateFactor = 2.34)
// {
//     return savings * rateFactor;
// }
// int main()
// {
//     int mySavings = 200000;
//     cout << "if you have that money " << mySavings << "in your bank account you will recience that much amount " << interestRate(mySavings) << " After 1 year " << endl;
//     // hrer we are overridng the value
//     cout << "if you have that money " << mySavings << "in your bank account you will recience that much amount " << interestRate(mySavings, 1.03) << " After 1 year " << endl;
//     return 0;
// }

// ARRAYS:

// #include <iostream>
// using namespace std;
// int main()
// {
//     const int numberOfEmpl = 4;
//     int hours_worked[numberOfEmpl];
//     for (int i = 0; i < numberOfEmpl; i++)
//     {
//         cout << "How many hours of work have done in this week ?" << endl;
//         cin >> hours_worked[i];
//     }
//     cout << "Each employe has worked for that much hours in this week " << endl;
//     for (int i = 0; i < numberOfEmpl; i++)
//     {
//         cout << "Hourse worked by each employe" << " [ " << i << " ] " << hours_worked[i] << endl;
//     }

//     return 0;
// }

// practice paper question on poointer

// #include <iostream>
// using namespace std;
// int main()
// {
//     int mobileStock = 50;
//     int *ptr = &mobileStock;
//     cout << "The stock value using pointer ptr is " << *ptr << endl;
//     *ptr -= 10;
//     cout << "THe stock after selling 10 phones is " << *ptr << endl;
//     return 0;
// }

// ARRAYS : SUM OF ELEMENTS IN ARRAY
// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[] = {3, 4, 2, 5, 3, 2, 4};
//     int n = sizeof(arr) / sizeof(arr[0]); // if we dont knwo the size of array
//     // int sum = 0;
//     int prod = 1;
//     cout << n << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//         // sum = sum + arr[i];
//         prod = prod * arr[i];
//     }
//     // cout << "The sum of array element is " << sum << endl;
//     cout << "The product of array element is " << prod << endl;
//     return 0;
// }

// PAPER QUESTIONS:
// Q1:A mobile shop in Pakistan wants to update a customer’s mobile balance after the customer adds recharge.
// Initially, the customer has a mobile balance of Rs. 100. When the customer recharges the balance, Rs. 50 should be added to the existing balance.
// To ensure the balance is updated permanently, the system must use pass by reference.
// Display balance before and after function call in main().

// #include <iostream>
// using namespace std;
// void custRech(int &balance)
// {
//     balance += 50;
// }
// int main()
// {
//     int initialBalance = 100;
//     cout << "balance before update" << initialBalance << endl;
//     custRech(initialBalance);
//     cout << "balnce after recharge update" << initialBalance << endl;
//     return 0;
// }

// Question 02:[CLO-03]
// 2.1
// A college keeps records of student marks for a small class. The marks of the 5 students are already known: 78, 85, 90, 67, 88.
// Write a C++ program that:
// 1. Initializes an array with the marks: 78, 85, 90, 67, 88.
// 2. Take a number from the user to be searched in the array.
// 3. Use search to check whether the mark exists in the array.
// 4. Displays:
// o "Marks <key> found at position <position>" if the mark is found
// o "Marks <key> not found in the array" if the mark does not exist.
// #include <iostream>
// using namespace std;
// int main()
// {
//     int key;
//     int size = 5;
//     int marksArr[size] = {78, 85, 90, 67, 88};
//     cout << "ENTER A NUMBER TO BE SEARCHED IN THE ARRAY." << endl;
//     cin >> key;
//     bool found = false;
//     int position = -1;
//     for (int i = 0; i < size; i++)
//     {
//         if (marksArr[i] == key)
//         {
//             found = true;
//             position = i;
//             break;
//         }
//     }
//     if (found)
//     {
//         cout << "The key is " << key << "found at postion " << position << endl;
//     }
//     else
//     {
//         cout << "The key is not found in the array" << endl;
//     }

//     return 0;
// }

// MAIN QUESTION

// #include <iostream>
// using namespace std;
// // Item cost calculation
// double calculateItemCost(double price, double quantity)
// {
//     return price * quantity;
// }
// // total bill calculation
// double calculateTotalBill(double cost1, double cost2, double cost3, double cost4)
// {
//     return cost1 + cost2 + cost3 + cost4;
// }
// void displayReceipt(double fc, double sc, double oc, double rc, double total)
// {
//     cout << "Utility Store Corporation of Pakistan " << endl;
//     cout << "The cost of flour is " << fc << endl;
//     cout << "The cost of sugar is " << sc << endl;
//     cout << "The cost of oil is " << oc << endl;
//     cout << "THe cost or rice is " << rc << endl;
//     cout << "The total cost of grocery is " << total << endl;
// }
// int main()
// {
//     double flourPrice = 120.0;
//     double sugarPrice = 150.0;
//     double oilPrice = 500.0;
//     double ricePrice = 200.0;
//     int fq, sq, oq, rq;
//     cout << "How much is the quantity of flour " << endl;
//     cin >> fq;
//     cout << "How much is the quantity of sugar " << endl;
//     cin >> sq;
//     cout << "How much is the quantity of oil " << endl;
//     cin >> oq;
//     cout << "How much is the quantity of rice " << endl;
//     cin >> rq;
//     double flourCost = calculateItemCost(flourPrice, fq);
//     double sugarCost = calculateItemCost(sugarPrice, sq);
//     double oilCost = calculateItemCost(oilPrice, oq);
//     double riceCost = calculateItemCost(ricePrice, rq);

//     double totalBill = calculateTotalBill(flourCost, sugarCost, oilCost, riceCost);
//     displayReceipt(flourCost, sugarCost, oilCost, riceCost, totalBill);
//     return 0;
// }

// 2D ARRAY
// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[3][4] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     cout << "Displaying the table ====" << endl;
//     for (int row = 0; row < 3; row++)
//     {
//         for (int col = 0; col < 4; col++)
//         {
//             cout << arr[row][col] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[4] = {34, 23, 23, 12};
//     int sum = 0;
//     for (int i = 0; i < 4;  i++)
//     {
//         cout << "Array Elemnt to be added to sum " << arr[i] << endl;
//         sum += arr[i];
//     }
//     cout << "THe sum of an array is " << sum << endl;
//     return 0;
// }

// QUESTION 1 — Passing Array to Function (CORE)

// A company stores salaries of 5 employees.

// Write a program that:

// Stores salaries in an array

// Passes the array to a function displaySalaries()

// The function prints all salaries

// No printing should be done in main()

// #include <iostream>
// using namespace std;
// void displaySalaries(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         cout << "The salareis of employe si " << arr[i] << endl;
//     }
// }
// int main()
// {
//     const int sizeOfEmpl = 5;
//     int arrOfEmp[sizeOfEmpl];
//     cout << "ENter your salaries." << endl;
//     for (int i = 0; i < sizeOfEmpl; i++)
//     {
//         cin >> arrOfEmp[i];
//     }
//     displaySalaries(arrOfEmp, sizeOfEmpl);
//     return 0;
// }

// QUESTION 2 — Array + Function + Return Value

// Write a program that :

//     Stores marks of 6 students in an array

//         Passes the array to a function
//         calculateSum()

//             The function returns the sum of marks

//     main() prints the returned sum

//     Focus :

//     Array passed to function

//     Return value from function

#include <iostream>
using namespace std;
int calculateSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int arrOfStu[6];
    cout << "Enter your marks " << endl;
    for (int i = 0; i < 6; i++)
    {
        cin >> arrOfStu[i];
    }
    int totalSum = calculateSum(arrOfStu, 6);
    cout << "The total sum is " << totalSum << endl;
    return 0;
}