#include <stdio.h>

#define MAXL 1001
#define MAXQ 1000001

int M, N;
int Map[MAXL][MAXL];
int Day[MAXL][MAXL];

// BFS
int QX[MAXQ];
int QY[MAXQ];
int front = 0, rear = 0;

// Direction
int DX[] = { 0, 0, -1, 1 };
int DY[] = { -1, 1, 0, 0 };

void Enqueue(int x, int y)
{
	QX[rear] = x;
	QY[rear] = y;
	rear++;
}

void Input()
{
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &Map[i][j]);
			Day[i][j] = -1;
		}
	}
}

void Process()
{
	int day = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			// 익었으면서, Day가 -1인데
			// 익힐 대상이 없으면 Day만 0으로 갱신
			// 익힐 대상이 있으면 Day 0으로 갱신하고 대상을 enqueue
			if (Map[i][j] == 1 && Day[i][j] == -1)
			{
				Day[i][j] = day;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + DX[k];
					int ny = j + DY[k];

					// 범위 안쪽
					if (nx >= 1 && ny >= 1 && nx <= N && ny <= M)
					{
						// 안 익었고, 큐에도 들어간 적 없으면
						if (Map[nx][ny] == 0 && Day[nx][ny] == -1)
						{
							Enqueue(nx, ny);
							Map[nx][ny] = 1; // 안 익었던 것이 익었고
							Day[nx][ny] = day + 1; // 익은 날짜 표시
						}
					}
				}
			}
		}
	}

	while (front < rear)
	{
		int x = QX[front];
		int y = QY[front];
		front++;

		int day = Day[x][y];
		for (int k = 0; k < 4; k++)
		{
			int nx = x + DX[k];
			int ny = y + DY[k];

			// 범위 안쪽
			if (nx >= 1 && ny >= 1 && nx <= N && ny <= M)
			{
				// 안 익었고, 큐에도 들어간 적 없으면
				if (Map[nx][ny] == 0 && Day[nx][ny] == -1)
				{
					Enqueue(nx, ny);
					Map[nx][ny] = 1; // 안 익었던 것이 익었고
					Day[nx][ny] = day + 1; // 익은 날짜 표시
				}
			}
		}
	}
}

void Output()
{
	int max = -1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			// 여전히 익지 않은 부분이 발견됨
			if (Day[i][j] == -1 && Map[i][j] == 0)
			{
				printf("%d\n", Day[i][j]);
				return;
			}

			if (max < Day[i][j])
				max = Day[i][j];
		}
	}
	printf("%d\n", max);
}

int main()
{
	Input();
	Process();
	Output();
	return 0;
}