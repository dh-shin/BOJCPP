#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int mr = 0, mg = 0, mb = 0;
	for (int i = 0; i < n; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		int newr = min(r + mg, r + mb);
		int newg = min(g + mr, g + mb);
		int newb = min(b + mr, b + mg);
		mr = newr;
		mg = newg;
		mb = newb;
	}
	cout << min(mr, min(mg, mb));
	cin >> n;
	return 0;
}