#include <iostream>
#include "workWithArrays.h"

using namespace std;

char** createWords(char[], int&);
void displayWords(char**, int);
void bubbleSort(char**, int&);
int arraysSymbol(char*, int, char);
void bubbleSortWithSymbol(char**, int&, char);
void bubbleSortAlphavite(char**, int&);

int main()
{
	char source[] = "“The Less I Know the Better” describes the pain of a man feeling left out in a love triangle, illustrated with a complex arrangement of groovy bass hooks, sensual Rhodes piano chords, and moody synth textures.";
	int n = 0;

	char** words = createWords(source, n);
	bubbleSort(words, n);
	displayWords(words, n);

	char symbol;
	cout << "enter the symbol:" << endl;
	cin >> symbol;

	bubbleSortWithSymbol(words, n, symbol);
	displayWords(words, n);

	bubbleSortAlphavite(words, n);
	displayWords(words, n);



		return 0;
}
void displayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << words[i] << " " << endl;
	}
}
char** createWords(char source[], int& k)
{
	int const N = 256;
	int i = 0, j = 0;
	k = 0;
	bool isWordCreating = false;
	char* booferWords[N];
	char boofer[N] = "";
	while (source[i])
	{
		if (isAlphabet(source[i]))
		{
			boofer[j] = source[i];
			j++;
			isWordCreating = true;
		}
		else if (isWordCreating || source[i + 1] == '\0')
		{
			booferWords[k] = createString(boofer, j);
			copyString(boofer, "");
			k++;
			j = 0;
			isWordCreating = false;
		}
		i++;
	}
	if (isWordCreating)
	{
		booferWords[k] = createString(boofer, j);
		k++;
	}

	char** words = new char* [k];

	for (int i = 0; i < k; i++)
	{
		words[i] = booferWords[i];
	}

	return words;
}
void bubbleSort(char** words, int& k)
{
	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;
		for (int j = k - 1; j > i; j--)
		{
			if (words[j] < words[j - 1])
			{
				swap(words[j], words[j - 1]);
				isSorted = false;
			}
		}
		i++;
	}
}
int arraysSymbol(char* array, int lengthArray, char symbol)
{
	int calc = 0;
	for (int i = 0; i <= lengthArray; i++)
	{
		if (array[i] == symbol)
		{
			calc++;
		}
		else
		{
			continue;
		}
	}
	return calc;
}
void bubbleSortWithSymbol(char** words, int& k, char symbol)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = k - 1; j > i; j--)
		{
			int counterFirst = arraysSymbol(words[j], getlength(words[j]), symbol);
			int counterSecond = arraysSymbol(words[j - 1], getlength(words[j - 1]), symbol);
			if (counterFirst < counterSecond)
			{
				swap(words[j], words[j - 1]);
			}
		}
	}
}
void bubbleSortAlphavite(char** words, int& k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = k - 1; j > i; j--)
		{
		
			if (compare(words[j-1],getlength(words[j-1],words[j],getlength(words[j],false)
			{
				swap(words[j], words[j - 1]);
			}
		}
	}
}


