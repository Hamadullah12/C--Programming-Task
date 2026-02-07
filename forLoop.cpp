// #include <iostream>
// using namespace std;
// int main()
// {
//     string name;
//     int qty;
//     double price, total, discount, tax, finalAmount;
//     cout << "Enter details for three items with their name, price & quantity." << endl;
//     for (int i = 1; i <= 3; i++)
//     {
//         cout << "Item " << i << "name :" << endl;
//         cin >> name;
//         cout << "Price of " << name << ":" << endl;
//         cin >> price;
//         cout << "Quantity of " << name << ":" << endl;
//         cin >> qty;

//         float itemTotal = price * qty;
//         cout << "Total amount for " << name " : " << itemTotal << endl;
//         total += itemTotal;
//     }
//     cout << "Total bill before discount is : " << total << endl;
//     if (total > 5000)
//     {
//         discount = total * (10 / 100);
//     }
//     else if (total >= 2000 && total < 5000)
//     {
//         discount = total * (5 / 100);
//     }
//     else
//     {
//         cout << "Not elegible for discount" << endl;
//     }
//     cout << "discount applied" << discount << endl;
//     float afterDiscount = total - discount;
//     tax = afterDiscount * (8 / 100);
//     finalAmount = afterDiscount + tax;

//     cout << "8% tax : " << tax << endl;
//     cout << "final amount to pay : " << finalAmount << endl;
//     return 0;
// }

// Q 1 : Display first 10 natural numbers?

// #include <iostream>
// using namespace std;
// int main()
// {
//     // for (int i = 1; i < 10; i++)
//     for (int i = 10; i > 0; i--)
//     {
//         cout << i << " " << endl;
//     }
//     return 0;
// }

// {
//     for (int i = 0; i < 100; i++)
//     {
//         if (i % 2 != 0)
//             cout << "odd number : " << i << endl;
//     }
// }
// {
//     int first, second;
//     cout << "first number" << endl;
//     cin >> first;
//     cout << "second" << endl;
//     cin >> second;
//     for (int i = first; i < second; i++)
//     {
//         if (i % 2 == 0)
//             cout << " even" << i << endl;
//     }
//     return 0;
// }
// {
//     int sum = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         sum = sum + i;
//         cout << "sum is " << sum << endl;
//     }
// }
// {
//     int pro = 1;
//     for (int i = 1; i < 10; i++)
//     {
//         pro = pro * i;
//         cout << "pro is " << pro << endl;
//     }
// }

// practice questions:
// Question 1 Write a C++ program to calculate the commission of a salesperson based on the following:
//  Input: Sales amount (float). Commission rules: Sales ≥ 100000 → 12% commission Sales between 50000 and 99999 → 8%
//  commission Sales < 50000 → 5% commission.
//   If sales exceed 150000, reduce the commission by 3% due to tax deduction.
//    Display commission and total income (sales + commission after reduction).

// #include <iostream>
// using namespace std;
// int main()
// {

//     float salesAmount, finalAmount, commission, taxDeduction;
//     cout << "How much sales do you made?" << endl;
//     cin >> salesAmount;
//     if (salesAmount >= 100000)
//     {
//         commission = salesAmount * (12.0 / 100);
//     }
//     else if (salesAmount >= 50000 && salesAmount <= 99999)
//     {
//         commission = salesAmount * (8.0 / 100);
//     }
//     else
//     {
//         commission = salesAmount * (5.0 / 100);
//     }

//     if (salesAmount > 150000)
//     {
//         taxDeduction = commission - (commission * 3.0 / 100);
//     }
//     finalAmount = salesAmount + commission;
//     cout << "Commission on based of sales : " << commission << endl;
//     cout << "Commission on based of sales deducted amount : " << taxDeduction << endl;
//     cout << "Total amount after adding commission : " << finalAmount << endl;
//     return 0;
// }

// Set 2 – Based on Billing, Discount, and Tax Calculation Logic

// These test loops, conditionals, totals, and arithmetic operations.

// Question 1
// Write a C++ program that:
// Takes 4 products (name, price, quantity)
// Calculates total price for each and total bill.
// Applies:
// 15% discount if total ≥ 10000
// 7% discount if total ≥ 5000 and < 10000
// Otherwise, no discount.
// Adds 10% tax after discount.
// Displays total before discount, discount, tax, and final bill.

// #include <iostream>
// using namespace std;
// int main()
// {
//     string name;
//     int price, qty, discount, tax, itemBill;
//     float total, totalBill;
//     cout << "Please provide the details of items ,price and quantity" << endl;
//     for (int i = 1; i <= 4; i++)
//     {
//         cout << "Item : " << i << "   name" << endl;
//         cin >> name;
//         cout << "Item Price " << name << " : " << endl;
//         cin >> price;
//         cout << "Item Quantity " << name << " : " << endl;
//         cin >> qty;
//         itemBill = qty * price;
//         cout << "Item Bill is " << itemBill << endl;
//         total += itemBill;
//     }
//     if (total >= 10000)
//     {
//         discount = total * (15.0 / 100);
//     }
//     else if (total > 5000 && total < 10000)
//     {
//         discount = total * (7.0 / 100);
//     }
//     else
//     {
//         cout << "No discount" << endl;
//     }
//     totalBill = discount + total;
//     tax = totalBill * (10.0 / 100);
//     cout << "Total bill before discount and tax :" << total << endl;
//     cout << "Discount on bill is : " << discount << endl;
//     cout << "Tax amount : " << tax << endl;
//     cout << "Final bill is : " << totalBill << endl;
//     return 0;
// }

// using switch statements

// #include <iostream>
// using namespace std;

// int main()
// {
//     int choice;
//     float total = 0;

//     cout << "==== Welcome to Hamad's Restaurant ====\n";
//     cout << "1. Burger - 250\n";
//     cout << "2. Pizza  - 800\n";
//     cout << "3. Fries  - 150\n";
//     cout << "4. Roll   - 200\n";
//     cout << "5. Drink  - 100\n";
//     cout << "=======================================\n";

//     // Take 3 orders
//     for (int i = 1; i <= 3; i++)
//     {
//         cout << "Enter your choice (1-5) for item " << i << ": ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             total += 250;
//             cout << "Burger added!\n";
//             break;
//         case 2:
//             total += 800;
//             cout << "Pizza added!\n";
//             break;
//         case 3:
//             total += 150;
//             cout << "Fries added!\n";
//             break;
//         case 4:
//             total += 200;
//             cout << "Roll added!\n";
//             break;
//         case 5:
//             total += 100;
//             cout << "Drink added!\n";
//             break;
//         default:
//             cout << "Invalid choice! No item added.\n";
//             i--;
//             break;
//         }
//     }

//     cout << "\n===============================\n";
//     cout << "Your total bill: Rs. " << total << endl;
//     cout << "Thank you for dining with us!\n";
//     cout << "===============================\n";

//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string userDefined = "admin";
//     string passwordDefined = "password123";
//     string username, password;
//     for (int i = 1; i <= 3; i++)
//     {
//         cout << "Type your username" << endl;
//         cin >> username;
//         cout << "Type your password" << endl;
//         cin >> password;
//         if (username == userDefined && password == passwordDefined)
//         {
//             cout << "Login succesfull" << endl;
//             break;
//         }
//         else
//         {
//             cout << "Acces denied" << endl;
//         }
//     }
//     return 0;
// }