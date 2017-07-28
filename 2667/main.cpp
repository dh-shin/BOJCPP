#include <iostream>
using namespace std;

#define MAXN 27

int map[MAXN][MAXN];
int n;

int num;
int cnt;
int nums[MAXN*MAXN];

int xd[] = { 1, -1, 0, 0 };
int yd[] = { 0, 0, 1, -1 };

class XY{
public:
	int x, y;
	XY(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

void DFS(XY* point)
{
	int x = point->x;
	int y = point->y;
	map[x][y] = 0; // visited
	num++;
	
	for (int i = 0; i < 4; i++)
	{
		int newx = x + xd[i];
		int newy = y + yd[i];
		if (map[newx][newy] == 1)
			DFS(new XY(newx, newy));
	}

}

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			char digit;
			cin >> digit;
			map[i][j] = digit - '0';
		}
}

XY* GetUnVisited()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (map[i][j] == 1)
				break;
		}
		if (j != n + 1)
			break;
	}

	if (i != n + 1)
	{
		XY* xy = new XY(i, j);
		return xy;
	}
	else
		return NULL;
}

void Process()
{
	XY* point;
	cnt = 0;
	while ((point = GetUnVisited()) != NULL)
	{
		num = 0;
		DFS(point);
		nums[cnt++] = num;
	}

	// Sort
	for (int i = 0; i < cnt; i++)
	{
		int max = -1;
		int maxidx = -1;
		for (int j = 0; j < cnt - i; j++)
		{
			if (nums[j] > max)
			{
				max = nums[j];
				maxidx = j;
			}
		}
		int temp = nums[maxidx];
		nums[maxidx] = nums[cnt - i - 1];
		nums[cnt - i - 1] = temp;
	}
}

void Output()
{
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << nums[i] << endl;
}

int main()
{	
	Input();
	Process();
	Output();
	return 0;
}