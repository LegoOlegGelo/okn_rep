#include <iostream>
#include <time.h>

using namespace std;

int get_val()
{
    return rand() % 6 + 1;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    srand(time(NULL));

    cout << "Выпало: " << get_val() << " и " << get_val() << endl;    

    return 0;
} 