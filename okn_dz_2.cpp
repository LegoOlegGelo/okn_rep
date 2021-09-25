#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int m, d;
    cout << "Номер месяца: ";
    cin >> m;
    cout << "Число: ";
    cin >> d;

    if (d > 31)
    {
        cout << "Слишком большое число!" << endl;
        return -1;
    }

    int D = 0;

    switch (m - 1)
    {
        case 11: D += 30;
        case 10: D += 31;
        case 9: D += 30;
        case 8: D += 31;
        case 7: D += 31;
        case 6: D += 30;
        case 5: D += 31;
        case 4: D += 30;
        case 3: D += 31;
        case 2: D += 28;
        case 1: D += 31; 
        case 0: D += d; break;
        default: cout << "Неправильный номер месяца!" << endl; return -2;
    }

    cout << endl << "До НГ осталось " << 365 - D << " дней!" << endl << endl;

    return 0;
}
