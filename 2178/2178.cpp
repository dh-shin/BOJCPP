#include <stdio.h>

#define MAXN 101
#define MAXQ 100001

int N, M;
int map[MAXN][MAXN];
int visit[MAXN][MAXN];

int front = 0, rear = 0;
int qx[MAXQ];
int qy[MAXQ];
int ql[MAXQ];

void enqueue(int x, int y, int l)
{
	qx[rear] = x;
	qy[rear] = y;
	ql[rear] = l;
	rear++;
}

int xd[] = { -1, 1, 0, 0 };
int yd[] = { 0, 0, 1, -1 };

void BFS(int x, int y, int l)
{
	enqueue(x, y, l);
	visit[y][x] = 1;
	while (front < rear && (qx[front] != M || qy[front] != N))
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = qx[front] + xd[i];
			int ny = qy[front] + yd[i];

			if (nx > 0 && ny > 0 && nx <= M && ny <= N && map[ny][nx] == 1 && visit[ny][nx] == 0)
			{
				enqueue(nx, ny, ql[front] + 1);
				visit[ny][nx] = 1;
			}
		}
		front++;
	}
}

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%1d", &map[i][j]);
}

void Process()
{
	BFS(1, 1, 1);
}

void Output()
{
	if (front < rear)
		printf("%d", ql[front]);
}

int main()
{
	Input();
	Process();
	Output();

	return 0;
}