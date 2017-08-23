#include <stdio.h>

#define MAXN 21
#define MAXK 1001

int N, M; // 지도 Row, Column
int x, y; // 주사위 좌표
int K; // 명령의 개수

int Map[MAXN][MAXN];

// (0, 0) 시작 문제

// 동, 서, 북, 남
// 1, 2, 3, 4

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int North;
int South;
int Line[4];
// 0: 서쪽
// 1: 윗면
// 2: 동쪽
// 3: 바닥

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
	if (direct == 1) // 동쪽
	{
		// Line만 오른쪽으로 Shift
		int end = Line[3];
		for (int j = 2; j >= 0; j--)
			Line[j + 1] = Line[j];
		Line[0] = end;
	}
	else if (direct == 2) // 서쪽
	{
		// Line만 왼쪽으로 Shift
		int first = Line[0];
		for (int j = 1; j <= 3; j++)
			Line[j - 1] = Line[j];
		Line[3] = first;
	}
	else if (direct == 3) // 북쪽
	{
		int temp = North;
		North = Line[1];
		Line[1] = South;
		South = Line[3];

		Line[3] = temp;
	}
	else // 남쪽
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
		// 범위 안에 있으면 위치 적용 및 true 리턴
		//printf("Position Changed!!! : (%d %d) -> (%d %d)\n", x, y, nx, ny);
		x = nx;
		y = ny;
		return true;
	}
	else
	{
		// 범위 안에 없으면 false 리턴
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
		if (ChangePosition(direct) == true) // false 이면 아무것도 안한다.
		{
			// 위치는 이미 ChangePosition에서 변경 적용 됐고,
			// 주사위 상태 변경
			RollDice(direct);

			// 숫자 복사 처리
			if (Map[x][y] == 0) // 이동한 칸에 써 있는 수가 0일 경우,
			{
				// 바닥 수가 칸에 복사된다.
				Map[x][y] = Line[3];
			}
			else // 이동한 칸에 써있는 수가 0이 아닌 경우,
			{
				// 칸 수가 바닥으로 복사되고
				Line[3] = Map[x][y];
				// 칸 수는 0이 된다.
				Map[x][y] = 0;
			}

			// 주사위 상단 숫자 출력
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