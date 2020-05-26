#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "CountWords.h"

using namespace std;

const int N = 64;

void inputBinary(const char*, const char*, const char*);
void cleanString(char*);
void cleanString(char**, int);
char** parse(char*, int&);
int countRepite(char**, char*, int);
void displayBinary(const char*);
void deleteMemory(char*);
void deleteMemory(char**, int);


int main()
{
	const char* path1 = "TEXT.txt";
	const char* path2 = "WORDS.txt";
	const char* pathBin = "WORDSANDCOUNTS.bin";

	inputBinary(path1, path2, pathBin);

	displayBinary(pathBin);
	
	return 0;
}

void inputBinary(const char* path1, const char* path2, const char* pathBin)
{
	ofstream toBin(pathBin, ios::binary | ios::app);
	ifstream from2(path2);
	
	char* buffer1 = new char[N] {};
	char* buffer2 = new char[N] {};

	while (!from2.eof())
	{
		ifstream from1(path1);

		from2.getline(buffer2, 16, ' ');

		int count = 0;
		while (!from1.eof())
		{
			from1.getline(buffer1, 16, ' ');
			int n = 0;
			char** words = parse(buffer1, n);
			count += countRepite(words, buffer2, n);

			cleanString(words, n);
			deleteMemory(words, n);
		}

		from1.close();

		CountWords buffer(buffer2, count);
		toBin.write((char*)&buffer, sizeof(CountWords));

		cleanString(buffer1);
		cleanString(buffer2);
	}

	delete[] buffer1, buffer2;
	toBin.close();
}

void cleanString(char* source)
{
	int size = strlen(source);
	for (int i = 0; i < size; ++i)
	{
		source[i] = '\0';
	}
}

void cleanString(char** source, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cleanString(source[i]);
	}
}

char** parse(char* source, int& n)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char* [strlen(source)];
	n = 0;
	char* pword = strpbrk(source, symbols);
	while (pword)
	{
		int length = strspn(pword, symbols);
		words[n] = new char[length + 1];
		strncpy(words[n], pword, length);
		words[n][length] = '\0';
		pword += length;
		pword = strpbrk(pword, symbols);
		n++;
	}

	return words;
}

int countRepite(char** text, char* word, int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(text[i], word) == 0)
		{
			count++;
		}
	}
	return count;
}

void displayBinary(const char* path)
{
	ifstream from(path, ios::binary);

	CountWords buffer;
	while (from.read((char*)&buffer, sizeof(CountWords)))
	{
		cout << buffer << endl;
	}

	from.close();
}

void deleteMemory(char* source)
{
	delete[] source;
}

void deleteMemory(char** source, int n)
{
	for (int i = 0; i < n; ++i)
	{
		deleteMemory(source[i]);
	}
	delete[] source;
}