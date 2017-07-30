#include <stdio.h>

#define MAXN 9

int N, M;
int Map[MAXN][MAXN];

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &Map[i][j]);
		}
	}

}

void Process()
{

}


int main()
{
	Input();

	return 0;
}