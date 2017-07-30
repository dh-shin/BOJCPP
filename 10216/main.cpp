#include <stdio.h>

#define MAXN 3001

int T;
int N;
int x[MAXN];
int y[MAXN];
int R[MAXN];
int AdjMat[MAXN][MAXN];
int Visit[MAXN];
int Count;

void Input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &x[i], &y[i], &R[i]);
		Visit[i] = 0;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			AdjMat[i][j] = 0;
}

bool DFS(int a)
{
	// 이미 방문한 곳이면 false 리턴
	if (Visit[a] == 1)
		return false;

	Visit[a] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (a == i)
			continue;
		if (AdjMat[a][i] == 1 && Visit[i] == 0)
			DFS(i);
	}
	return true;
}

void Process()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			int xs = x[i] - x[j];
			int ys = y[i] - y[j];
			int dist1 = xs * xs + ys * ys; // 두 좌표간 거리
			int dist2 = R[i] * R[i] + R[j] * R[j] + 2 * R[i] * R[j]; // 반지름 합
			if (dist1 <= dist2)
			{
				AdjMat[i][j] = 1;
				AdjMat[j][i] = 1;
			}
		}
	}

	Count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (DFS(i) == true)
			Count++;
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		Input();
		Process();
		printf("%d\n", Count);
	}

	return 0;
}