#include <iostream>

using namespace std;

int enterNumber();
void chekingNumber(int, int, int);
int digitToRemove();
int numberOfDigits(int);


int main()
{
	int number = enterNumber();
	int r = digitToRemove();
	int i = numberOfDigits(number);

	chekingNumber(number, r, i);

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
void chekingNumber(int number, int r, int i)
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
	cout << "chaned number is:" << changedNumber << endl;

}

