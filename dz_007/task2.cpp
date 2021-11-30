#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char* str = new char[256];
	cin >> str;

	char* temp = new char[256];
	strcpy_s(temp, 256, str);

	int sum = 0;

	char* context;
	while (char* part = strtok_s(temp, "+", &context))
	{
		sum += atoi(part);
		temp = nullptr;
	}

	cout << sum << endl;

	delete[] str;
	return 0;
}