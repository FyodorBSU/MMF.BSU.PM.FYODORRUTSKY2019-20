#include <iostream>

using namespace std;

void menu();
void menuText();
void testing();
int enterNumber();
short logic(int);
void dysplayResult(short);
void workWithConsole();
void howManyUnities(int, int , short);
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
	short  sumForUnity = 0;
	for (; number > 0; )
	{
		if (number % 2 == 1)
		{

			sumForUnity++;
			number = number / 2;
		}
		else
		{
			number = number / 2;
			continue;

		}
	}

	return sumForUnity;
}
void dysplayResult(short sumForUnity)
{
	cout << "the quantity of unities is: " << sumForUnity << endl;
}
void workWithConsole()
{
	int number = enterNumber();

	int long long sumForUnity = logic(number);

	dysplayResult(sumForUnity);
}
void testing()
{
	int testNumber = 1;

	howManyUnities(testNumber++, 19, 3);
	howManyUnities(testNumber++, 1, 1);
	howManyUnities(testNumber++, 0, 0);
	howManyUnities(testNumber++, 122, 5);
	howManyUnities(testNumber++, 99, 4);
}
void howManyUnities(int testCaseNumber,int number, short sumForUnity)
{
	short act = logic(number);

	if (act == sumForUnity)
	{
		cout << "Case #" << testCaseNumber << " is right. /)" << endl;
		
	}
	else
	{
		cout << "Case #" << testCaseNumber << " is not right. /)" << endl;
	}

}