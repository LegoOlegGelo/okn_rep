#include <iostream>

using namespace std;

// 2^i = m, где i - шаг рекурсии, сначала = 1
int bin_to_dec(int bin, int m = 1)
{
    if (bin == 0)
        return 0;

    return bin_to_dec(bin / 10, m * 2) + bin % 10 * m;
}

int main()
{
    // x - псевдодвоичное число
    // допускаются только числа с 1 и 0
    int x = bin_to_dec(10110);
    cout << x << endl << endl;

    return 0;
}