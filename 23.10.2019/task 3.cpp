#include <iostream>

using namespace std;

void menu();
void menuText();
void testing();
int long enterNumber();
int digitToCount();
short logic(int long, int);
void dysplayResult(short);
void workWithConsole();
void howManyDigits(int, int long, int, short);
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
int long enterNumber()
{
	int long number;

	cout << "enter number for cheking:" << endl;
	cin >> number;
	number = abs(number);

	return number;

}
int digitToCount()
{
	int digit;

	cout << "enter digit to find and found quantity:" << endl;
	cin >> digit;

	digit = abs(digit);

	return digit;

}
short logic(int long number, int digit)
{
	int sumForDigitQuantity = 0;

	while (number % 16 != 0)
	{
		if (number % 16 == digit)
		{
			sumForDigitQuantity++;

			number = number - number % 16;
		}
		else
		{
			number = number - number % 16;

			continue;
		}
	}
	if (number % 16 == 0)
		if (number / 16 == digit || number % 16 == digit)
		{
			sumForDigitQuantity++;

		}

		return sumForDigitQuantity;

}
void dysplayResult(short sumForDigitQuantity)
{
	cout << "the quantity of unities is: " << sumForDigitQuantity << endl;
}
void workWithConsole()
{
	int long number = enterNumber();

	int digit = digitToCount();

	short sumForDigitQuantity = logic(number, digit);

	dysplayResult(sumForDigitQuantity);
}
void testing()
{
	int testNumber = 1;

	howManyDigits(testNumber++, 16, 1, 1);
	howManyDigits(testNumber++, 88, 5, 1);
	howManyDigits(testNumber++, 4999, 3, 1);
	howManyDigits(testNumber++, 7878787, 8, 3);
	howManyDigits(testNumber++, 67, 3, 1);
}
void howManyDigits(int testCaseNumber, int long number, int digit, short sumForDigitQuantity)
{
	short act = logic(number, digit);

	if (act == sumForDigitQuantity)
	{
		cout << "Case #" << testCaseNumber << " is right. /)" << endl;

	}
	else
	{
		cout << "Case #" << testCaseNumber << " is not right. /)" << endl;
	}

}