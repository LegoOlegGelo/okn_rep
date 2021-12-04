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

	int A_rows = 3,		 A_cols = 4; // A size
	int B_rows = A_cols, B_cols = 2; // B size

	int** A = create_matrix(A_rows, A_cols);
	random_matrix(A, A_rows, A_cols);
	print_matrix(A, A_rows, A_cols);

	cout << endl;

	int** B = create_matrix(B_rows, B_cols);
	random_matrix(B, B_rows, B_cols);
	print_matrix(B, B_rows, B_cols);

	
	int C_rows = A_rows, C_cols = B_cols;
	int** C = create_matrix(C_rows, C_cols);

	for (int i = 0; i < C_rows; i++)
		for (int j = 0; j < C_cols; j++)
		{
			int s = 0;

			for (int t = 0; t < A_cols; t++)
				s += A[i][t] * B[t][j];

			C[i][j] = s;
		}

	cout << endl;
	print_matrix(C, C_rows, C_cols);


	// очищаем память
	delete_matrix(A, A_rows, A_cols);
	delete_matrix(B, B_rows, B_cols);
	return 0;
}