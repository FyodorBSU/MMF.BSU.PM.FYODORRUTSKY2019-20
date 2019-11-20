#include <iostream>

using namespace std;

int enterNumber();
void displayResult(bool, int);
bool chekingNumber(int);


int main()    
{
	int number = enterNumber();

	bool t = chekingNumber(number);

	

	displayResult(t,number);

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
bool chekingNumber(int number)
{

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
