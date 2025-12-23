// #include <iostream>
// using namespace std;

// int main()
// {
//     int marks[5][3];
//     int total[5] = {0};
//     float average[5];
//     int topStudent = 0;

//     for (int i = 0; i < 5; i++)
//     {
//         cout << "Enter marks for Student " << i + 1 << " (Math Physics CS): ";
//         for (int j = 0; j < 3; j++)
//         {
//             cin >> marks[i][j];
//             total[i] += marks[i][j];
//         }
//         average[i] = total[i] / 3.0;
//     }

//     for (int i = 1; i < 5; i++)
//     {
//         if (total[i] > total[topStudent])
//             topStudent = i;
//     }

//     cout << "\nStudent\tMath\tPhysics\tCS\tTotal\tAverage\n";
//     for (int i = 0; i < 5; i++)
//     {
//         cout << i + 1 << "\t";
//         for (int j = 0; j < 3; j++)
//             cout << marks[i][j] << "\t";
//         cout << total[i] << "\t" << average[i] << endl;
//     }

//     cout << "\nTop Scorer: Student " << topStudent + 1 << endl;

//     return 0;
// }

// second task

#include <iostream>
using namespace std;

int main()
{
    int sales[4][7];
    int weeklyTotal[4] = {0};
    int bestShop = 0;
    int maxSale = 0;
    int maxDay = 0;

    string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter sales for Shop " << i + 1 << " (Mon to Sun): ";
        for (int j = 0; j < 7; j++)
        {
            cin >> sales[i][j];
            weeklyTotal[i] += sales[i][j];

            if (sales[i][j] > maxSale)
            {
                maxSale = sales[i][j];
                maxDay = j;
            }
        }
    }

    for (int i = 1; i < 4; i++)
    {
        if (weeklyTotal[i] > weeklyTotal[bestShop])
            bestShop = i;
    }

    cout << "\nShop\tMon\tTue\tWed\tThu\tFri\tSat\tSun\tTotal\n";
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << "\t";
        for (int j = 0; j < 7; j++)
            cout << sales[i][j] << "\t";
        cout << weeklyTotal[i] << endl;
    }

    cout << "\nShop with Highest Weekly Sales: Shop "
         << bestShop + 1
         << " (Total = " << weeklyTotal[bestShop] << ")\n";

    cout << "Day with Maximum Sales Overall: "
         << days[maxDay]
         << " (Sales = " << maxSale << ")\n";

    return 0;
}
