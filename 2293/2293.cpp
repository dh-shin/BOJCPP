#include <iostream>
using namespace std;

#define MAXK 10001
int comb[MAXK];

int main()
{
	int n, k, coin;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> coin;
		for (int j = 0; j <= k; j++)
		{
			if (i == 0)
			{
				if (j % coin == 0)
				{
					comb[j] = 1;
				}
			}
			else
			{
				int prev = j - coin;
				if (prev >= 0)
					comb[j] += comb[prev];
			}
		}
	}
	cout << comb[k];
	return 0;
}