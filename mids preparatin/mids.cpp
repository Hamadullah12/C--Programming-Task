// What is a Program Made Of

// 🟢 Write a C++ program that prints your name on the screen.
// 🟡 Write a C++ program that displays your name and your roll number on separate lines using multiple cout statements.
// 🔴 Write a program that displays your name, class, and your favorite quote in a formatted way using escape sequences (\n, \t).

// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main()
// {
// 1st question
// int roll = 12;
// cout << "Hamad" << endl;
// cout << roll << endl;
// cout << "My favourite quote is that failure will come distraction will come you have to be focused and consistent \n";
// cout << "Class is 13 \t"; //\t is using for providing space between twoo statment in one line.
// cout << "Good luck for exam\n";

//  Q2 :Write a short program using at least three different C++ keywords (int, float, return).
// 🟡 Create a program that declares different data types using their keywords and prints them.
// 🔴 Write a program that intentionally uses a keyword as an identifier and observe (and explain) the compiler error.

// int bank = 120000;
// float result = 87.78;
// char A = 'A';
// long big = 2345;
// cout << bank << result << A << big << endl;

// Q 3 :Declare integer and float variables and print their values.
// 🟡 Assign literal values to variables and perform addition.
// 🔴 Use constants (const) to store pi and radius, then calculate area of a circle.

// const float pi = 3.145;
// float radius = 14.88;
// double Area = (4 * pi) * radius * radius;
// cout << "areda" << Area << endl;
//   Q:4  //
// Print different integer literals (decimal, octal, hex).
// 🟡 Add two integer literals and display result.
// 🔴 Demonstrate overflow by using an int value beyond its limit and display result
// int decimal = 234;
// int octa = 0476;
// int hexa = 0x345;
// cout << "octa " << octa << endl;
// cout << "hexa " << hexa << endl;
// int largeNumber = 2147483647;
// cout << "large number " << largeNumber << endl;
// largeNumber += 1;
// cout << "Over flow occurs " << largeNumber << endl;

//     Store a single letter in char and print it.
// 🟡 Read a character from user input and display its ASCII value.
// 🔴 Check whether a given character is a vowel or consonant.

// char single;
// double bigNumber;
// cout << "Enter number" << endl;
// cin >> bigNumber;
// int newNumb = static_cast<int>(bigNumber);
// cout << "addd any character\n";
// cin >> single;
// cout << "tolower" << char(tolower(single)) << endl;
// cout << "Its ASCII value is " << float(single) << endl;
// char ch = 'm';
// cout << "The converted valus is " << static_cast<int>(ch) << endl;
// cout << "big number conberted calue " << newNumb << endl;

// int num1 = 987, num2 = 89, num3 = 76, num4 = 9, num5 = 7, num6 = 9;
// double num7 = 98.876;
// double num8 = 56.987646;
// cout << setprecision(3) << fixed << endl;
// cout << setw(5) << num1 << setw(5) << num2 << endl;
// cout << setw(5) << num3 << setw(5) << num4 << endl;
// cout << setw(5) << num5 << setw(5) << num6 << endl;
// cout << setw(5) << num7 << setw(10) << num8 << endl;

// string name;
// cout << "name" << endl;
// getline(cin, name);//to neglet white spaces
// cout << "name" << name;
// return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int choice, quantity;
//     float totalBill = 0;

//     cout << "-----------------------------\n";
//     cout << "🍴 Welcome to Hamad's Restaurant 🍴\n";
//     cout << "-----------------------------\n";

//     // The menu will be shown 5 times
//     for (int i = 1; i <= 5; i++)
//     {
//         cout << "\n------ MENU ------\n";
//         cout << "1. Burger     - Rs. 250\n";
//         cout << "2. Pizza      - Rs. 500\n";
//         cout << "3. Sandwich   - Rs. 200\n";
//         cout << "4. Fries      - Rs. 150\n";
//         cout << "5. Cold Drink - Rs. 100\n";
//         cout << "6. Exit and Generate Bill\n";

//         cout << "\nEnter your choice (1-6): ";
//         cin >> choice;

//         if (choice == 6)
//         {
//             cout << "\nGenerating Bill...\n";
//             break; // exit the for loop
//         }

//         cout << "Enter quantity: ";
//         cin >> quantity;

//         switch (choice)
//         {
//         case 1:
//             cout << quantity << " Burger(s) added to your order.\n";
//             totalBill += 250 * quantity;
//             break;

//         case 2:
//             cout << quantity << " Pizza(s) added to your order.\n";
//             totalBill += 500 * quantity;
//             break;

//         case 3:
//             cout << quantity << " Sandwich(es) added to your order.\n";
//             totalBill += 200 * quantity;
//             break;

//         case 4:
//             cout << quantity << " Fries added to your order.\n";
//             totalBill += 150 * quantity;
//             break;

//         case 5:
//             cout << quantity << " Cold Drink(s) added to your order.\n";
//             totalBill += 100 * quantity;
//             break;

//         default:
//             cout << "❌ Invalid choice! Please select between 1-6.\n";
//         }
//     }

//     cout << "\n-----------------------------\n";
//     cout << "Your Total Bill: Rs. " << totalBill << endl;
//     cout << "Thank you for visiting Hamad's Restaurant! 🍽️\n";
//     cout << "-----------------------------\n";

//     return 0;
// }

// Write a C++ program that displays a menu of mathematical operations to the user and allows them to perform up to 5 calculations using a for loop.
// The menu should include:
// AdditionSubtractionMultiplicationDivisionSquareRootExit

// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
//     int choice;
//     for (;;)
//     {
//         int num1, num2;

//         cout << "Select mathematical operation from 1 to 5 adn to exit enter 6" << endl;
//         cin >> choice;

//         if (choice < 1 || choice > 6)
//         {
//             cout << "enter correct choice  1 to 6" << endl;
//             cout << "enter agian" << endl;
//             continue;
//         }
//         if (choice == 6)
//         {
//             cout << "exiting program" << endl;
//             break;
//         }

//         cout << "Please enter num 1 and num2 for calculation" << endl;
//         cin >> num1 >> num2;

//         switch (choice)
//         {
//         case 1:
//             cout << "Addition\t" << num1 + num2 << endl;
//             break;
//         case 2:
//             cout << "sub\t" << num1 - num2 << endl;
//             break;
//         case 3:
//             cout << "mult\t" << num1 * num2 << endl;
//             break;
//         case 4:
//             if (num2 == 0)
//             {
//                 cout << "enter valid number\t " << endl;
//             }
//             else
//             {
//                 cout << "division\t" << (float)num1 / num2 << endl;
//             }
//             break;
//         case 5:

//             cout << "square of num1  " << pow(num1, 2) << endl;
//             cout << "square of num1  " << pow(num2, 2) << endl;
//             break;

//         default:
//             break;
//         }
//     }

//     return 0;
// }

/*
    🏪 Project: Restaurant Billing & Menu System
    🧠 Concepts Covered: All fundamental C++ topics
    📘 Created by: Hamad (Practice Program)
*/

#include <iostream> // Input/Output Stream
#include <iomanip>  // for setprecision()
#include <cmath>    // for math functions
#include <string>   // for string data type
using namespace std;

// 🚀 Program starts
int main()
{
    // --------------- Variable Declarations -----------------
    int choice;                   // menu item choice
    int quantity;                 // number of items
    float totalBill = 0;          // total bill amount
    const float taxRate = 0.08;   // 8% tax
    string customerName;          // string data type
    char takeAway;                // char data type (Y/N)
    bool discountApplied = false; // bool data type

    // --------------- Program Introduction -----------------
    cout << "========================================\n";
    cout << " 🍔  WELCOME TO HAMAD'S RESTAURANT  🍔\n";
    cout << "========================================\n";

    cout << "Enter your name: ";
    getline(cin, customerName); // input with spaces
    cout << "Welcome, " << customerName << "!\n\n";

    // --------------- Menu Display using for loop -------------
    for (int i = 1; i <= 5; i++)
    {
        cout << "\n------- MENU -------\n";
        cout << "1. Burger        - Rs. 250\n";
        cout << "2. Pizza         - Rs. 500\n";
        cout << "3. Fries         - Rs. 150\n";
        cout << "4. Cold Drink    - Rs. 100\n";
        cout << "5. Exit and Generate Bill\n";
        cout << "---------------------\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Check for valid choice using relational operators
        if (choice < 1 || choice > 5)
        {
            cout << "❌ Invalid choice! Please select again.\n";
            i--; // retry same iteration
            continue;
        }

        // Exit condition
        if (choice == 5)
        {
            cout << "\n🧾 Generating your final bill...\n";
            break;
        }

        // Ask for quantity
        cout << "Enter quantity: ";
        cin >> quantity;

        // Check for overflow (if user enters unrealistic large quantity)
        if (quantity > 1000)
        {
            cout << "⚠️ Overflow Error: Quantity too large! Enter again.\n";
            i--;
            continue;
        }

        // ---------------- Switch Statement ----------------
        switch (choice)
        {
        case 1:
            cout << quantity << " Burger(s) added.\n";
            totalBill += 250 * quantity;
            break;
        case 2:
            cout << quantity << " Pizza(s) added.\n";
            totalBill += 500 * quantity;
            break;
        case 3:
            cout << quantity << " Fries added.\n";
            totalBill += 150 * quantity;
            break;
        case 4:
            cout << quantity << " Cold Drink(s) added.\n";
            totalBill += 100 * quantity;
            break;
        default:
            cout << "Invalid Option.\n";
        }

        // Increment message counter (demonstrate ++ operator)
        cout << "You have selected " << i << " item(s) so far.\n";
    }

    // ---------------- Bill Calculation ----------------
    float tax = totalBill * taxRate; // arithmetic operator
    float grandTotal = totalBill + tax;

    // Apply discount using logical & relational operators
    if (totalBill >= 1000 && totalBill <= 2000)
    {
        grandTotal -= 100; // flat Rs.100 discount
        discountApplied = true;
    }
    else if (totalBill > 2000)
    {
        grandTotal -= 0.10 * grandTotal; // 10% discount
        discountApplied = true;
    }

    // ---------------- Takeaway Option ----------------
    cout << "\nDo you want Takeaway? (Y/N): ";
    cin >> takeAway;

    // Nested if example
    if (takeAway == 'Y' || takeAway == 'y')
    {
        cout << "Packaging charges Rs.50 added.\n";
        grandTotal += 50;
    }
    else if (takeAway == 'N' || takeAway == 'n')
    {
        cout << "Dine-in selected. No extra charges.\n";
    }
    else
    {
        cout << "Invalid choice, assuming Dine-in.\n";
    }

    // ---------------- Type Casting Example ----------------
    int roundedTotal = static_cast<int>(grandTotal); // type casting float → int

    // ---------------- Output with Formatting ----------------
    cout << fixed << setprecision(2);
    cout << "\n============ BILL SUMMARY ============\n";
    cout << "Customer Name: " << customerName << endl;
    cout << "Total Amount: Rs. " << totalBill << endl;
    cout << "Tax (8%): Rs. " << tax << endl;
    if (discountApplied)
        cout << "Discount Applied ✅\n";
    else
        cout << "No Discount ❌\n";
    cout << "Final Amount: Rs. " << grandTotal << endl;
    cout << "Rounded Amount (int): Rs. " << roundedTotal << endl;
    cout << "======================================\n";

    // ---------------- Bool & Logical Check ----------------
    bool highSpender = (grandTotal > 1500);
    if (highSpender)
    {
        cout << "🎉 You’re one of our premium customers!\n";
    }
    else
    {
        cout << "Thank you for dining with us!\n";
    }

    // ---------------- End of Program ----------------
    cout << "\nProgram executed successfully. Goodbye!\n";
    return 0;
}
