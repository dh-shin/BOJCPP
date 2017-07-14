#include <iostream>
#include <climits>
using namespace std;

#define MAXN 101
long long side[7];
long long seq[MAXN];

int GetMinusIndex(int i)
{
	if (i == 1)
		return 6;
	else
		return i - 1;
}

int GetPlusIndex(int i)
{
	if (i == 6)
		return 1;
	else
		return i + 1;
}

int FindMaxIndex(long long* arr)
{
	int i;
	int maxidx = -1;
	long long max = LLONG_MIN;
	for (i = 1; i <= 6; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
			maxidx = i;
		}
	}		

	int count = 0;
	for (int i = 1; i <= 6; i++)
	{
		if (arr[i] == max)
			count++;
	}
	
	if (count == 1)
	{
		return maxidx;
	}
	else
	{
		long long maxs[7];
		for (i = 1; i <= 6; i++)
		{
			if (arr[i] == max)
			{
				long long a, b;
				a = arr[GetMinusIndex(i)];
				b = arr[GetPlusIndex(i)];
				if (a > b)
					maxs[i] = a;
				else
					maxs[i] = b;
			}
			else
			{
				maxs[i] = 0;
			}
		}

		max = LLONG_MIN;
		for (int i = 1; i <= 6; i++)
		{
			if (maxs[i] > max)
			{
				max = maxs[i];
				maxidx = i;
			}
		}
	}

	return maxidx;
}

int main()
{
	side[1] = 1;
	side[3] = 1;
	side[5] = 1;
	seq[1] = 1;

	long long longest = 1;
	int maxidx = 1;
	for (int i = 2; i < MAXN; i++)
	{
		seq[i] = longest;
		side[maxidx] = 0;
		side[GetPlusIndex(maxidx)] += longest;
		side[GetMinusIndex(maxidx)] += longest;
		maxidx = FindMaxIndex(side);
		longest = side[maxidx];
	}

	int n, idx;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> idx;
		cout << seq[idx] << endl;
	}
	return 0;
}