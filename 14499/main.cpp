#include <stdio.h>

#define MAXN 21
#define MAXK 1001

int N, M; // ���� Row, Column
int x, y; // �ֻ��� ��ǥ
int K; // ����� ����

int Map[MAXN][MAXN];

// (0, 0) ���� ����

// ��, ��, ��, ��
// 1, 2, 3, 4

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int North;
int South;
int Line[4];
// 0: ����
// 1: ����
// 2: ����
// 3: �ٴ�

void Input()
{
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &Map[i][j]);
		}
	}

	North = 0;
	South = 0;
	for (int i = 0; i < 4; i++)
		Line[i] = 0;
}

void RollDice(int direct)
{
	if (direct == 1) // ����
	{
		// Line�� ���������� Shift
		int end = Line[3];
		for (int j = 2; j >= 0; j--)
			Line[j + 1] = Line[j];
		Line[0] = end;
	}
	else if (direct == 2) // ����
	{
		// Line�� �������� Shift
		int first = Line[0];
		for (int j = 1; j <= 3; j++)
			Line[j - 1] = Line[j];
		Line[3] = first;
	}
	else if (direct == 3) // ����
	{
		int temp = North;
		North = Line[1];
		Line[1] = South;
		South = Line[3];

		Line[3] = temp;
	}
	else // ����
	{
		int temp = South;
		South = Line[1];
		Line[1] = North;
		North = Line[3];
		Line[3] = temp;
	}
}

bool ChangePosition(int direct)
{
	int nx = x + dx[direct];
	int ny = y + dy[direct];

	if (nx >= 0 && ny >= 0 && nx < N && ny < M)
	{
		// ���� �ȿ� ������ ��ġ ���� �� true ����
		//printf("Position Changed!!! : (%d %d) -> (%d %d)\n", x, y, nx, ny);
		x = nx;
		y = ny;
		return true;
	}
	else
	{
		// ���� �ȿ� ������ false ����
		return false;
	}
}

void PrintMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", Map[i][j]);
		}
		printf("\n");
	}
}

void PrintDice()
{
	printf("Dice: \n");
	printf("%d\n", North);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", Line[i]);
	}
	printf("\n%d\n\n", South);
}

void Process()
{
	for (int i = 0; i < K; i++)
	{
		int direct;
		scanf("%d", &direct);

		//printf("=========DEBUG START===========");
		//printf("iter : %d / Direction : %d\n", i, direct);
		//PrintMap();
		if (ChangePosition(direct) == true) // false �̸� �ƹ��͵� ���Ѵ�.
		{
			// ��ġ�� �̹� ChangePosition���� ���� ���� �ư�,
			// �ֻ��� ���� ����
			RollDice(direct);

			// ���� ���� ó��
			if (Map[x][y] == 0) // �̵��� ĭ�� �� �ִ� ���� 0�� ���,
			{
				// �ٴ� ���� ĭ�� ����ȴ�.
				Map[x][y] = Line[3];
			}
			else // �̵��� ĭ�� ���ִ� ���� 0�� �ƴ� ���,
			{
				// ĭ ���� �ٴ����� ����ǰ�
				Line[3] = Map[x][y];
				// ĭ ���� 0�� �ȴ�.
				Map[x][y] = 0;
			}

			// �ֻ��� ��� ���� ���
			printf("%d\n", Line[1]);
		}
		//PrintDice();
		//PrintMap();
		//printf("====================\n");
	}
}

int main()
{
	Input();
	Process();
	scanf("%d", &N);
	return 0;
}