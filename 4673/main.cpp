#include <stdio.h>

#define MAXN 10001
int Kap[MAXN];

int GetKap(int x)
{
	int target = x;
	int len = 0;
	do{
		x = x / 10;
		len++;
	} while (x > 0);

	int val = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		int div = 1;
		for (int j = 0; j < i; j++)
			div *= 10;
		val += target / div;
		target %= div;
	}
	return val;
}

int main()
{
	for (int i = 1; i < MAXN; i++)
	{
		int kap = i + GetKap(i);
		Kap[kap] = 1;
	}

	for (int i = 1; i < MAXN; i++)
	{
		if (Kap[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}