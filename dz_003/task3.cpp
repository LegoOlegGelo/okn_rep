#include <iostream>

using namespace std;

void prime(int n)
{
    if (n <= 2) { cout << n; return; }

    int d = 2;

    while (d * d <= n)
    {
        if (n % d == 0)
        {
            cout << d << " * ";
            prime(n / d);
            return;
        }
        d++;
    }

    cout << n;
}

int main()
{
    // тестовые числа
    int ns[] = { 2 * 2 * 2 * 5 * 7,    36,     17,    1 };

    for (int i = 0; i < sizeof(ns)/sizeof(int); i++)
    {
        prime(ns[i]);
        cout << endl;
    }

    cout << endl;
    return 0;
}