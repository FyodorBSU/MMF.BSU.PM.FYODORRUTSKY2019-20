#include <iostream>

using namespace std;

int enterNumber();
void displayResult(int, int);
int chekingNumber(int, int);
int chekingNumbersOfDigits(int);
void menu();
void menuText();
void testing();
void workWithConsole();
void polindromeTesting(int, int, int, bool);




int main()
{
	menu();

	return 0;
}
int enterNumber()
{
	int number;

	cout << "enter number for cheking:" << endl;
	cin >> number;
	number = abs(number);

	return number;
}
int chekingNumbersOfDigits(int number)
{
	int i = 0;
	while (number != 0)
	{
		number = number / 10;
		i++;

	}
	return i;
}
int chekingNumber(int number, int i)
{
	int  clone = number, reverse = 0, c = 1;

	for (number; i >= c; c++)
	{
		reverse = reverse * 10 + clone % 10;
		clone = clone / 10;

	}
	return reverse;
}

void displayResult(int reverse, int number)
{
	if (reverse == number)
	{
		cout << "this number is polindrome!!" << endl;
	}
	else
	{
		cout << "this number is not polindrome!!" << endl;
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
		case 'e':
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
	cout << "press 't' to start testing" << endl;
	cout << "press 'e' to leave programe" << endl;
}
void workWithConsole()
{
	int number = enterNumber();

	int i = chekingNumbersOfDigits(number);

	int reverse = chekingNumber(number, i);

	displayResult(number, reverse);
}

void testing()
{

	int testNumber = 1;

	polindromeTesting(testNumber++, 123321,6,1 );
	polindromeTesting(testNumber++, 12345, 5, 0 );
	polindromeTesting(testNumber++, 1222442, 7, 0 );
	polindromeTesting(testNumber++, 22222, 5, 1);
	polindromeTesting(testNumber++, 0, 1, 1);


}
void polindromeTesting(int testCaseNumber , int number, int i,  bool t)
{
	bool act = chekingNumber(number, i);

	if (act==t)
	{
		cout << "Case #" << testCaseNumber << " is correct. \)" << endl;
	}
	else
	{
		cout << "Case #" << testCaseNumber << " IS NOT CORRECT. \(" << endl;

	}
}
