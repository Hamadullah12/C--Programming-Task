#include <iostream>
using namespace std;
void rakatCounter(int &totalSunnah, int &totalFarz, int &totalWitar)
{
    int farz, sunnah, witar;
    for (int i = 1; i <= 5; i++)
    {
        if (i == 1)
        {
            cout << "Fajar Prayer" << endl;
            cout << "Enter sunnah rakkah.\n";
            cin >> sunnah;
            cout << "Enter farz rakkah.\n";
            cin >> farz;
        }
        else if (i == 2)
        {
            cout << "Zuhur Prayer" << endl;
            cout << "Enter sunnah rakkah.\n";
            cin >> sunnah;
            cout << "Enter farz rakkah.\n";
            cin >> farz;
            cout << "Enter Sunnah Rakkah\n";
            cin >> sunnah;
        }
        else if (i == 3)
        {
            cout << "Asar Prayer" << endl;
            cout << "Enter sunnah rakkah.\n";
            cin >> sunnah;
            cout << "Enter farz rakkah.\n";
            cin >> farz;
        }

        else if (i == 4)
        {
            cout << "Maghrib Prayer" << endl;
            cout << "Enter farz rakkah.\n";
            cin >> farz;
            cout << "Enter sunnah rakkah.\n";
            cin >> sunnah;
        }
        else if (i == 5)
        {
            cout << "Isha Prayer" << endl;
            cout << "Enter sunnah rakkah.\n";
            cin >> sunnah;
            cout << "Enter farz rakkah.\n";
            cin >> farz;
            cout << "Enter sunnah rakkah\n";
            cin >> sunnah;
            cout << "Enter Witar rakkah.\n";
            cin >> witar;
        }

        totalSunnah = totalSunnah + sunnah;
        totalFarz = totalFarz + farz;
        totalWitar = witar;
    }
}
int main()
{
    int totalSunnah = 0;
    int totalFarz = 0;
    int totalWitar = 0;
    rakatCounter(totalSunnah, totalFarz, totalWitar);
    int total = totalFarz + totalSunnah + totalWitar;
    cout << "Total Fard rakkah per day : " << totalFarz << endl;
    cout << "Total Sunnah rakkah per day : " << totalSunnah << endl;
    cout << "Witar rakkah in isha prayer : " << totalWitar << endl;
    cout << "Total Sunnah and fard rakkah and witar per day : " << total << endl;

    return 0;
}