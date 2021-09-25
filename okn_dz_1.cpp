#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int x;
    cin >> x;

    if (x >= 100 && x < 1000)
        cout << "Трехзначное" << endl;
    else
        cout << "Не трехзначное" << endl;

    return 0;
}
