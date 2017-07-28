#include <stdio.h>

#define MAX 101

int N, K;
int L;

int Map[MAX][MAX];
// 0: ��ĭ
// 1: ���
// 2: ��

int MapDir[MAX][MAX];

int Rot[MAX][2];
// 0: ����
// 1: ������

// �� �� �� ��
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int D;
int hX, hY;
int tX, tY;
int second;

void GoNextPos()
{
	MapDir[hX][hY] = D; // ���ư� ������ ���
	hX = hX + dx[D];
	hY = hY + dy[D];
}

void FindNewTail()
{
	int d = MapDir[tX][tY];
	tX = tX + dx[d];
	tY = tY + dy[d];
}

void Input()
{
	scanf("%d", &N);
	scanf("%d", &K);

	//���� ��� -1�� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			MapDir[i][j] = -1;

	// ��� ��ġ
	for (int i = 0; i < K; i++)
	{
		int r, c;
		scanf("%d %d", &r, &c);
		Map[r][c] = 1;
	}

	scanf("%d", &L);
	for (int i = 0; i < L; i++)
	{
		int sec; char rot;
		scanf("%d %c", &sec, &rot);
		Rot[i][0] = sec;
		if (rot == 'D')
			Rot[i][1] = 1;
		else
			Rot[i][1] = 0;
	}
}

void PrintMap()
{
	printf("%d\n", second - 1);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", Map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

void Process()
{
	second = 0;
	hX = 1, hY = 1;
	tX = 1, tY = 1;
	Map[tX][tY] = 2; // �������� ��
	D = 1; // ó���� ���� ���� ����

	while (1)
	{
		second++;
		GoNextPos();

		//PrintMap();

		// �� ���� �׽�Ʈ
		if (hX < 1 || hY < 1 || hX > N || hY > N)
			break;

		// �� �浹 �׽�Ʈ
		if (Map[hX][hY] == 2)
			break;

		// ��� �׽�Ʈ
		if (Map[hX][hY] != 1) // ����� �� �Ծ��� ���
		{
			// ���� 1ĭ ���� �� ��ĭ����
			Map[tX][tY] = 0;
			// ������ ���� ����
			FindNewTail();
		}

		// ���� ó��
		Map[hX][hY] = 2;

		// ȸ�� ó��
		for (int i = 0; i < L; i++)
		{
			// �ð��밡 ���� ���
			if (Rot[i][0] == second)
			{
				if (Rot[i][1] == 0) // ����
					D = (D + 3) % 4;
				else // ������
					D = (D + 1) % 4; 
			}
		}
	}

	printf("%d\n", second);
	//scanf("%d", &N);
}

int main()
{
	Input();
	Process();

	return 0;
}