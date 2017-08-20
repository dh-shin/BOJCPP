#include <iostream>
using namespace std;

#define NMAX 10000

int N;
int Data[NMAX + 1];

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int curr;
		cin >> curr;
		Data[curr]++;
	}
}

void Output()
{
	for (int i = 1; i <= NMAX; i++)
		for (int j = 0; j < Data[i]; j++)
			cout << i << "\n";
}

int main()
{
	ios::sync_with_stdio(false);

	Input();
	Output();

	return 0;
}