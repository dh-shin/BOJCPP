#include <iostream>
using namespace std;

#define MAXN 101

long long int P[MAXN];

void Process()
{
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	for (int i = 6; i <= 100; i++)
	{
		P[i] = P[i - 1] + P[i - 5];
		//cout << P[i] << endl;
	}
}

int main()
{
	Process();

	int t;
	cin >> t;
	while (t--)
	{
		int curr;
		cin >> curr;
		cout << P[curr] << endl;
	}
	return 0;
}