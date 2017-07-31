#include <stdio.h>

#define MAXN 16

int N;
int T[MAXN];
int P[MAXN];

int MaxP[MAXN];

void Input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &T[i], &P[i]);
	MaxP[1] = 0;
}

int GetMaxP(int n)
{
	int max = -1;
	for (int i = 1; i <= n; i++)
	{
		if (max < MaxP[i])
			max = MaxP[i];
	}
	return max;
}

void Process()
{
	for (int i = 1; i <= N; i++)
	{
		int dest = i + T[i];
		if (dest <= N + 1) // 제한 시간을 넘지 않으면 계산
		{
			int destP = GetMaxP(i) + P[i];
			//printf("dest : %d, destP : %d\n", dest, destP);
			if (MaxP[dest] < destP)
				MaxP[dest] = destP;
		}
	}
}

void Output()
{
	printf("%d\n", GetMaxP(N + 1));
}

int main()
{
	Input();
	Process();
	Output();
	return 0;
}