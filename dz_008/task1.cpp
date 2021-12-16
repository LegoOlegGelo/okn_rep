#include <iostream>
#include "matrix_funcs.h"

using namespace std;

void search_min(int** matrix, int rows, int cols, int& r, int& c)
{
	r = 0; c = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matrix[i][j] < matrix[r][c])
			{
				r = i; c = j;
			}
}

int main()
{
	srand(time(NULL));

	// создаем матрицу, заполняем рандомными элементами и печатаем
	int rows = 4, cols = 5;
	int** base_matrix = create_matrix(rows, cols);
	random_matrix(base_matrix, rows, cols);
	print_matrix(base_matrix, rows, cols);

	// ищем минимальный элемент
	int r, c;
	search_min(base_matrix, rows, cols, r, c);

	// создаем матрицу размером меньше
	int new_rows = rows - 1, new_cols = cols - 1;
	int** matrix = create_matrix(rows, cols);

	// создаем новую матрицу и печатаем ее
	for (int i = 0; i < new_rows; i++)
	{
		int adden = 0;
		for (int j = 0; j < new_cols; j++)
		{
			if (j == c) adden = 1;

			matrix[i][j] = base_matrix[i + (i >= r)][j + (j >= c)];
		}
	}

	cout << endl << "min (row, col) = (" << r << ", " << c << ")" << endl << endl;
	print_matrix(matrix, new_rows, new_cols);

	// очищаем память
	delete_matrix(base_matrix, rows, cols);
	delete_matrix(matrix, rows, cols);
	return 0;
}