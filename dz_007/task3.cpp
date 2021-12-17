#include <iostream>
#include <string.h>

using namespace std;

int BUF_SIZE = 256;

void print_name(const char* str)
{
	char* s_copy = new char[BUF_SIZE];
	strcpy_s(s_copy, BUF_SIZE - 1, str);

	char* lastname = new char[BUF_SIZE];

	char* context;
	for (int i = 0; i < 3; i++)
	{
		char* part = strtok_s(s_copy, " ", &context);

		if (i == 0) lastname = part;
		else cout << part[0] << ". ";

		s_copy = nullptr;
	}
	cout << lastname << endl;

	delete[] s_copy;
	delete[] lastname;
}

int main()
{
	char* str = new char[BUF_SIZE];
	cin.getline(str, BUF_SIZE - 1);

	print_name(str);
	
	delete[] str;
	return 0;
}