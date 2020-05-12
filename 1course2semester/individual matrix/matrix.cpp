#include <iostream>
#include <fstream>

using namespace std;

bool isOdd(int**, int, int);
void work(const char*, const char*, int, int);
int** transformToMatrix(int*, int, int);
int* createMatrix(int, int);
void initializeMatrix(int*, int, int);
void writeInBinFile(const char*, int, int, int);
void readFromBinary(const char*, int, int);
void showMatrix(int**, int, int);

int main()
{
	cout << "befor" << endl;
	writeInBinFile("source.bin", 5, 3, 3);
	readFromBinary("source.bin", 5, 3);
	work("source.bin", "oddMatrix.bin", 5, 3);
	cout << endl << "after in first file:" << endl;
	readFromBinary("source.bin", 5, 3);
	cout << endl << "after in second file:" << endl;
	readFromBinary("oddMatrix.bin", 5, 3);
	return 0;
}
bool isOdd(int* matrix, int n, int m)
{
	int sum = 0;
	for (int i = 1; i < n*m; i+=2)
	{
		if(matrix[i]>0)
		{
			sum += matrix[i];
		}
	}
	return !(sum % 2);
}
void work(const char* path1, const char* path2, int n, int m)
{
	fstream stream1(path1, ios::in | ios::out | ios::binary);
	ofstream stream2(path2, ios::binary);

	int* a = createMatrix(n, m);
	int* b = createMatrix(n, m);
	for(int i=0;i<n*m;i++)
	{
		b[i] = 1;
	}
	int sbuf = n * m * sizeof(int);
	
	while (stream1.read((char*)a, sbuf))
	{
		if (isOdd(a, n, m))
		{
			stream2.write((char*)a, sbuf);
			stream1.seekp(-sbuf, ios::cur);
			stream1.write((char*)b, sbuf);
			stream1.seekp(sbuf, ios::cur);
		}
	}
	delete[] a;
	stream1.close();
	stream2.close();
}
int** transformToMatrix(int* arr, int n, int m)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = arr[i * m + j];
		}
	}
	return matrix;
}
void showMatrix(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}

		cout << endl;
	}
}
int* createMatrix(int n, int m)
{
	int* matrix = new int[n * m];
	return matrix;
}
void initializeMatrix(int* matrix, int n, int m)
{
	for (int* p = matrix; p < matrix + m * n; p++)
	{
		*p = rand() % 20;
	}
}
void writeInBinFile(const char* path, int n, int m, int k)
{
	ofstream sout(path, ios::binary);
	if(!sout.is_open())
	{
		throw std::invalid_argument("wrong way~");
		
	}
	int* a = createMatrix(n, m);
	int sbuf = n * m * sizeof(int);
	for (int i = 1; i <= k; i++)
	{
		initializeMatrix(a, n, m);
		sout.write((char*)a, sbuf);
		cout << endl;
	}
	delete[] a;
	sout.close();
}
void readFromBinary(const char* path, int n, int m)
{
	ifstream sin(path, ios::binary);
	int* a = createMatrix(n, m);
	int sbuf = n * m * sizeof(int);
	while (sin.read((char*)a, sbuf))
	{
		int** matrix = transformToMatrix(a, n, m);
		showMatrix(matrix, n, m);
		cout << endl;
	}
	delete[] a;
	sin.close();
}