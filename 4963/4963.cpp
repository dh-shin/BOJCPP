#include <stdio.h>

#define LENG 51

int M, N;
int Map[LENG][LENG];
int Visit[LENG][LENG];
int ICount;

// 팔방향
// 북 -> 동 -> 남 -> 서 -> 북
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void Input()
{
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &Map[i][j]);
			Visit[i][j] = 0;
		}
	}
}

void DFS(int x, int y)
{
	Visit[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 범위 내에 있는 지 확인
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= M)
		{
			if (Map[nx][ny] == 1 && Visit[nx][ny] == 0)
				DFS(nx, ny);
		}
	}
}

void Process()
{
	ICount = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == 1 && Visit[i][j] == 0)
			{
				DFS(i, j);
				ICount++;
			}
		}
	}
}

void Output()
{
	printf("%d\n", ICount);
}

int main()
{
	while (1)
	{
		Input();
		if (M == 0 && N == 0)
			break;
		Process();
		Output();
	}
	return 0;
}