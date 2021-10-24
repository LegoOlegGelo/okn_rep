#include <iostream>

using namespace std;

void print_array(int array[], const int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    
    cout << endl;
}

void arithm_prog(int* arr, const int size, int a, int d)
{
    for (int i = 0; i < 10; i++)
        *(arr++) = a + d * i;
}

void rnd_perm(int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        // случ int
        arr[i] = 1 + rand() % size;
        
        // если такой элемент уже был раньше,
        // уменьшаем i, чтобы перезаписался arr[i]
        for (int j = 0; j < i; j++)
            if (arr[j] == arr[i])
            {
                i--;
                break;
            }
    }
}

void rnd_arr(int* arr, const int size)
{
    for (int i = 0; i < size; i++)
        *(arr++) = 1000 + rand() % 2001;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    const int size = 10;
    int* arr = new int[size];



    // Задача 1 (арифм. прогр.)
    int a, d;
    cout << "1. Введите a1, d = ";
    cin >> a >> d;
    cout << "Арифметическая прогрессия: ";
    arithm_prog(arr, size, a, d);
    print_array(arr, size);



    // Задача 2 (случ. перестановка)
    cout << endl << "2. Случайная перестановка: ";
    rnd_perm(arr, size);
    print_array(arr, size);



    // Задача 3 (случ. числа от 1000 до 2000)
    rnd_arr(arr, size);
    cout << endl << "3. Случ. числа: ";
    print_array(arr, size);

    int even_count = 0;

    for (int i = 0; i < size; i++)
    {
        int ab = arr[i] % 100, b = arr[i] % 10;
        
        if (ab - b == 20)
            even_count++;
    }

    cout << "Кол-во чисел с предпоследней цифрой 2: ";
    cout << even_count;



    cout << endl << endl;
    return 0;
}