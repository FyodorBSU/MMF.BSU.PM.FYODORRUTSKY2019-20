#include <iostream>

using namespace std;

void menu();
void menuText();
void testing();
int enterNumber();
short logic(int);
void dysplayResult(short);
void workWithConsole();
void howManyZeroes(int, int, short);
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
int enterNumber()
{
	int number;

	cout << "enter number for cheking:" << endl;
	cin >> number;
	number = abs(number);

	return number;

}
short logic(int number)
{
	short  sumForZero = 0;

	while(number > 0)
	{
		
		if (number % 2 == 0)
		{

			sumForZero++;
			number = number / 2;
		}
		else
		{
			number = number / 2;
			continue;

		}
	}

	

	return sumForZero;
}
void dysplayResult(short sumForZero)
{
	cout << "the quantity of unities is: " << sumForZero << endl;
}
void workWithConsole()
{
	int number = enterNumber();

	int long long sumForZero = logic(number);

	dysplayResult(sumForZero);
}
void testing()
{
	int testNumber = 1;

	howManyZeroes(testNumber++, 19, 2);
	howManyZeroes(testNumber++, 1, 0);
	howManyZeroes(testNumber++, 0, 1);
	howManyZeroes(testNumber++, 122, 2);
	howManyZeroes(testNumber++, 99, 3);
}
void howManyZeroes(int testCaseNumber, int number, short sumForZero)
{
	short act = logic(number);

	if (act == sumForZero)
	{
		cout << "Case #" << testCaseNumber << " is right. /)" << endl;

	}
	else
	{
		cout << "Case #" << testCaseNumber << " is not right. /)" << endl;
	}

}