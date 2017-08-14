#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int T;

int main()
{
	srand(time(NULL));

	FILE* fp = fopen("sample.txt", "w");

	T = 200;
	fprintf(fp, "%d\n", T);
	for (int i = 0; i < T; i++)
	{
		//int k = rand() % 100 + 5;
		int k = 50;
		fprintf(fp, "%d\n", k);
		for (int j = 0; j < k; j++)
		{
			int chance = rand() % 5 + 1;
			if (chance <= 3)
			{
				int chance2 = rand() % 2 + 1;
				if (chance2 == 1)
				{
					fprintf(fp, "D 1\n");
				}
				else{
					fprintf(fp, "D -1\n");
				}
			}
			else{
				long long int num = rand() % 100;
				fprintf(fp, "I %lld\n", num);
			}
		}
	}

	fclose(fp);
}