#include <stdio.h>

#define MAXN 11

int C[MAXN];
int T, N;

int main()
{
	C[1] = 1;
	C[2] = 2;
	C[3] = 4;

	for (int i = 4; i < MAXN; i++)
		C[i] = C[i - 1] + C[i - 2] + C[i - 3];

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		printf("%d\n", C[N]);
	}

	return 0;
}