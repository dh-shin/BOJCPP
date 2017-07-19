#include <iostream>
#include <cstring>
using namespace std;

#define MAXK 501
int minv[MAXK];
int sumv[MAXK];

int main()
{
	int n, k;
	cin >> n;
	while (n--)
	{
		cin >> k;
		memset(minv, 0, sizeof(minv));
		memset(sumv, 0, sizeof(sumv));
		int curr, prev;
		cin >> curr;
		minv[1] = sumv[1] = curr;
		cin >> curr;
		minv[2] = sumv[2] = sumv[1] + curr;
 		for (int i = 3; i <= k; i++)
		{
			prev = curr;

			int a = sumv[i - 2] + (prev + curr) * 2;
			int b = sumv[i - 1] + curr;
			if ( a > b )	
				minv[i] = b;
			else
				minv[i] = a;
		}
		cout << minv[k] << endl;
	}
	cin >> n;

	return 0;
}