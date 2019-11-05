#include<iostream>

using namespace std;

void menu();
void menuText();
void testing();
void workWithConsole();
void initArray(int array[], int n);
void changeOfArray(int primeArray[], int array[], int n);
void workOfTesting(int testCaseNumber, int arr11, int arr12, int arr13, int arr14, int arr15, int primeArr1, int primeArr2, int primeArr3, int primeArr4, int primeArr5);

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
	int primeArray[n] = { 0 };

	initArray(array, n);
	changeOfArray(array, primeArray, n);

	for (int i = 0; i < n; i++)
	{
		if (primeArray[i] == 0)
		{
			continue;
		}
		else
		{
			cout << primeArray[i] << " ";
		}
	}

}
void testing()
{
	int testCaseNumber = 1;
	workOfTesting(testCaseNumber++, 1, 3, 5, 7, 9, 0, 3, 5, 7, 2);
	workOfTesting(testCaseNumber++, 13, 17, 22, 44, 19, 13, 17, 0, 0, 17);
	workOfTesting(testCaseNumber++, 5, 8, 10, 55, 43, 5, 0, 0, 0, 43);
	workOfTesting(testCaseNumber++, 2, 66, 77, 88, 99, 2, 0, 0, 0, 0);
	workOfTesting(testCaseNumber++, 1, 2, 3, 4, 5, 0, 2, 3, 0, 5);
}
void changeOfArray(int array[], int primeArray[], int n)
{
	int j = 0;
	for (; j < n; j++)
		for (int i = 2; i <= sqrt(array[j]); i++)
		{
			if (array[j] % i == 0)
			{
				primeArray[j] = 0;
				break;

			}
			else
			{
				primeArray[j] = array[j];

			}
		}

}

void workOfTesting(int testCaseNumber, int arr11, int arr12, int arr13, int arr14, int arr15, int primeArr1, int primeArr2, int primeArr3, int primeArr4, int primeArr5)
{
	int const k = 5;
	int firstArray[k] = { 0 };
	int primeArray[k] = { 0 };
	firstArray[0] = arr11;
	firstArray[1] = arr12;
	firstArray[2] = arr13;
	firstArray[3] = arr14;
	firstArray[4] = arr15;

	changeOfArray(firstArray, primeArray, k);
	if (primeArray[0] == primeArr1 && primeArray[1] == primeArr2 && primeArray[2] == primeArr3 && primeArray[3] == primeArr4 && primeArray[4] == primeArr5)
		cout << " test # " << testCaseNumber << " is correct." << endl;
	else
		cout << " test # " << testCaseNumber << " is not correct." << endl;
}


