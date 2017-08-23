#include <iostream>
using namespace std;

#define MAXN 1001

int map[MAXN][MAXN];
int visit[MAXN];
int n;

void DFS(int index)
{
	visit[index] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i != index && map[index][i] == 1 && visit[i] == 0)
		{
			DFS(i);
		}
	}
}

int GetUnVisitedNode()
{
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
			return i;
	}
	return 0;
}

void Clear()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			map[i][j] = 0;
	for (int i = 0; i < MAXN; i++)
		visit[i] = 0;

	n = 0;
}

int main()
{
	int t;

	cin >> t;
	while (t--)
	{
		Clear();

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int curr;
			cin >> curr;
			map[i][curr] = 1;
		}
		
		int cnt = 0;
		int target = GetUnVisitedNode();
		while (target != 0)
		{
			cnt++;
			DFS(target);
			target = GetUnVisitedNode();
		}
		cout << cnt << endl;
	}

	return 0;
}