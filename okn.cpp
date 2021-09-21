#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int num;
    cin >> num;
    cout << endl << endl;

    if (num == 0)
    {
        cout << "ноль" << endl;
        return 0;
    }
    else if (num > 10000000 || num < -10000000)
    {
        num = 10000000;
        cout << "Ограничение! |x| <= 10 млн" << endl;
        return 0;   
    }

    if (num < 0)
    {
        cout << "минус ";
        num *= -1;
    }

    int edin = num                         % 1000; // единицы
    int tys = (num - edin)       / 1000    % 1000; // тысячи
    int mil = (num - edin - tys) / 1000000 % 1000; // миллионы


    // миллионы 0 - 10
    if (mil > 0)
    {
        switch (mil){
            case 1: cout << "один миллион "; break;
            case 2: cout << "два миллиона "; break;
            case 3: cout << "три миллиона "; break;
            case 4: cout << "четыре миллиона "; break;
            case 5: cout << "пять миллионов "; break;
            case 6: cout << "шесть миллионов "; break;
            case 7: cout << "семь миллионов "; break;
            case 8: cout << "восемь миллионов "; break;
            case 9: cout << "девять миллионов "; break;
            case 10: cout << "десять миллионов "; break;
        }
    }

    // тысячи 0 - 999
    if (tys > 0)
    {
        int e = tys                 % 10; // единицы тысяч 
        int d = (tys - e)     / 10  % 10; // десятки тысяч
        int s = (tys - e - d) / 100 % 10; // сотни тысяч
        
        // сотни тыс 100 - 900
        if (s > 0)
        {
            switch (s)
            {
                case 1: cout << "сто "; break;
                case 2: cout << "двести "; break;
                case 3: cout << "триста "; break;
                case 4: cout << "четыреста "; break;
                case 5: cout << "пятьсот "; break;
                case 6: cout << "шестьсот "; break;
                case 7: cout << "семьсот "; break;
                case 8: cout << "восемьсот "; break;
                case 9: cout << "девятьсот "; break;
            }
        }

        // десятки тыс 20 - 90
        if (d > 1)
        {
            switch (d){
                case 2: cout << "двадцать "; break;
                case 3: cout << "тридцать "; break;
                case 4: cout << "сорок "; break;
                case 5: cout << "пятьдесят "; break;
                case 6: cout << "шестьдесят "; break;
                case 7: cout << "семьдесят "; break;
                case 8: cout << "восемьдесят"; break;
                case 9: cout << "девяносто "; break;
            }
        }

        // 0 - 19 тыс
        int de = d > 1 ? e : (d*10 + e);
        switch (de){
            case 1: cout << "одна тысяча "; break;
            case 2: cout << "две тысячи "; break;
            case 3: cout << "три тысячи "; break;
            case 4: cout << "четыре тысячи "; break;
            case 5: cout << "пять тысяч "; break;
            case 6: cout << "шесть тысяч "; break;
            case 7: cout << "семь тысяч "; break;
            case 8: cout << "восемь тысяч "; break;
            case 9: cout << "девять тысяч "; break;
            case 10: cout << "десять тысяч "; break;
            case 11: cout << "одиннадцать тысяч "; break;
            case 12: cout << "двенадцать тысяч "; break;
            case 13: cout << "тринадцать тысяч "; break;
            case 14: cout << "четырнадцать тысяч "; break;
            case 15: cout << "пятнадцать тысяч "; break;
            case 16: cout << "шестнадцать тысяч "; break;
            case 17: cout << "семнадцать тысяч "; break;
            case 18: cout << "восемнадцать тысяч "; break;
            case 19: cout << "девятнадцать тысяч "; break;
            default: cout << "тысяч "; break;
        }
    }


    // единицы 0 - 999
    if (edin > 0)
    {
        int e = edin                 % 10; // единицы 
        int d = (edin - e)     / 10  % 10; // десятки
        int s = (edin - e - d) / 100 % 10; // сотни
        
        // сотни 100 - 900
        if (s > 0)
        {
            switch (s)
            {
                case 1: cout << "сто "; break;
                case 2: cout << "двести "; break;
                case 3: cout << "триста "; break;
                case 4: cout << "четыреста "; break;
                case 5: cout << "пятьсот "; break;
                case 6: cout << "шестьсот "; break;
                case 7: cout << "семьсот "; break;
                case 8: cout << "восемьсот "; break;
                case 9: cout << "девятьсот "; break;
            }
        }

        // десятки 20 - 90
        if (d > 1)
        {
            switch (d){
                case 2: cout << "двадцать "; break;
                case 3: cout << "тридцать "; break;
                case 4: cout << "сорок "; break;
                case 5: cout << "пятьдесят "; break;
                case 6: cout << "шестьедяст "; break;
                case 7: cout << "семьдесят "; break;
                case 8: cout << "восемьдесят"; break;
                case 9: cout << "девяносто "; break;
            }
        }

        // 0 - 19
        int de = d > 1 ? e : (d*10 + e);
        switch (de){
            case 1: cout << "один"; break;
            case 2: cout << "два"; break;
            case 3: cout << "три"; break;
            case 4: cout << "четыре"; break;
            case 5: cout << "пять"; break;
            case 6: cout << "шесть"; break;
            case 7: cout << "семь"; break;
            case 8: cout << "восемь"; break;
            case 9: cout << "девять"; break;
            case 10: cout << "десять"; break;
            case 11: cout << "одиннадцать"; break;
            case 12: cout << "двенадцать"; break;
            case 13: cout << "тринадцать"; break;
            case 14: cout << "четырнадцать"; break;
            case 15: cout << "пятнадцать"; break;
            case 16: cout << "шестнадцать"; break;
            case 17: cout << "семнадцать"; break;
            case 18: cout << "восемнадцать"; break;
            case 19: cout << "девятнадцать"; break;
        }
    }


    cout << endl << endl;
    return 0;
}