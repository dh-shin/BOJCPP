#include <iostream>
using namespace std;

#define MAXN 10001
int maxv[MAXN];

int GetMax(int a, int b, int c)
{
	int max;
	if (a > b) 
		max = a;
	else 
		max = b;

	if (max < c)
		max = c;

	return max;
}

int main()
{
	int n;
	cin >> n;
	int curr, prev = 0;
	for (int i = 1; i <= n; i++){
		cin >> curr;
		if (i == 1)
			maxv[i] = curr;
		else if (i == 2)
			maxv[i] = curr + maxv[i - 1];
		else{
			int zero = maxv[i - 1];
			int first = curr + maxv[i - 2];
			int second = curr + prev + maxv[i - 3];
			maxv[i] = GetMax(zero, first, second);
		}
		prev = curr;
	}
	cout << maxv[n];
	return 0;
}