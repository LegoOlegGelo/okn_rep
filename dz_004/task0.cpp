#include <iostream>

using namespace std;

// недорешенная задача на паре
// решение для общего случая
// в том числе и для (N = 10, parts = 2), (N = 12, parts = 3)
// также работает для N не кратных parts, например, (N = 10, parts = 3)

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int N, parts; // N - кол-во элементов, parts - на сколько частей делить массив
    cin >> N >> parts;
    int cip = N / parts; // кол-во элементов в одном подмассиве

    // объявление, заполнение и вывод первоначального массива
    int* A = new int[N];

    for (int i = 0; i < N; i++)
        A[i] = -10 + rand() % 21;

    for (int i = 0; i < N; i++)
    {
        cout << A[i] << ' ';
        if ((i + 1) % cip == 0 && i + 1 < N) cout << " | ";
    }
    cout << endl;

    // алгоритм перемещения элементов
    for (int i = 0; i < parts; i++)
    {
        for (int j = 0; j < cip / 2; j++)
        {
            int c = A[i * cip + j];
            A[i * cip + j] = A[i * cip + cip - 1 - j];
            A[i * cip + cip - 1 - j] = c;
        }
    }

    // вывод результатов
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << ' ';
        if ((i + 1) % cip == 0 && i + 1 < N) cout << " | ";
    }

    cout << endl << endl;
    delete[] A;
    return 0;
}

/* 

примеры:

1) N = 36, parts = 6
-10 8 9 -10 4 -6  | -3 -10 0 1 7 9  | -8 8 -6 1 2 -7  | 5 -1 -1 7 -6 8  | -2 6 -9 0 3 -6  | 1 1 10 -3 1 3 
-6 4 -10 9 8 -10  | 9 7 1 0 -10 -3  | -7 2 1 -6 8 -8  | 8 -6 7 -1 -1 5  | -6 3 0 -9 6 -2  | 3 1 -3 10 1 1 

2) N = 12, parts = 3
-6 9 -10 5  | -9 10 2 7  | 0 7 2 -3 
5 -10 9 -6  | 7 2 10 -9  | -3 2 7 0 

3) N = 10, parts = 3
4 -7 9  | 3 -7 2  | -9 -9 6  | -5 
9 -7 4  | 2 -7 3  | 6 -9 -9  | -5 

*/