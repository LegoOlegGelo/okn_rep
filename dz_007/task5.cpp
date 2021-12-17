#include <iostream>
#include <string.h>
#include <Windows.h>

using namespace std;

int BUF_SIZE = 256;

int get_entries_count(char* str, char* pattern, bool all_entries = false)
{
	/*
	* all_entries = true
	* str = "aaa"; pattern = "aa"  =>  2 вхождения ([0] + [1], [1] + [2])
	* 
	* 
	* all_entries = false
	*    str =  "aaa"; pattern = "aa"  =>  1 вхождение ([0] + [1])
	* но str = "aaaa"; pattern = "aa"  =>  2 вхождения ([0] + [1], [2] + [3])
	*/

	int str_len = strlen(str);
	int pat_len = strlen(pattern);

	int entries_count = 0;


	for (int i = 0; i < str_len; i++)
		if (str[i] == pattern[0])
		{
			if (str_len - i < pat_len)
				break;

			bool is_pattern = true;
			int j_saved = 1;

			for (int j = 1; j < pat_len; j++)
				if (str[i + j] != pattern[j])
				{
					j_saved = j;
					is_pattern = false;
					break;
				}
			
			entries_count += is_pattern;

			if (!all_entries)
				i += j_saved;
		}
	
	return entries_count;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char* str = new char[BUF_SIZE];
	char* pattern = new char[BUF_SIZE];

	cout << "Строка: ";
	cin.getline(str, BUF_SIZE - 1);
	cout << "Искомый паттерн: ";
	cin.getline(pattern, BUF_SIZE - 1);

	cout << "Кол-во вхождений: " << get_entries_count(str, pattern) << endl;

	delete[] str;
	return 0;
}