#include <iostream>
using namespace std;

#define MAXN 500

int map[MAXN][MAXN];
int num[MAXN][MAXN];
int N, M;

// E, W, S, N
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int getNum(int x, int y)
{
	if (num[x][y] != -1)
		return num[x][y];

	int currNum = 0;
	for (int i = 0; i < 4; i++)
	{
		int px = x + dx[i];
		int py = y + dy[i];
		if (0 <= px && px < M && 0 <= py && py < N)
			if (map[px][py] > map[x][y])
				currNum += getNum(px, py);
	}
	return num[x][y] = currNum;
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			num[i][j] = -1;
		}
	}
	num[0][0] = 1;

	cout << getNum(M - 1, N - 1) << endl;
	return 0;
}

