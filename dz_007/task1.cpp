#include <iostream>

using namespace std;

bool is_palindrom(const char* str)
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - 1 - i])
            return false;

    return true;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    char* str = new char[256];
    cin >> str;

    cout << (is_palindrom(str) ? "палиндром" : "НЕ палиндром") << endl;

    delete[] str;
    return 0;
}