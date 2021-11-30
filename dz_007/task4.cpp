#include <iostream>
#include <string.h>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int buf_size = 256;

	char* str = new char[buf_size];
	char* ext = new char[15];

	cout << "Введите название файла: ";
	cin.getline(str, buf_size - 1);
	cout << "Введите новое расширение (с точкой, например, \".bak\"): ";
	cin.getline(ext, 15 - 1);
	
	int len = strlen(str);
	int ext_len = strlen(ext);
	int last_dot_index = -1;

	for (int i = 0; i < len; i++)
		if (str[i] == '.')
			last_dot_index = i;
	
	int start = last_dot_index != -1 ? last_dot_index : len;

	// ext_len + 1 для того чтобы записать ext и '\0'
	for (int i = 0; i < ext_len + 1; i++)
		str[start + i] = ext[i];

	cout << "Файл: " << str << endl;

	delete[] ext;
	delete[] str;
	return 0;
}