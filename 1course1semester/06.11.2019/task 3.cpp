#include<iostream>

using namespace std;

void menu();
void menuText();
void testing();
void workWithConsole();
int* localeMemory(int size);
void initArray(int* array, int);
int changeOfArray(int* array, int, int);
int enterMinimalDigit();
void displayResult(int, int);
void workOfTesting(int testCaseNumber, int arr11, int arr12, int arr13, int arr14, int arr15, int min, int lowerNumbers);

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
int* localeMemory(int size)
{
	if (size < 0)
	{
		cout << "impossible!!!" << endl;
		return nullptr;
	}
	return new int(size);
}
void menuText()
{
	cout << "press 'c' to work with console" << endl;
	cout << "press 't' to start tests" << endl;
	cout << "press 'r' to exit" << endl;
}
void initArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << (i + 1) << "]";
		cin >> array[i];
	}
}
int enterMinimalDigit()
{
	int min;
	cout << "enter digit to compare:" << endl;
	cin >> min;

	return min;

}
void workWithConsole()
{
	int size;

	cout << "enter array's size:" << endl;
	cin >> size;

	int* array = localeMemory(size);

	initArray(array, size);
	int min = enterMinimalDigit();
	int lowerNumbers = changeOfArray(array, min, size);


	displayResult(lowerNumbers, min);



}
void testing()
{
	int testCaseNumber = 1;
	workOfTesting(testCaseNumber++, 1, 3, 5, 7, 9, 7, 3);
	workOfTesting(testCaseNumber++, 13, 17, 22, 44, 19, 36, 4);
	workOfTesting(testCaseNumber++, 5, 8, 10, 55, 43, 41, 3);
	workOfTesting(testCaseNumber++, 2, 66, 77, 88, 99, 90, 4);
	workOfTesting(testCaseNumber++, 1, 2, 3, 4, 5, 6, 5);
}
int changeOfArray(int array[], int min, int n)
{
	int lowerNumbers = 0;

	for (int i = 0; i < n; i++)
	{
		if (array[i] < min)
		{
			lowerNumbers++;
		}
		else
			continue;

	}

	return lowerNumbers;
}
void displayResult(int lowerNumbers, int min)
{
	cout << "There are " << lowerNumbers << " less digits, than " << min << endl;
}

void workOfTesting(int testCaseNumber, int arr11, int arr12, int arr13, int arr14, int arr15, int min, int lowerNumbers)
{
	int const k = 5;
	int firstArray[k] = { 0 };
	firstArray[0] = arr11;
	firstArray[1] = arr12;
	firstArray[2] = arr13;
	firstArray[3] = arr14;
	firstArray[4] = arr15;
	int actual = changeOfArray(firstArray, min, k);
	if (actual == lowerNumbers)
		cout << "test # " << testCaseNumber << " is correct." << endl;
	else
		cout << "test # " << testCaseNumber << " is not correct." << endl;
}
