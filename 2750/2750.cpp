#include <iostream>
using namespace std;

#define NMAX 1000

int N;
int Data[NMAX + 1];
int MData[NMAX + 1];

void Input()
{
	cin >> N;
	int curr;
	for (int i = 1; i <= N; i++)
	{
		cin >> curr;
		if (curr < 0) MData[-1 * curr]++;
		else Data[curr]++;
	}
}

void Output()
{
	int i;
	for (i = NMAX; i >= 1; i--)
		if (MData[i] > 0) cout << (-1 * i) << "\n";
	for (i = 0; i <= NMAX; i++)
		if (Data[i] > 0) cout << i << "\n";

}

int main()
{
	ios::sync_with_stdio(false);

	Input();
	Output();

	return 0;
}