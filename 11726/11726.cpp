#include <stdio.h>

#define MAXN 1001
#define DIV 10007

long long int C[MAXN];
int N;

int main()
{
	scanf("%d", &N);
	C[1] = 1;
	C[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		C[i] = (C[i - 1] % DIV) + (C[i - 2] % DIV);
		C[i] = C[i] % DIV;
	}

	printf("%lld\n", C[N]);

	return 0;
}