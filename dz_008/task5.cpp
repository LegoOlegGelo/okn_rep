#include <iostream>
#include "matrix_funcs.h"

using namespace std;

void find_min(int* array, int len, int& c)
{
	c = 0;

	for (int i = 0; i < len; i++)
		if (array[i] < array[c])
			c = i;
}

void find_max(int* array, int len, int& c)
{
	c = 0;

	for (int i = 0; i < len; i++)
		if (array[i] > array[c])
			c = i;
}

int main()
{
	srand(time(NULL));

	int A_rows = 5, A_cols = 3;

	int** A = create_matrix(A_rows, A_cols);
	random_matrix(A, A_rows, A_cols);
	print_matrix(A, A_rows, A_cols);
	cout << endl;

	// идем с конца, чтобы взять максимальные элементы из первоначальных строк
	int max_c;
	find_max(A[A_rows - 1 - 1], A_cols, max_c);

	for (int i = A_rows - 1; i > 0; i--)
	{
		// ищем наименьший
		int min_c;
		find_min(A[i], A_cols, min_c);

		// меняем
		A[i][min_c] = A[i - 1][max_c];

		// ищем наибольший
		find_max(A[i], A_cols, max_c);
	}

	print_matrix(A, A_rows, A_cols);

	// очищаем память
	delete_matrix(A, A_rows, A_cols);
	return 0;
}