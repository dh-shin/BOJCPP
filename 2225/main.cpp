#include <stdio.h>

#define MAX 201
int N, K;
int C[MAX][MAX];

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= K; i++)
		C[0][i] = 1;
	for (int i = 1; i <= K; i++)
		for (int j = 1; j <= N; j++){
			int sum = 0;
			for (int m = 0; m <= j; m++)
			{
				sum += C[m][i - 1];
				sum %= 1000000000;
			}
			C[j][i] = sum;
		}
	
	printf("%d\n", C[N][K]);
	return 0;
}