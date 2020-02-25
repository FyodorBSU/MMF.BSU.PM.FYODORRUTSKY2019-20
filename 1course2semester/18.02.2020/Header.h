#pragma once

#include <ctime>
#include <iostream>

using namespace std;

class RationalFraction
{
public:
	int numerator, denominator;
public:
	RationalFraction()
	{
		numerator = 1;
		denominator = 1;
	}
	void display()
	{
		if (denominator == 0)
		{
			throw std::runtime_error("Division by zero!");
		}
		if (numerator * denominator > 0)
		{
			cout << abs(numerator) / LCD() << "/" << abs(denominator) / LCD() << endl;
		}
		else if (abs(denominator) / LCD() == 1)
		{
			cout << "-" << abs(numerator) / LCD() << endl;
		}
		else
		{
			cout << "-" << abs(numerator) / LCD() << "/" << abs(denominator) / LCD() << endl;
		}
	}
	int LCD()
	{
		int min = abs(numerator < denominator ? numerator : denominator);
		int LCD = min;
		if (min == 0)
		{
			return 1;
		}
		while (min > 0)
		{
			if (numerator % min == 0)
			{
				if (denominator % min == 0)
				{
					LCD = min;
					break;
				}
			}
			min--;
		}
		return LCD;
	}
	void Enter()
	{
		denominator = 0;
		while (denominator == 0)
		{
			cout << "Enter the numerator:" << endl;
			cin >> numerator;
			cout << "Enter the denominator:" << endl;
			cin >> denominator;
			if(denominator==0)
			{
				system("cls");
			}
		}
		
	}
};