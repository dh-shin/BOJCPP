#include <stdio.h>

#define MAXN 101

int N;
int Map[MAXN][MAXN];
long long int Path[MAXN][MAXN];

void Input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &Map[i][j]);
			Path[i][j] = -1;
		}
	Path[1][1] = 1;
}

long long int GetPathNum(int x, int y)
{
	if (Path[x][y] != -1)
		return Path[x][y];

	long long int sum = 0;
	for (int i = 1; i < x; i++)
	{
		int dist = x - i;
		if (Map[i][y] == dist)
			sum += GetPathNum(i, y);
	}
	for (int i = 1; i < y; i++)
	{
		int dist = y - i;
		if (Map[x][i] == dist)
			sum += GetPathNum(x, i);
	}
	
	Path[x][y] = sum;
	return sum;
}

int main()
{
	Input();
	printf("%lld\n", GetPathNum(N, N));
	return 0;
}