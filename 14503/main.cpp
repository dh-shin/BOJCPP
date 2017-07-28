#include <stdio.h>

#define MAX 51

// 북 동 남 서
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int N, M;
int R, C, D;
int Map[MAX][MAX];
int CCount = 0;
// 0: 청소 안함
// 1: 벽
// 2: 청소 함


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
	Map[R][C] = 2; // 현재 위치 청소
	CCount++;
	while (1)
	{
		// 더 이상 할 일이 없으면
		if (IsNoMoreTask() == true)
		{
			int back = GetBackValue();
			if (back == 1)
			{
				// 뒷쪽 방향이 벽일 경우 정지
				break;
			}
			else
			{
				// 뒷쪽 방향이 (청소된) 빈 칸일 경우, 뒤로 이동
				int d = (D + 2) % 4;
				R = R + dr[d];
				C = C + dc[d];
			}
		}
		else
		{
			// 할 일이 남은 경우
			int left = GetLeftValue();
			D = (D + 3) % 4;	// 회전
			if (left == 0) // 왼쪽 청소 가능
			{
				R = R + dr[D];		// 보는 방향으로 전진
				C = C + dc[D];		// 보는 방향으로 전진
				Map[R][C] = 2; // 현재 위치 청소
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