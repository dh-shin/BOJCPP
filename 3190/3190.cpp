#include <stdio.h>

#define MAX 101

int N, K;
int L;

int Map[MAX][MAX];
// 0: 빈칸
// 1: 사과
// 2: 몸

int MapDir[MAX][MAX];

int Rot[MAX][2];
// 0: 왼쪽
// 1: 오른쪽

// 북 동 남 서
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int D;
int hX, hY;
int tX, tY;
int second;

void GoNextPos()
{
	MapDir[hX][hY] = D; // 나아간 방향을 기록
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

	//방향 기록 -1로 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			MapDir[i][j] = -1;

	// 사과 배치
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
	Map[tX][tY] = 2; // 꼬리이자 몸
	D = 1; // 처음에 동쪽 보고 있음

	while (1)
	{
		second++;
		GoNextPos();

		//PrintMap();

		// 벽 종료 테스트
		if (hX < 1 || hY < 1 || hX > N || hY > N)
			break;

		// 몸 충돌 테스트
		if (Map[hX][hY] == 2)
			break;

		// 사과 테스트
		if (Map[hX][hY] != 1) // 사과를 못 먹었을 경우
		{
			// 꼬리 1칸 제거 후 빈칸으로
			Map[tX][tY] = 0;
			// 꼬리를 새로 지정
			FindNewTail();
		}

		// 전진 처리
		Map[hX][hY] = 2;

		// 회전 처리
		for (int i = 0; i < L; i++)
		{
			// 시간대가 맞을 경우
			if (Rot[i][0] == second)
			{
				if (Rot[i][1] == 0) // 왼쪽
					D = (D + 3) % 4;
				else // 오른쪽
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