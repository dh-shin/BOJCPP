#include <iostream>
using namespace std;

#define MAXK 501

int k;
int num[MAXK];
int C[MAXK][MAXK];
int cost;

void Input()
{
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> num[i];
		for (int j = 1; j <= k; j++)
			C[i][j] = 0;
	}
}

int GetC(int a, int b)
{
	if (a != b && C[a][b] == 0)
	{
		int sum = 0;
		for (int i = a; i <= b; i++)
			sum += num[i];
		int min = 987654321;
		for (int i = a; i < b; i++)
		{
			int val = GetC(a, i) + GetC(i + 1, b);
			if (val < min)
				min = val;
		}
		sum += min;
		C[a][b] = sum;
	}
	return C[a][b];
}

void Process()
{
	cost = GetC(1, k);
}

void Output()
{
	cout << cost << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		Input();
		Process();
		Output();
	}

	return 0;
}