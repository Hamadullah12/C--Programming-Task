// // // #include <iostream>
// // // #include <string>
// // // using namespace std;

// // // int inputMarks()
// // // {
// // //     int m1, m2, m3;
// // //     cout << "Enter marks for 3 subjects:\n";
// // //     cin >> m1 >> m2 >> m3;
// // //     return m1 + m2 + m3;
// // // }

// // // float calcPercentage(int total)
// // // {
// // //     return (total / 300.0) * 100;
// // // }

// // // char getGrade(float percentage)
// // // {
// // //     if (percentage >= 80)
// // //         return 'A';
// // //     else if (percentage >= 70)
// // //         return 'B';
// // //     else if (percentage >= 60)
// // //         return 'C';
// // //     else if (percentage >= 50)
// // //         return 'D';
// // //     else
// // //         return 'F';
// // // }

// // // string resultStatus(char grade)
// // // {
// // //     if (grade == 'F')
// // //         return "Fail";
// // //     else
// // //         return "Pass";
// // // }

// // // void printReport()
// // // {
// // //     int total = inputMarks();
// // //     float percentage = calcPercentage(total);
// // //     char grade = getGrade(percentage);
// // //     string status = resultStatus(grade);

// // //     cout << "\nTotal = " << total << endl;
// // //     cout << "Percentage = " << percentage << endl;
// // //     cout << "Grade = " << grade << endl;
// // //     cout << "Status = " << status << endl;
// // // }

// // // int main()
// // // {
// // //     printReport();
// // //     return 0;
// // // }

// // // TASK 2
// // #include <iostream>
// // using namespace std;

// // int calculateTotal(int marks[], int n)
// // {
// //     int sum = 0;
// //     for (int i = 0; i < n; i++)
// //         sum += marks[i];
// //     return sum;
// // }

// // float calculateAverage(int marks[], int n)
// // {
// //     return calculateTotal(marks, n) / (float)n;
// // }

// // int findHighest(int marks[], int n)
// // {
// //     int max = marks[0];
// //     for (int i = 1; i < n; i++)
// //         if (marks[i] > max)
// //             max = marks[i];
// //     return max;
// // }

// // int findLowest(int marks[], int n)
// // {
// //     int min = marks[0];
// //     for (int i = 1; i < n; i++)
// //         if (marks[i] < min)
// //             min = marks[i];
// //     return min;
// // }
// // int countPass(int marks[], int n)
// // {
// //     int count = 0;
// //     for (int i = 0; i < n; i++)
// //         if (marks[i] >= 50)
// //             count++;
// //     return count;
// // }
// // int countFail(int marks[], int n)
// // {
// //     return n - countPass(marks, n);
// // }
// // void printReport(int marks[], int n)
// // {
// //     cout << "\nTotal Marks = " << calculateTotal(marks, n) << endl;
// //     cout << "Average Marks = " << calculateAverage(marks, n) << endl;
// //     cout << "Highest Marks = " << findHighest(marks, n) << endl;
// //     cout << "Lowest Marks = " << findLowest(marks, n) << endl;
// //     cout << "Number of Students Passed = " << countPass(marks, n) << endl;
// //     cout << "Number of Students Failed = " << countFail(marks, n) << endl;
// // }
// // int main()
// // {
// //     int n;
// //     cout << "Enter number of students: ";
// //     cin >> n;

// //     int marks[n];
// //     cout << "Enter marks:\n";
// //     for (int i = 0; i < n; i++)
// //         cin >> marks[i];

// //     printReport(marks, n);
// //     return 0;
// // }

// // task 3
// #include <iostream>
// using namespace std;

// int main()
// {
//     int rows = 6;
//     int seatsPerRow = 8;
//     int reserved = 0;
//     int available = 0;

//     cout << "Seminar Hall Seating Arrangement:\n\n";

//     for (int i = 1; i <= rows; i++)
//     {
//         for (int j = 1; j <= seatsPerRow; j++)
//         {
//             if (j == 2)
//             {
//                 cout << "R ";
//                 reserved++;
//             }
//             else
//             {
//                 cout << "A ";
//                 available++;
//             }
//         }
//         cout << endl;
//     }

//     cout << "\nTotal Seats: " << rows * seatsPerRow << endl;
//     cout << "Reserved Seats: " << reserved << endl;
//     cout << "Available Seats: " << available << endl;

//     return 0;
// }
