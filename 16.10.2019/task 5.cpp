#include <iostream>

using namespace std;

int enterNumber();
int chekingNumber(int, int, int);
int digitToRemove();
int numberOfDigits(int);
void menu();
void menuText();
void testing();
void workOfTesting(int, int, int, int, int);
void workWithConsole();
void dysplayResult(int);
int main()
{
	menu();

	return 0;
}
int digitToRemove()
{
	int r;

	while (true)
	{
		cout << "enter digit to remove:" << endl;
		cin >> r;

		if (r >= 0 && r <= 9)
		{
			break;
		}
		cout << "not a digit!!" << endl;
		system("pause");
	}

	return r;
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
	int number = enterNumber();
	int r = digitToRemove();
	int i = numberOfDigits(number);

	chekingNumber(number, r, i);
}
void dysplayResult(int changedNumber)
{
	cout << "changed number is: " << changedNumber << endl;
}
int enterNumber()
{
	int number;

	cout << "enter number for cheking:" << endl;
	cin >> number;
	number = abs(number);

	return number;
}
int numberOfDigits(int number)
{
	int i = 0;
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return i;
}
int chekingNumber(int number, int r, int i)
{
	int changedNumber = 0;

	for (int a = 0; i > 0; i--)
	{
		a = number / (int)pow(10, i - 1);
		number = number % (int)pow(10, i - 1);

		if (a == r)
		{
			continue;

		}
		else
		{
			changedNumber = 10 * (changedNumber + a);
		}
		

	}
	changedNumber = changedNumber / 10;
	return changedNumber;

}
void testing()
{
	int testNumber = 1;

	workOfTesting(testNumber++, 2333, 4, 3, 2);
	workOfTesting(testNumber++, 54545, 5, 4, 555);
	workOfTesting(testNumber++, 47, 2, 4, 7);
	workOfTesting(testNumber++, 0, 1, 8,0);
	workOfTesting(testNumber++, 111111, 6, 8, 111111);
}
void workOfTesting(int testCaseNumber, int number, int i, int r, int changedNumber)
{
	int act = chekingNumber(number, r, i);
	if (act == changedNumber)
	{
		cout << "Case #" << testCaseNumber << " well changed /)" << endl;
	}
	else
	{
		cout << "Case #" << testCaseNumber << " bad changed. /(" << endl;

	}
}
