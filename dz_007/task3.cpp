#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int buf_size = 256;

	char* str = new char[buf_size];
	cin.getline(str, buf_size - 1);

	char* s_copy = new char[buf_size];
	strcpy_s(s_copy, buf_size - 1, str);

	char* lastname = new char[buf_size];

	char* context;
	for (int i = 0; i < 3; i++)
	{
		char* part = strtok_s(s_copy, " ", &context);

		if (i == 0) lastname = part;
		else cout << part[0] << ". ";

		s_copy = nullptr;
	}
	cout << lastname << endl;

	delete[] str;
	delete[] s_copy;
	delete[] lastname;
	return 0;
}