#include <iostream>
#include <fstream>

using namespace std;

int sizeOfMatrix(char*);
int** createMatrix(int);
int** getMatrixFromFile(char*, int);
void display(int**, int);
int** newMatrix(int**, int);
void matrixToFile(int**, int, char*);
void Delete(int**, int);
void outMatrix(int**, int, ostream&);
int findMax(int**, int, int, int);

int main()
{
	char path[64] = "‪C:\\Users\\USER\\Desktop\\jojo2.txt";
	int size = sizeOfMatrix(path);
	int** matrix = getMatrixFromFile(path, size);
	matrixToFile(matrix, size, path);
	outMatrix(matrix, size, cout);
	Delete(matrix, size);
	return 0;
}
int sizeOfMatrix(char* path)
{
	int size = 0, temp = 0;

	ifstream in(path);

	if (!in.is_open())
	{
		throw std::invalid_argument("Error");
	}

	while (!in.eof())
	{
		in >> temp;
		size++;
	}

	in.close();

	return sqrt(size);
}
int** createMatrix(int size)
{
	int** matrix = new int* [size];

	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size];
	}

	return matrix;
}
int** getMatrixFromFile(char* path, int size)
{
	int** matrix = createMatrix(size);

	ifstream in(path);

	if (!in.is_open())
	{
		throw std::invalid_argument("Error");
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			in >> matrix[i][j];
		}
	}

	in.close();

	return matrix;
}
void outMatrix(int** matrix, int size, ostream& out)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			out << matrix[i][j] << " ";
		}
		out << endl;
	}
}
int** newMatrix(int** matrix, int size)
{
	int** newMatrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			newMatrix[i][j] = findMax(matrix, i, j, size);
		}
	}
	return newMatrix;
}
int findMax(int** matrix, int i, int j, int size)
{
	int max = matrix[i][j], jmax = j;

	for (int i1 = i; i1 >= 0; --i1)
	{
		for (int j1 = j; j1 >= 0 && j1 <= jmax; j1++)
		{
			if (max < matrix[i1][j1])
			{
				max = matrix[i1][j1];
			}
		}
		if (j > 0)
		{
			j--;
		}
		if (jmax < size)
		{
			jmax++;
		}
	}
	int jmin = j;
	for (int i1 = i; i1 <= size; i1++)
	{
		for (int j1 = j; j1 <= size && j1 >= jmin; j1++)
		{
			if (max < matrix[i1][j1])
			{
				max = matrix[i1][j1];
			}
		}
		if (j < size)
		{
			j++;
		}
		if (jmin < size)
		{
			jmin++;
		}
	}

	return max;
}
void matrixToFile(int** matrix, int size, char* path)
{
	ofstream out;
	out.open(path, ios_base::app);

	out << endl << "new matrix" << endl;
	outMatrix(matrix, size, out);
	out.close();
}
void Delete(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}
