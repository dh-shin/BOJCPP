#include <iostream>
using namespace std;

#define MAXN 40
#define MAXS 13
#define IMP 0x7fffffff

class Location{
public:
	int r;
	int c;
};

class Queue{
public:
	int r;
	int c;
	int step;
};

int N, C;
int map[MAXN + 1][MAXN + 1];
int node_num;
Location nodes[MAXS + 2];
int cost[MAXS + 2][MAXS + 2];
int visit[MAXS + 2][MAXS + 2];

Queue queue[MAXN * MAXN];
int front, rear;

void BFS(int loc)
{
	for (int i = 0; i < MAXS + 2; i++)
		for (int j = 0; j < MAXS + 2; j++)
			visit[i][j] = 0;

	front = 0;
	rear = 0;

	int dr[] = { 0, 0, 1, -1 };
	int dc[] = { 1, -1, 0, 0 };

	Queue data;
	Queue ndata;

	data.r = nodes[loc].r;
	data.c = nodes[loc].c;
	data.step = 0;

	queue[front++] = data;
	visit[nodes[loc].r][nodes[loc].c] = 1;

	while (front < rear)
	{
		data = queue[rear++];

		for (int i = 0; i < 4; i++)
		{
			ndata.r = data.r + dr[i];
			ndata.c = data.c + dc[i];
			ndata.step = data.step + 1;

			if (map[ndata.r][ndata.c] != 1 && visit[ndata.r][ndata.c] == 0)
			{
				queue[front++] = ndata;
				visit[ndata.r][ndata.c] = ndata.step;
			}
		}
	}

	for (int i = 0; i < node_num; i++)
	{
		if (visit[nodes[loc].r][nodes[loc].c] == 0 || i == loc)
			cost[loc][i] = cost[i][loc] = IMP;
		else
			cost[loc][i] = cost[i][loc] = visit[nodes[loc].r][nodes[loc].c];
	}
}

void Make_Cost()
{
	for (int i = 0; i < node_num; i++)
		BFS(i);
}

int Bit_Count(int bits)
{
	int cnt = 0;
	while (bits > 0)
	{
		if ((bits & 1) == 1) cnt++;
		bits >>= 1;
	}
	return cnt;
}

#define Bit_Check (bits, n) ((bits) & (1 << (n)))
#define Bit_Clear (bits, n) ((bits) & ~(1 << (n)))

void Input()
{
	cin >> N >> C;
	int nidx = 1;
	Location dst;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			Location node;
			node.r = i;
			node.c = j;

			if (map[i][j] == 2) nodes[0] = node; // 나자연씨 집
			else if (map[i][j] == 3) nodes[nidx++] = node; // 학생 집
			else if (map[i][j] == 4) dst = node; // 어린이 집
		}
	}
	nodes[nidx++] = dst;
	node_num = nidx;

	Make_Cost();
}

int main()
{
	Input();

	return 0;
}