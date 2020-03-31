#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;


double* mergeSort(double*, int, int);
void enterArray(double*, int);
void randomArray(double*, int);
void displayArray(double*, int);
void contentsArray(double*, int);
void getFromArrayToFile(int size, double* source);
int unitCounter(double);
int zeroCounter(double);
double* changedArray(double*,int,int&);
bool isCorrect(double, int, int);



int main()
{
}
void enterArray(double* source, int size)
{
	cout << "enter array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << i + 1 << "]" << " ";
		cin >> source[i];
	}
}
void randomArray(double* source, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		source[i] = 1. / (rand() % 20 + 1);
	}
}
void displayArray(double* source, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << source[i] << " ";
	}
	cout << endl;
}
double* mergeSort(double* source, int left, int right)
{
	double* buffer = new double[right + 1];
	if (left == right)
	{
		buffer[left] = source[left];
		return buffer;
	}

	int middle = (left + right) / 2;

	double* leftBuff = mergeSort(source, left, middle);
	double* rightBuff = mergeSort(source, middle + 1, right);

	double* target = leftBuff == source ? buffer : source;

	int leftCur = left, rightCur = middle + 1;
	for (int i = left; i <= right; i++)
	{
		if (leftCur <= middle && rightCur <= right)
		{
			if (unitCounter(leftBuff[leftCur]) < unitCounter(rightBuff[rightCur]))
			{
				target[i] = leftBuff[leftCur];
				leftCur++;
			}
			else
			{
				target[i] = rightBuff[rightCur];
				rightCur++;
			}
		}
		else if (leftCur <= middle)
		{
			target[i] = leftBuff[leftCur];
			leftCur++;
		}
		else
		{
			target[i] = rightBuff[rightCur];
			rightCur++;
		}
	}

	return target;
}
void contentsArray(double* source, int size)
{
	const auto N = 40;
	char path[N] = R"(C:\Users\USER\Desktop\jojo2.txt)";
	ifstream fin(path);
	if (!fin.is_open())
	{
		throw std::invalid_argument("exeption");
		exit(1);
	}
	int i = 0, term;
	while (!fin.eof() && i < size)
	{
		fin >> source[i];
		i++;
	}

	fin.close();
}
void getFromArrayToFile(int size, double* source)
{
	const auto N = 40;
	char path[N] = R"(C:\Users\USER\Desktop\jojo2.txt)";
	ofstream sout(path);

	if (!sout.is_open())
	{
		throw std::invalid_argument("no way");
		exit(1);
	}
	system("cls");
	for (auto i = 0; i < size; i++)
	{
		sout.width(5);
		sout << source[i] << endl;
	}
	sout.close();
}
int unitCounter(double number)
{
	int counter = 0;
	int temp = number;
	while (temp)
	{
		if (temp % 2)
		{
			counter++;
		}
		temp /= 2;
	}
	return counter;
}
int zeroCounter(double number)
{
	int counter = 0;
	int temp = number;
	while (temp)
	{
		if (!(temp % 2))
		{
			counter++;
		}
		temp /= 2;
	}
	return counter;
}
bool isCorrect(double number, int a, int b)
{
	return a <= unitCounter(number) && b <= zeroCounter(number);
}
double* changedArray(double* source, int size,int& newsize)
{
	int a, b;
	cout << "enter number of zeros: ";
	cin >> b;
	cout << " and units: ";
	cin >> a;
	cout << endl;
	double* buffer = new double[100];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if(isCorrect(source[i],a,b))
		{
			buffer[j] = source[i];
			j++;
		}
	}
	newsize = j;
	double* changed = new double[j + 1];
	for (int i = 0; i < j+1; i++)
	{
		changed[i] = buffer[i];
	}
	delete[] buffer;
	return changed;
}