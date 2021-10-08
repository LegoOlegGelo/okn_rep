#include <iostream>
#include <cmath>

using namespace std;

// через рекурсию
int fib1(int n)
{
    if (n <= 2)
        return 1;

    return fib1(n - 1) + fib1(n - 2);
}

// формула Бине (википедия)
int fib2(int n)
{
    float sqrt5 = sqrt(5);

    float x1 = pow((1 + sqrt5) / 2, n);
    float x2 = pow((1 - sqrt5) / 2, n);

    return round((x1 - x2) / sqrt5);
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите натуральное n = ";
    cin >> n;

    cout << "Алгоритм 1: " << fib1(n) << endl;
    cout << "Алгоритм 2: " << fib2(n) << endl;

    return 0;
} 