#include <iostream>
#include "Header.h"

using namespace std;

typedef int(*rationalFraction)(RationalFraction, RationalFraction);
RationalFraction Sum(RationalFraction, RationalFraction);
RationalFraction Multiplication(RationalFraction, RationalFraction);
RationalFraction Reverse(RationalFraction);
RationalFraction Power(RationalFraction, int);
void menu();
void Console();
void testing();
void testCase();

int main()
{
	menu();

	return 0;
}
void menu()
{
	enum button { console = '1', test = '2', exit = '3' };
	char button = '0';
	while (button)
	{
		cout << "Press 1 to work with console." << endl;
		cout << "Press 2 to start test." << endl;
		cout << "Press 3 to exit." << endl;
		cin >> button;
		system("cls");
		switch (button)
		{
		case console:

			Console();
			system("pause");
			break;

		case test:

			testing();
			system("pause");
			break;

		case exit:

			return;

		default:

			cout << "Error. Try again." << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	}
}
void Console()
{
	char button = '0';
	while (button)
	{
		cout << "Press 1 to solve sum."<< endl;
		cout << "Press 2 to solve product."<< endl;
		cout << "Press 3 to reverse." << endl;
		cout << "Press 4 to raise in power."<< endl;
		cout << "Press 0 to exit." << endl;
		cin >> button;
		system("cls");
		if (button == '0')
		{
			return;
		}
		
		RationalFraction expr1, expr2;
		cout<< "Enter the first rational fraction." <<endl;
		expr1.Enter();
		cout <<"Enter the second rational fraction."<< endl;
		expr2.Enter();
		
		switch (button)
		{
		case '1':
			Sum(expr1, expr2).display();
			system("pause");
			break;
		case '2':
			Multiplication(expr1, expr2).display();
			system("pause");
			break;
		case '3':
			Reverse(expr1).display();
			cout<< endl;
			Reverse(expr2).display();
			system("pause");
			break;
		case '4':
			short exponent;
			cout<< "Enter the exponent." <<endl;
			cin>> exponent;
			Power(expr1, exponent).display();
			cout<< endl;
			Power(expr2, exponent).display();
			system("pause");
			break;
		default:
			cout<< "Error. Try again."<< endl;
			system("pause");
			system("cls");
		}
		system("cls");
	}
}
void testing()
{

}
void testCase()
{

}
RationalFraction Sum(RationalFraction fraction1, RationalFraction fraction2)
{
	RationalFraction sum;

	sum.denominator = fraction2.denominator * fraction1.denominator;
	sum.numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;

	return sum;
}
RationalFraction Multiplication(RationalFraction fraction1, RationalFraction fraction2)
{
	RationalFraction product;

	product.numerator = fraction1.numerator * fraction1.numerator;
	product.denominator = fraction1.denominator * fraction2.denominator;

	return product;
}
RationalFraction Power(RationalFraction fraction, int power)
{
	fraction.numerator = pow(fraction.numerator, power);
	fraction.denominator = pow(fraction.denominator, power);
	
	return fraction;
}
RationalFraction Reverse(RationalFraction fraction)
{
	RationalFraction reverse;

	reverse.numerator = fraction.denominator;
	reverse.denominator = fraction.numerator;

	return reverse;
}