#include <iostream>
#include <cstring>
using namespace std;

#define MAXCOST 1000001
int minc[MAXCOST];

int GetMin(int* arr, int length)
{
	int minval = MAXCOST;
	for (int i = 0; i < length; i++)
	{
		if (minval > arr[i])
			minval = arr[i];
	}
	return minval;
}

int main()
{
	int n;
	cin >> n;
	minc[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int cost[3];
		memset(cost, MAXCOST, sizeof(cost));
		if (i % 2 == 0)
			cost[0] = minc[i / 2] + 1;
		if (i % 3 == 0)
			cost[1] = minc[i / 3] + 1;
		cost[2] = minc[i - 1] + 1;
		minc[i] = GetMin(cost, 3);
	}
	cout << minc[n] << endl;
	return 0;
}