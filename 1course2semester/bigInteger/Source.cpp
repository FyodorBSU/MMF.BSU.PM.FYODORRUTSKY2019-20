#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BigInteger.h"

using namespace std;



int main()
{
	const char* number1 = "94287657";
	BigInteger number(number1);
	cout << number;
}
