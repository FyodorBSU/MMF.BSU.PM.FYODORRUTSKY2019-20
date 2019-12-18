#include <iostream>

using namespace std;

int getLength(const char*);
bool isDigit(const char);
void reverseNumber(int&);
//etc
int parseStringToSumWithUnsigned(const char*);
int parseStringToSumWithSigned(const char*);
void parseStringToSumWithUnsignedTest();
void parseStringToSumWithSignedTest();


int main()
{
	parseStringToSumWithUnsignedTest();
	parseStringToSumWithSignedTest();
	system("pause");
	return 0;
}

int parseStringToSumWithUnsigned(const char* source)
{
	int number = 0, buffer = 0, j = 0;
	for (int i = 0; i < getLength(source);)
	{
		if (isDigit(source[i]))
		{
			for (j = i; isDigit(source[j]); j++, i++)
			{
				number += (source[j] - '0');
				number *= 10;
			}
			if (source[j - 1] != 0)
			{
				number /= 10;
			}
			buffer += number;
			number = 0;
		}
		else
		{
			i++;
		}
	}
	return buffer;
}

int parseStringToSumWithSigned(const char* source)
{
	int number = 0, buffer = 0, j = 0;
	for (int i = 0; i < getLength(source);)
	{
		if (isDigit(source[i]))
		{
			int sign = 1;
			for (j = i; isDigit(source[j]); j++, i++)
			{
				number += (source[j] - '0');
				number *= 10;
				sign++;
			}
			if (source[j - 1] != 0)
			{
				number /= 10;
			}
			if (source[j - sign] == '-')
			{
				buffer -= number;
			}
			else
			{
				buffer += number;
			}
			sign = 0;
			number = 0;
		}
		i++;
	}
	return buffer;
}

bool isDigit(const char symbol)
{
	if (symbol >= '0' && symbol <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void reverseNumber(int& number)
{
	int reverse = 0;

	while (number > 0)
	{
		reverse = reverse * 10 + number % 10;
		number /= 10;
	}
	number = reverse;
}

int getLength(const char* source)
{
	int length = 0;

	while (source[length])
	{
		length++;
	}

	return length;
}

void parseStringToSumWithUnsignedTest()
{
	bool result = parseStringToSumWithUnsigned("1235+-8+*** 90") == 1333;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithUnsigned("1235+-8+* 4** -22--- 9") == 1278;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithUnsigned("998*/*/--66...33==600") == 1697;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

}

void parseStringToSumWithSignedTest()
{
	bool result = parseStringToSumWithSigned("1235+-8+*** 90") == 1317;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithSigned("1235+-8+* 4** -22--- 9") == 1218;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithSigned("998*/*/--66...33==60") == 1025;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

}