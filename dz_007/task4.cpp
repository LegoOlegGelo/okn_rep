#include <iostream>
#include <string.h>
#include <Windows.h>

using namespace std;

int BUF_SIZE = 256;

char* get_new_filename(char* str, char* ext)
{
	char* str_copy = new char[BUF_SIZE];
	strcpy_s(str_copy, BUF_SIZE - 1, str);

	int len = strlen(str_copy);
	int ext_len = strlen(ext);
	int last_dot_index = -1;

	for (int i = 0; i < len; i++)
		if (str_copy[i] == '.')
			last_dot_index = i;

	int start = last_dot_index != -1 ? last_dot_index : len;

	// ext_len + 1 для того чтобы записать ext и '\0'
	for (int i = 0; i < ext_len + 1; i++)
		str_copy[start + i] = ext[i];

	return str_copy;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char* str = new char[BUF_SIZE];
	char* ext = new char[15];

	cout << "Введите название файла: ";
	cin.getline(str, BUF_SIZE - 1);
	cout << "Введите новое расширение (с точкой, например, \".bak\"): ";
	cin.getline(ext, 15 - 1);

	char* answer = get_new_filename(str, ext);
	cout << "Файл: " << answer << endl;

	delete[] ext;
	delete[] str;
	delete[] answer;
	return 0;
}