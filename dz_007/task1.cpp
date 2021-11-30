#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    char* str = new char[256];

    cin >> str;

    int len = strlen(str);

    bool is_p = true;

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            is_p = false;
    }

    cout << (is_p ? "палиндром" : "НЕ палиндром") << endl;

    delete[] str;
    return 0;
}