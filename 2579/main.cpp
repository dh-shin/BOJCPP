#include <iostream>
using namespace std;

#define MAXS 2
#define MAXN 301

int cscore[MAXN][MAXS];

int maxscore(int* arr)
{
	int max = 0;
	for (int i = 0; i < MAXS; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int main()
{
	int n;
	cin >> n;
	cscore[0][0] = 0;
	cscore[0][1] = 0;

	int curr;
	for (int i = 1; i <= n; i++)
	{
		cin >> curr;
		if (i == 1)
			cscore[i][0] = curr;
		else
			cscore[i][0] = maxscore(cscore[i - 2]) + curr;
		cscore[i][1] = cscore[i - 1][0] + curr;
	}
	
	cout << maxscore(cscore[n]);

	return 0;
}