
#include <iostream>
#include <ctime>

using namespace std;

void bubleSort(int*, int);
void swap(int&, int&);
void randomArray(int*, int, int);
void displayArray(int*, int);
int* allocateMemory(int);
void deleteMemory(int*);
bool areEqual(int*, int, int*, int);
bool isDataValid(int*, int);
void menu();
void menuText();
void testing();
void workWithConsole();
void testCase(int* expected, int n, int* actual, int m);

int main()
{
	menu();

	return 0;

}

bool isDataValid(int* array, int n)
{
	if (array == nullptr)
	{
		return false;
	}

	if (n <= 0)
	{
		return false;
	}

	return true;
}

bool areEqual(int* lhs, int n, int* rhs, int m)
{
	if (!isDataValid(lhs, n) || !isDataValid(rhs, m))
	{
		cout << " Invalid data!!!" << endl;
		return false;
	}

	if (n != m)
	{
		return false;
	}

	for (int* p = lhs, *q = rhs; p < lhs + n; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}

	return true;
}

void deleteMemory(int* sourceArray)
{
	delete[]sourceArray;
}

int* allocateMemory(int n)
{
	if (n <= 0)
	{
		cout << " N <= 0. Error!!!" << endl;
		return nullptr;
	}

	int* a = new int[n];

	return  a;
}

void displayArray(int* array, int n)
{
	if (!isDataValid(array, n))
	{
		cout << " Invalid data!!!" << endl;
	}

	for (int* p = array; p < array + n; p++)
	{
		cout << *p << " ";
	}

	cout << endl;

}

void randomArray(int* array, int n, int max)
{
	if (!isDataValid(array, n))
	{
		cout << " Invalid data!!!" << endl;
	}

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % max -max/2;
	}
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void bubleSort(int* sourceArray, int n)
{
	if (!isDataValid(sourceArray, n))
	{
		cout << " Invalid data!!!" << endl;
	}

	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;
		for (int j = n - 1; j > i; j--)
		{
			if (sourceArray[j] < sourceArray[j - 1])
			{
				swap(sourceArray[j], sourceArray[j - 1]);
				isSorted = false;
			}
		}
		i++;
	}
}
void menu()
{
	while (true)
	{
		char operation;
		menuText();
		cin >> operation;
		switch (operation)
		{
		case 'c':
			workWithConsole();
			break;
		case 't':
			testing();
			break;
		case 'r':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}
		system("pause");
		system("cls");

	}
}
void menuText()
{
	cout << "press 'c' to work with console" << endl;
	cout << "press 't' to start tests" << endl;
	cout << "press 'r' to exit" << endl;
}
void workWithConsole()
{
	int n;
	cout << "enter the number of members of array:" << endl;
	cin >> n;
	int max = pow(n, 5);

	int* array = allocateMemory(n);

	randomArray(array, n, max);

	cout << "unchanged array:" << endl;
	displayArray(array, n);

	bubleSort(array, n);
	cout << "changed array:" << endl;

	displayArray(array, n);
	deleteMemory(array);

	


}
void testing()
{
	int testNumber = 1;

	int n = 5;

	int* expected = new int[n] { 1, 2, 3, 4, 5 };
	int* actual = new int[n] {5, 4, 3, 2, 1};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);

	n = 10;
	expected = new int[n] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	actual = new int[n] {5, 4, 3, 2, 1, 8, 7, 10, 6, 9};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);

	n = 10;
	expected = new int[n] { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	actual = new int[n] {3, 3, 1, 1, 2, 2, 5, 5, 4, 4};
	testCase(expected, n, actual, n);
	deleteMemory(expected);
	deleteMemory(actual);

}
void testCase(int* expected, int n, int* actual, int m)
{
	bubleSort(actual, m);

	if (areEqual(expected, n, actual, m))
	{
		cout << " :)" << endl;
	}
	else
	{
		cout << " :(" << endl;
	}


}