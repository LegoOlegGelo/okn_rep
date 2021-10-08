#include <iostream>

using namespace std;

int get_val()
{
    return rand() % 6 + 1;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "Выпало: " << get_val() << " и " << get_val() << endl;    

    return 0;
} 