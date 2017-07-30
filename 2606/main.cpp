#include <stdio.h>

#define MAXN 101

int N, K;
int Map[MAXN][MAXN];
int Visit[MAXN];
// 0: �湮 ����
// 1: �湮 ��

void Input()
{
	scanf("%d", &N);
	scanf("%d", &K);
	while (K--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		Map[a][b] = 1;
		Map[b][a] = 1;
	}
}

void DFS(int a)
{
	Visit[a] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (a == i)
			continue;

		// a �� i �� ����Ǿ� �ְ�, i�� �湮�� ���� ������
		if (Map[a][i] == 1 && Visit[i] == 0)
			DFS(i);
	}
}

void Output()
{
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (Visit[i] == 1)
			count++;
	}
	count--;
	printf("%d\n", count);
}

int main()
{
	Input();
	DFS(1);
	Output();
	return 0;
}