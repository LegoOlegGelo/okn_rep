#include <iostream>
#include <string.h>

using namespace std;

int get_sum(const char* str)
{
	char* temp = new char[256];
	strcpy_s(temp, 256, str);

	int sum = 0;

	char* context;
	while (char* part = strtok_s(temp, "+", &context))
	{
		sum += atoi(part);
		temp = nullptr;
	}

	delete[] temp;
	return sum;
}

int main()
{
	char* str = new char[256];
	cin >> str;

	cout << get_sum(str) << endl;

	delete[] str;
	return 0;
}