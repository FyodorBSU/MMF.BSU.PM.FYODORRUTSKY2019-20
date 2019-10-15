#include <iostream>

using namespace std;

int enterNumber();
void displayResult(int, int);
int chekingNumber(int);
int chekingNumbersOfDigits(int);


int main()    
{
	int number = enterNumber();
	int reverse = chekingNumber(number);

	displayResult(number, reverse);

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
int chekingNumber(int number)
{
	int i = 1, clone = number, reverse=0, c=0;

	for(number;i>=c ;c++ )
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
