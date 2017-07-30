#include <stdio.h>

#define MAXL 1000

char FirstWord[MAXL];
char SecondWord[MAXL];
int FSize;
int SSize; 
int CountMap[MAXL][MAXL];

int GetSize(char* word)
{
	int size = 0;
	for (int i = 0; i < MAXL; i++)
	{
		if (word[i] == '\0')
			break;
		size++;
	}
	return size;
}

int main()
{
	scanf("%s", FirstWord);
	scanf("%s", SecondWord);

	FSize = GetSize(FirstWord);
	SSize = GetSize(SecondWord);

	for (int i = 0; i < SSize; i++)
	{
		for (int j = 0; j < FSize; j++)
		{

		}
	}


	int N;
	scanf("%d", &N);

	return 0;
}