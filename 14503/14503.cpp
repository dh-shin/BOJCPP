#include <stdio.h>

#define MAX 51

// �� �� �� ��
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int N, M;
int R, C, D;
int Map[MAX][MAX];
int CCount = 0;
// 0: û�� ����
// 1: ��
// 2: û�� ��


void Input()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &R, &C, &D);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &Map[i][j]);
}

int GetLeftValue()
{
	int d = (D + 3) % 4;
	return Map[R + dr[d]][C + dc[d]];
}

int GetBackValue()
{
	int d = (D + 2) % 4;
	return Map[R + dr[d]][C + dc[d]];
}

bool IsNoMoreTask()
{
	for (int i = 0; i < 4; i++)
	{
		int newr = R + dr[i];
		int newc = C + dc[i];
		if (Map[newr][newc] == 0)
			return false;
	}
	return true;
}

void Process()
{
	Map[R][C] = 2; // ���� ��ġ û��
	CCount++;
	while (1)
	{
		// �� �̻� �� ���� ������
		if (IsNoMoreTask() == true)
		{
			int back = GetBackValue();
			if (back == 1)
			{
				// ���� ������ ���� ��� ����
				break;
			}
			else
			{
				// ���� ������ (û�ҵ�) �� ĭ�� ���, �ڷ� �̵�
				int d = (D + 2) % 4;
				R = R + dr[d];
				C = C + dc[d];
			}
		}
		else
		{
			// �� ���� ���� ���
			int left = GetLeftValue();
			D = (D + 3) % 4;	// ȸ��
			if (left == 0) // ���� û�� ����
			{
				R = R + dr[D];		// ���� �������� ����
				C = C + dc[D];		// ���� �������� ����
				Map[R][C] = 2; // ���� ��ġ û��
				CCount++;
			}
		}
	}
}

void Output()
{
	printf("%d\n", CCount);
}

int main()
{
	Input();
	Process();
	Output();
	return 0;
}