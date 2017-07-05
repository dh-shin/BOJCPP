#include <iostream>
#include <cstring>
using namespace std;

#define DIGIT 10
#define MOD 1000000000

int pval[DIGIT];
int cval[DIGIT];

int main()
{
	int n;
	cin >> n;
	
	cval[0] = 0;
	for (int i = 1; i < DIGIT; i++)
		cval[i] = 1;

	int sum = DIGIT - 1;
	for (int i = 2; i <= n; i++)
	{
		sum = 0;
		memcpy(pval, cval, sizeof(cval));
		for (int j = 0; j < DIGIT; j++)
		{
			if (j == 0)
				cval[0] = pval[1] % MOD;
			else if (j == 9)
				cval[9] = pval[8] % MOD;
			else
				cval[j] = (pval[j + 1] + pval[j - 1]) % MOD;
			sum += cval[j];
			sum %= MOD;
		}
	}
	cout << sum << endl;
	return 0;
}