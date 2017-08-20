#include <iostream>
using namespace std;

#define MAXSITE 29

int N, M;
long long int D[MAXSITE + 1][MAXSITE + 1];

long long int GetD(int n, int m)
{
	if (D[n][m] == 0)
	{
		long long int sum = 0;
		int new_n = n - 1;
		int new_m = m - 1;
		while (new_n <= new_m)
		{
			sum += GetD(new_n, new_m);
			new_m--;
		}
		D[n][m] = sum;
	}
	return D[n][m];
}

void Dynamic()
{
	for (int i = 1; i <= MAXSITE; i++)
	{
		D[i][i] = 1;
		D[1][i] = i;
	}
}

void Input()
{
	cin >> N >> M;
}

void Output()
{
	cout << GetD(N, M) << "\n";
}

int main()
{
	Dynamic();
	
	int t;
	cin >> t;
	while (t--)
	{
		Input();
		Output();
	}

	return 0;
}