#include <iostream>

using namespace std;

int enterNumber();
void displayResult(bool, int);
bool chekingNumber(int);
void menu();
void menuText();
void testing();
void workWithConsole();
void primeOrNotTesting(int, int, bool);


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
	

	return number;
}
bool chekingNumber(int number)
{
	number = abs(number);
	bool t = true;
	if (number == 0 || number == 1)
	{
		t = false;
	}
		else
		{
			for (int i = 2; i < number; i++)
			{
				if (number % i == 0)
				{
					t = false;
					break;
				}
				else
				{
					
					continue;
				}
			}
		}
	return t;
}
void displayResult(bool t, int number)
{
	if (t)
	{
		cout << number << " is prime number" << endl;
	}
	else
	{
		cout << number << " is not prime number" << endl;
	}
}
void menuText()
{
	cout << "press 'c' to work with console" << endl;
	cout << "press 't' to start tests" << endl;
	cout << "press 'r' to exit" << endl;
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

void workWithConsole()
{
	int number = enterNumber();


	bool t = chekingNumber(number);

	displayResult(number, t);
}


void testing()
{
	int testNumber = 1;

	primeOrNotTesting(testNumber++, 13,1 );
	primeOrNotTesting(testNumber++, 27, 0);
	primeOrNotTesting(testNumber++, 101, 1);
	primeOrNotTesting(testNumber++, 6, 0);
	primeOrNotTesting(testNumber++, 0, 0);
}

void primeOrNotTesting(int testCaseNumber, int number,bool t)
{
	bool act = chekingNumber(number);

	if (act==t)
	{
		cout << "Case #" << testCaseNumber << " is prime. /)" << endl;
	}
	else
	{
		cout << "Case #" << testCaseNumber << " IS NOT prime. /(" << endl;
		//cout << "actual = " << actual << ", but expacted =" << expectedCount << endl;
	}
}