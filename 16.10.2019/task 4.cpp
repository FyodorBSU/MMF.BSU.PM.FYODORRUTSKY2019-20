#include <iostream>

using namespace std;

int enterNumber();
int chekingNumber(int, int, int, int);
int digitToRemove();
int digitToSet();
int numberOfDigits(int);
void menu();
void menuText();
void testing();
void workOfTesting(int, int, int, int, int, int);
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
int digitToSet()
{
	int k;
	while (true)
	{
		cout << "enter digit to set:" << endl;
		cin >> k;

		if (k >= 0 && k <= 9)
		{
			break;
		}
		cout << "not a digit!!" << endl;
		system("pause");
	}

	return k;
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
int chekingNumber(int number, int k, int r, int i)
{
	int changedNumber = 0;

	for (int a = 0; i > 0; i--)
	{
		a = number / (int)pow(10, i - 1);
		if (a == r)
		{
			a = k;
			changedNumber = 10 * (changedNumber + a);

		}
		else
		{
			changedNumber = 10 * (changedNumber + a);
		}
		number = number % (int)pow(10, i - 1);

	}
	changedNumber = changedNumber / 10;

	return changedNumber;

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
void testing()
{
	int testNumber = 1;

	workOfTesting(testNumber++, 2333, 4, 3, 5, 2555);
	workOfTesting(testNumber++, 54545, 5, 4, 9, 59595);
	workOfTesting(testNumber++, 4, 1, 4, 7, 7);
	workOfTesting(testNumber++, 0, 1, 0, 6, 6);
	workOfTesting(testNumber++, 111111, 6, 1, 8, 888888);
}
void workOfTesting(int testCaseNumber, int number, int i, int r, int k, int changedNumber)
{
	int act = chekingNumber(number, k, r, i);
	if (act == changedNumber)
	{
		cout << "Case #" << testCaseNumber << " well changed /)" << endl;
	}
	else
	{
		cout << "Case #" << testCaseNumber << " bad changed. /(" << endl;

	}
}
void workWithConsole()
{
	int number = enterNumber();
	int r = digitToRemove();
	int k = digitToSet();
	int i = numberOfDigits(number);

	chekingNumber(number, k, r, i);
}
void dysplayResult(int changedNumber)
{
	cout << "changed number is: " << changedNumber << endl;
}