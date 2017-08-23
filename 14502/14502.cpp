#include <stdio.h>

#define MAXN 9
#define MAXC 65

int N, M;
int Map[MAXN][MAXN];
int WallMap[MAXN][MAXN];
int Visit[MAXN][MAXN];
int MaxSafe = -1;

// ����
int Bx[MAXC];
int By[MAXC];
int BCount;
int Flag[MAXC];

// �̵� (��, ��, ��, ��)
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void CountSafeZone()
{
	int count = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (WallMap[i][j] == 0)
				count++;
		}

	if (MaxSafe < count)
		MaxSafe = count;
}

void DFS(int x, int y)
{
	Visit[x][y] = 1;
	WallMap[x][y] = 2; // ���̷����� ������

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= M)
		{
			// �� ĭ�̸� (Visit�� 0�� ��) ���̷��� ���� ����
			if (WallMap[nx][ny] == 0)
				DFS(nx, ny);
		}
	}
}

void ProcessCombination()
{
	/*
	for (int i = 0; i < MAXC; i++)
	{
		if (Flag[i] == 1)
			printf("(%d %d) ", Bx[i], By[i]);
	}
	printf("\n");
	*/

	// Map�� WallMap���� ����, Visit �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			WallMap[i][j] = Map[i][j];
			Visit[i][j] = 0;
		}	

	for (int i = 0; i < MAXC; i++)
	{
		// �� ġ��
		if (Flag[i] == 1)
			WallMap[Bx[i]][By[i]] = 1;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			// ���̷��� �̸鼭 Visit ���� �ʾ����� DFS ����
			if (WallMap[i][j] == 2 && Visit[i][j] == 0)
				DFS(i, j);
		}

	CountSafeZone();
}

void ClearFlag()
{
	for (int i = 0; i < MAXC; i++)
		Flag[i] = 0;
}

void Input()
{
	// �Է� �ޱ�
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &Map[i][j]);

			// ���� ���� �� �ִ� �ĺ� (�� ĭ) �ε��� ä���
			if (Map[i][j] == 0)
			{
				Bx[BCount] = i;
				By[BCount] = j;
				BCount++;
			}
		}
	}
}

void Combination(int n, int r)
{
	if (n == r)
	{
		for (int i = 0; i < n; i++)
			Flag[i] = 1;
		ProcessCombination();
		ClearFlag();
		return;
	}
	if (r == 1)
	{
		for (int i = 0; i < n; i++)
		{
			Flag[i] = 1;
			ProcessCombination();
			Flag[i] = 0;
		}
		return;
	}
	
	Flag[n - 1] = 1;
	Combination(n - 1, r - 1);

	Flag[n - 1] = 0;
	Combination(n - 1, r);
}

void Process()
{
	Combination(BCount, 3);
}

int main()
{
	Input();
	Process();
	printf("%d\n", MaxSafe);
	return 0;
}