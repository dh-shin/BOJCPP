#include <iostream>
using namespace std;

#define MAXN 50
#define LIMIT 100

int N;
int A[MAXN + 1];
int B[MAXN + 1];

int main()
{
	cin >> N;
	int num;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		A[num]++;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		B[num]++;
	}

	int sum = 0;
	int idxa = 0, idxb = LIMIT;
	for (int i = 1; i <= N; i++)
	{
		while (1)
		{
			if (A[idxa] != 0)
			{
				A[idxa]--;
				break;
			}
			idxa++;
		}
		while (1)
		{
			if (B[idxb] != 0)
			{
				B[idxb]--;
				break;
			}
			idxb--;
		}
		cout << idxa << " " << idxb << endl;
		sum += idxa * idxb;
	}

	cout << sum << endl;
	return 0;
}