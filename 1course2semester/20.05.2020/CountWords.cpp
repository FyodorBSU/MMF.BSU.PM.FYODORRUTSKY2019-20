#define _CRT_SECURE_NO_WARNINGS
#include "CountWords.h"


CountWords::CountWords()
{
	strcpy(word, "\0");
	count = 0;
}

CountWords::CountWords(char* word, int number)
{
	strcpy(this->word, word);
	this->count = number;
}

inline char* CountWords::getWord()
{
	return word;
}

inline int CountWords::getCount()
{
	return count;
}

void CountWords::setWord(char* source)
{
	for (unsigned int i = 0; i < strlen(source); i++)
	{
		word[i] = source[i];
	}
}

void CountWords::setCount(int count)
{
	this->count = count;
}

ostream& operator<<(ostream& stream, CountWords& WordAndNumber)
{
	stream << WordAndNumber.word << WordAndNumber.count;
	return stream;
}
