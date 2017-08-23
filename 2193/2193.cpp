#include <stdio.h>

#define MAXN 91

long long int PN[MAXN][2];
int N;

int main()
{
	scanf("%d", &N);
	PN[1][1] = 1;
	PN[2][0] = 1;

	for (int i = 3; i <= N; i++)
	{
		PN[i][0] = PN[i - 1][0] + PN[i - 1][1];
		PN[i][1] = PN[i - 1][0];
	}

	printf("%lld\n", PN[N][0] + PN[N][1]);

	return 0;
}