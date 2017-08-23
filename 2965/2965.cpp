#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int d1 = b - a, d2 = c -b;
	if (d1 > d2) cout << d1 - 1;
	else cout << d2 - 1;
	return 0;
}