#include <iostream>

using namespace std;

void print_matrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << matrix[i][j] << " ";

		cout << endl;
	}
}

void random_matrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = 10 + rand() % 90;
}

int** create_matrix(int rows, int cols)
{
	if (rows * cols <= 0 || rows < 0)
		return nullptr;

	int** matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	return matrix;
}

void delete_matrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;
}

int main()
{
	srand(time(NULL));

	int A_rows =	  3, A_cols =	   5;
	int B_rows = A_cols, B_cols = A_rows;

	int** A = create_matrix(A_rows, A_cols);
	random_matrix(A, A_rows, A_cols);
	print_matrix(A, A_rows, A_cols);

	cout << endl;

	int** B = create_matrix(A_cols, A_rows);

	
	for (int i = 0; i < A_rows; i++)
		for (int j = 0; j < A_cols; j++)
			B[B_rows - 1 - j][B_cols - 1 - i] = A[i][j];


	print_matrix(B, B_rows, B_cols);

	// очищаем память
	delete_matrix(A, A_rows, A_cols);
	delete_matrix(B, B_rows, B_cols);
	return 0;
}