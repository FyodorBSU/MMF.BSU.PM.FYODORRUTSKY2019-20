#include <iostream>
#include "Header.h"

using namespace std;

int* encoding(char const*, char const*);
char* decoding(int const*, int, char const*);
char* createRule(const char*);
void createRuleTest();
void encodingTests();
void decodingTests();
bool equals(const char*, const char*);
bool equals(const int*, int, const int*, int);
char* createRule(const char*, int);

int main()
{

	createRuleTest();
	encodingTests();
	decodingTests();
	system("pause");

	return 0;
}

char* createRule(const char* source)
{
	int size = getlength(source);
	char* rule = new char[size + 1];
	int i = 0;
	int end = size;
	for (int j = size - 1; i < end; i++, j--)
	{
		rule[i] = source[j];
	}
	rule[i] = '\0';

	return rule;
}
char* createRule(const char* source, int shift)
{
	char* array = createRule(source);
	int size = getlength(source);
	char* rule = new char[size];
	int i = 0, k = 0;
	for (int i = 0, k = shift; k < size && i < size - shift; i++, k++)
	{
		rule[i] = array[k];
	}
	for (int m = size - shift, h = 0; h < shift; m++, h++)
	{
		rule[m] = array[h];
	}

	rule[size] = '\0';

	return rule;
}

int* encoding(const char* source, const char* rule)
{
	int* encode = new int[getlength(source)];

	for (int i = 0; i < getlength(source); i++)
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

char* decoding(const int* source, int size, const char* rule)
{
	char* decode = new char[size + 1];
	int i = 0;
	for (; i < size; i++)
	{
		if (1 <= source[i] && source[i] <= 26)
		{
			decode[i] = rule[source[i] - 1];
		}
		else
		{
			decode[i] = source[i];
		}
	}
	decode[i] = '\0';

	return decode;
}

bool equals(const char* lhs, const char* rhs)
{
	int sizeLeft = getlength(lhs);
	int sizeRight = getlength(rhs);

	for (int i = 0; lhs[i] != '\0' || rhs[i] != '\0'; i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}

	}
	return true;

	if (sizeLeft != sizeRight)
	{
		return false;
	}
}

bool equals(const int* lhs, int l, const int* rhs, int r)
{
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
	}
	return true;
}

void createRuleTest()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* actual = createRule(source);

	const char* expected = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

	cout << "Test for creation rule " << (equals(actual, expected) ? "Passed." : "Failed.") << endl;

	delete[] actual;


	actual = createRule(source, 5);

	expected = "UTSRQPONMLKJIHGFEDCBAZYXWV";

	cout << "Test for creation rule(shift) " << (equals(actual, expected) ? "Passed." : "Failed.") << endl;

	delete[] actual;
}

void encodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	int* encode = encoding("Learn C++!", rule);

	cout << "Test for encoding " << (equals(encode, 10, new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }, 10) ? "Passed." : "Failed.") << endl;

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding " << (equals(encode, 29, new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, 29) ? "Passed." : "Failed.") << endl;


	rule = createRule(source, 5);

	encode = encoding("Learn C++!", rule);

	cout << "Test for encoding(shift) " << (equals(encode, 10, new int[10]{ 10, 17, 21, 4, 8, 32, 19, 43, 43, 33 }, 10) ? "Passed." : "Failed.") << endl;

	delete[] encode;

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding(shift) " << (equals(encode, 29, new int[29]{ 19, 7, 15, 13, 2, 7, 44, 32, 17, 4, 15, 7, 32, 3, 1, 9, 33, 32, 40, 18, 17, 3, 19, 21, 4, 2, 17, 3, 41 }, 29) ? "Passed." : "Failed.") << endl;

	delete[] encode;

	delete[] rule;
}

void decodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	char* decode = decoding(new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }, 10, rule);

	cout << "Test for decoding " << (equals(decode, "LEARN C++!") ? "Passed." : "Failed.") << endl;

	delete[] decode;

	decode = decoding(new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, 29, rule);

	cout << "Test for decoding " << (equals(decode, "COGITO, ERGO SUM! (DESCARTES)") ? "Passed." : "Failed.") << endl;

	delete[] decode;

	delete[] rule;


	rule = createRule(source, 5);

	decode = decoding(new int[10]{ 10, 17, 21, 4, 8, 32, 19, 43, 43, 33 }, 10, rule);

	cout << "Test for decoding(shift) " << (equals(decode, "LEARN C++!") ? "Passed." : "Failed.") << endl;

	delete[] decode;

	decode = decoding(new int[29]{ 19, 7, 15, 13, 2, 7, 44, 32, 17, 4, 15, 7, 32, 3, 1, 9, 33, 32, 40, 18, 17, 3, 19, 21, 4, 2, 17, 3, 41 }, 29, rule);

	cout << "Test for decoding(shift) " << (equals(decode, "COGITO, ERGO SUM! (DESCARTES)") ? "Passed." : "Failed.") << endl;

	delete[] decode;

	delete[] rule;
}