#include<iostream>

using namespace std;

void menu();
void menuText();
void testing();
void workWithConsole();
void initArray(int array[], int n);
void changeOfArray(int array[], int n);
void workOfTesting(int, int, int, int, int, int, int, int, int, int, int);

int main()
{

	menu();

	return 0;
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
void initArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << (i + 1) << "]";
		cin >> array[i];
	}
}
void workWithConsole()
{
	int const n = 10;
	int array[n] = { 0 };

	initArray(array, n);
	changeOfArray(array, n);

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}

}
void testing()
{
	int testCaseNumber = 1;
	workOfTesting(testCaseNumber++, 2, 5, 7, 8, 9, 9, 8, 7, 5, 2);
	workOfTesting(testCaseNumber++, 3, 3, 6, 9, 2, 2, 9, 6, 3, 3);
	workOfTesting(testCaseNumber++, 5, 8, 10, 55, 43, 43, 55, 10, 8, 5);
	workOfTesting(testCaseNumber++, 2, 66, 77, 88, 99, 99, 88, 77, 66, 2);
	workOfTesting(testCaseNumber++,  1, 2, 3, 4, 5, 5, 4, 3, 2, 1);
}
void changeOfArray(int array[], int n)
{
	int t;
	int j = n - 1;

	for (int i = 0; i < j; i++, j--)
	{
		t = array[i];
		array[i] = array[j];
		array[j] = t;

	}


}
void workOfTesting(int testCaseNumber, int arr11, int arr12, int arr13, int arr14, int arr15, int arr21, int arr22, int arr23, int arr24, int arr25)
{
	int const k = 5;
	int firstArray[k] = { 0 };
	int secondArray[k] = { 0 };
	firstArray[0] = arr11;
	firstArray[1] = arr12;
	firstArray[2] = arr13;
	firstArray[3] = arr14;
	firstArray[4] = arr15;
	secondArray[0] = arr21;
	secondArray[1] = arr22;
	secondArray[2] = arr23;
	secondArray[3] = arr24;
	secondArray[4] = arr25;

	changeOfArray(firstArray, k);

	bool t = true;
	for (int i = 0; i < k; i++)
	{
		if (firstArray[i] == secondArray[i])
		{
			t = true;
			continue;
		}
		else
		{
			t = false;
			break;
		}
	}

	if (t)
		cout << "test #" << testCaseNumber << "is correct!!" << endl;
	else
		cout << "test #" << testCaseNumber << "is not correct!!" << endl;


}
