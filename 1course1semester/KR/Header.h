#pragma once

#include <iostream>

using namespace std;

int getlength(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}

	int length = 0;
	while (source[length])
	{
		length++;
	}
	return length;
}
bool isAlphabet(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z' || 'a' <= symbol && symbol <= 'z';
}
bool isLower(char symbol)
{
	return 'a' <= symbol && symbol <= 'z';
}
char toUpper(char symbol)
{
	if (isAlphabet(symbol) && isLower(symbol))
	{
		return symbol - 32;
	}
	return symbol;
}
int findLetter(const char* array, int const n, char const value)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == value)
		{
			return i;
		}
	}
}
