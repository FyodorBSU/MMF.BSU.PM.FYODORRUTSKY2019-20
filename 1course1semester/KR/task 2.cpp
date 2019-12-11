#include <iostream>
#include "Header.h"

using namespace std;

//int* encoding(char const*, char const*);
//char* decoding(int const*, int, const char*);
char* createRule(const char*);
void createRuleTest();
//void encodingTests();
//void decodingTests();
bool equals(const char*, const char*);
//bool equals(const int*, int, const int*);

int main()
{

	createRuleTest();
	encodingTests();
	//decodingTests();
	//system("pause");

	return 0;
}

char* createRule(const char* source)
{
	int size = getlength(source);
	char* rule = new char[size + 1];
	int i = 0;
	for (int end = size - 1; i < end; i++, end--)
	{
		rule[i] = source[end];
	}
	rule[i] = '\0';

	return rule;
}

int* encoding(const char* source, const char* rule)
{
	int* encode = new int[getlength(source) + 1];

	for (int i = 0; i < (getlength(source) + 1); i++)
	{
		if (isAlphabet(source[i]))
		{
			encode[i] = findLetter(rule, getlength(rule), toUpper(source[i])) + 1;
		}
		else
		{
			encode[i] = source[i];
		}
	}

	return encode;
}

char* decoding(const int* source, int size, char* rule) 
{
	char* decode = new char[256];

	for (int i = 0; i < size; i++)
	{
		if (1 <= source[i] || source[i] <= 26)
		{
			int n = source[i];
			decode[i] = rule[n];
		}
		else
		{
			decode[i] = rule[i];
		}
	}

	return decode;
}

bool equals(const char* lhs, const char* rhs)
{
	bool t = true;

	for (int i = 0; lhs[i] != '\0' || rhs[i] != '\0'; i++)
	{
		if (lhs[i] == rhs[i])
		{
			return true;
		}
		else
		{
			return false;
			break;
		}
	}
	if (sizeof(*lhs) != sizeof(*rhs))
	{
		return false;
	}
}

bool equals(const int* lhs, int l, const int* rhs, int r)
{
	bool t = true;
	if (l != r)
	{
		return false;
	}
	for (int i = 0; i < l || i < r; i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;

		}
		else
		{
			return true;
		}
	}
	
}

void createRuleTest()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char* actual = createRule(source);
	const char* expected = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	cout << "Test for creation rule " << (equals(actual, expected) ? "Passed." : "Failed.") << endl;
}

void encodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	int* encode = encoding("Learn C++!", rule);

	cout << "Test for encoding " << (equals(encode, 10, new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }), 10)) ? "Passed." : "Failed.") << endl;

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding " << (equals(encode, 29, new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }), 29)) ? "Passed." : "Failed.") << endl;

}

//void decodingTests()
//{
//	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//
//	const char* rule = createRule(source);
//
//	char* decode = decoding(new int[10]{ 10, 17, 21, 4, 8, 32, 19, 43, 43, 33 }, 10, rule);
//
//	cout << "Test for decoding " << (equals(decode, "LEARN C++!") ? "Passed." : "Failed.") << endl;
//
//	decode = decoding(new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, 29, rule);
//
//	cout << "Test for decoding " << (equals(decode, "COGITO, ERGO SUM! (DESCARTES)") ? "Passed." : "Failed.") << endl;
//}