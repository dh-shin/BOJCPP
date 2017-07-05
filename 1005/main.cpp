#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 1001
#define MAXK 1000001
int cost[MAXN];
int mcost[MAXN];
int path[MAXN][MAXN];

int GetNumPath(int dest)
{
	int index = 0;
	for (int i = 0; i < MAXN; i++)
	{
		int curr = path[dest][i];
		if (curr == -1)
			break;
		index++;
	}
	return index;
}

void AddPath(int start, int dest)
{
	int index = GetNumPath(dest);
	path[dest][index] = start;
}

int GetMCost(int dest)
{
	if (mcost[dest] != -1)
		return mcost[dest];

	int cnum = GetNumPath(dest);
	if (cnum == 0)
		mcost[dest] = cost[dest];
	else
	{
		int maxcost = -1;
		for (int i = 0; i < cnum; i++)
		{
			int cid = path[dest][i];
			int currcost = GetMCost(cid);
			if (maxcost < currcost)
				maxcost = currcost;
		}
		mcost[dest] = maxcost + cost[dest];
	}
	return mcost[dest];
}

void Process()
{
	int n, k, fdest;
	cin >> n >> k;
	memset(cost, 0, sizeof(cost));
	memset(mcost, -1, sizeof(mcost));
	for (int i = 0; i < MAXN; i++)
		memset(path[i], -1, sizeof(path[i]));

	for (int i = 1; i <= n; i++)
		cin >> cost[i];

	for (int i = 0; i < k; i++)
	{
		int s, d;
		cin >> s >> d;
		AddPath(s, d);
	}

	cin >> fdest;
	cout << GetMCost(fdest) << endl;
	return;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		Process();
	return 0;
}