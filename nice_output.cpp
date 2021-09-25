#include <iostream>
#include <vector>
#include <string>

using namespace std;

void nice_cout_num(int* num, int wid_coef, char symbol, int rand);

int main()
{
    int a = 1234567890;

    nice_cout_num(&a, 2, '*', 0);
    cout << endl << endl << endl << endl;

    nice_cout_num(&a, 2, '+', 0);
    cout << endl << endl << endl << endl;



    nice_cout_num(&a, 2, '+', 1);
    cout << endl << endl << endl << endl;


    cout << endl << endl << endl << endl;
    return 0;
}

void nice_cout_num(int* num, int wid_coef, char symbol, int rand)
{
    string symbols = "1!:@2#3'$%^4&5*(6.?\"|)7-+8/=,9;0";
    int symbols_len = 33;
    int symbol_c = 0;

    int digits[10][5][3] = 
    {
        {
            { 1, 1, 1 },
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 1, 1, 1 }
        },
        {
            { 0, 0, 1 },
            { 0, 1, 1 },
            { 1, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 }
        },
        {
            { 1, 1, 1 },
            { 0, 0, 1 },
            { 1, 1, 1 },
            { 1, 0, 0 },
            { 1, 1, 1 }
        },
        {
            { 1, 1, 1 },
            { 0, 0, 1 },
            { 1, 1, 1 },
            { 0, 0, 1 },
            { 1, 1, 1 }
        },
        {
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 1, 1, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 }
        },
        {
            { 1, 1, 1 },
            { 1, 0, 0 },
            { 1, 1, 1 },
            { 0, 0, 1 },
            { 1, 1, 1 }
        },
        {
            { 1, 1, 1 },
            { 1, 0, 0 },
            { 1, 1, 1 },
            { 1, 0, 1 },
            { 1, 1, 1 }
        },
        { 
            { 1, 1, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 }
        },
        {
            { 1, 1, 1 },
            { 1, 0, 1 },
            { 1, 1, 1 },
            { 1, 0, 1 },
            { 1, 1, 1 }
        },
        {
            { 1, 1, 1 },
            { 1, 0, 1 },
            { 1, 1, 1 },
            { 0, 0, 1 },
            { 1, 1, 1 }
        }
        
    };

    int num_copy = *num;
    vector<int> num_digits;

    while (num_copy > 0)
    {
        num_digits.push_back(num_copy % 10);
        num_copy /= 10;
    }

    for (int i = 0; i < 5 * wid_coef; i++)
    {
        for (int d = num_digits.size() - 1; d >= 0; d--)
        {
            for (int j = 0; j < 3 * wid_coef; j++)
            {
                if (rand) cout << (digits[num_digits[d]][i / wid_coef][j / wid_coef] ? symbols[symbol_c % symbols_len] : ' ') << " ";
                else cout << (digits[num_digits[d]][i / wid_coef][j / wid_coef] ? symbol : ' ') << " ";
                symbol_c++;
            }
            cout << "   ";
        }
        cout << endl;
    }
}