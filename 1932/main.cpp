#include <iostream>
using namespace std;

#define MAXN 500
int maxval[MAXN][MAXN];

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int curr;
		for (int j = 0; j < i + 1; j++)
		{
			cin >> curr;
			if (i == 0) 
			{
				maxval[i][j] = curr;
				break;
			}	

			int first, second;
			if (j - 1 >= 0)
				first = maxval[i - 1][j - 1];
			else
				first = -1;

			if (j != i)
				second = maxval[i - 1][j];
			else
				second = -1;

			maxval[i][j] = max(first, second) + curr;
		}
	}

	int maxlength = -1;
	for (int i = 0; i < n; i++)
	{
		if (maxlength < maxval[n - 1][i])
			maxlength = maxval[n - 1][i];
	}

	cout << maxlength;

	return 0;
}
