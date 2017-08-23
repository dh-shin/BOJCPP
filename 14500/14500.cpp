#include <stdio.h>

#define MAXN 501
#define DEPTH 4

int N, M;
int Map[MAXN][MAXN];
int Fin[MAXN][MAXN];
int MaxValue;
int MaxX[DEPTH + 1];
int MaxY[DEPTH + 1];

// Queue
int qx[MAXN];
int qy[MAXN];
int qd[MAXN];
int qv[MAXN];
int qpx[MAXN][DEPTH + 1];
int qpy[MAXN][DEPTH + 1];
int front, rear;

// Direction
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &Map[i][j]);
			Fin[i][j] = 0;
		}
	}
}

void Enqueue(int x, int y, int d, int v, int* _qpx, int* _qpy)
{
	qx[rear] = x;
	qy[rear] = y;
	qd[rear] = d;
	qv[rear] = v;

	for (int i = 1; i < d; i++)
	{
		qpx[rear][i] = _qpx[i];
		qpy[rear][i] = _qpy[i];
	}

	qpx[rear][d] = x;
	qpy[rear][d] = y;
	rear++;
}

void BFS(int x, int y)
{
	front = rear = 0;
	Enqueue(x, y, 1, Map[x][y], NULL, NULL);

	while (front < rear)
	{
		int _x = qx[front];
		int _y = qy[front];
		int _d = qd[front];
		int _v = qv[front];
		int* _qpx = qpx[front];
		int* _qpy = qpy[front];
		front++;

		printf("front : %d\n", front);

		// 높이 4에서 정지
		if (_d == DEPTH)
		{
			if (MaxValue < _v)
			{
				MaxValue = _v;
				printf("MaxValue: %d\n", MaxValue);
				for (int i = 1; i <= 4; i++)
				{
					MaxX[i] = _qpx[i];
					MaxY[i] = _qpy[i];
					printf("(%d %d)\n", MaxX[i], MaxY[i]);
				}
			}
			continue;
		}

		// 높이 4 미만일 경우 계속 진행
		for (int i = 0; i < 4; i++)
		{
			int nx = _x + dx[i];
			int ny = _y + dy[i];

			// 범위 안에 있으면
			if (nx >= 1 && ny >= 1 && nx <= N && ny <= M)
			{
				if (Fin[nx][ny] == 0)
				{
					bool isDup = false;
					for (int j = 1; j <= _d; j++)
					{
						if (_qpx[j] == nx && _qpy[j] == ny)
						{
							isDup = true;
							break;
						}
					}
					if (isDup == true)
						continue;
					Enqueue(nx, ny, _d + 1, _v + Map[nx][ny], _qpx, _qpy);
				}
			}
		}
		
	}

	Fin[x][y] = 1;
}

void Process()
{
	MaxValue = -1; 
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			BFS(i, j);
		}
	}
	
}

int main()
{
	Input();
	Process();
	printf("%d\n", MaxValue);
	for (int i = 1; i <= 4; i++)
		printf("(%d %d)\n", MaxX[i], MaxY[i]);
	scanf("%d", &N);
	return 0;
}