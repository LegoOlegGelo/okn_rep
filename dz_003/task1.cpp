#include <iostream>

using namespace std;

void printDigits(int x)
{
    if (x < 10) { cout << x; return; }

    printDigits(x / 10);
    cout << "  " << x % 10;
}

int main()
{
    printDigits(1234);
    cout << endl << endl;

    return 0;
}