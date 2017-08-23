#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int fiv = n / 5;
	int fiv_res = n % 5;
	int result = 0;

	if (n == 4 || n == 7) result = -1;
	else if (fiv_res == 0) result = fiv;
	else if (fiv_res == 1) result = --fiv + 2;
	else if (fiv_res == 2)
	{
		fiv -= 2;
		result = fiv + 4;
	}
	else if (fiv_res == 3) result = fiv + 1;
	else if (fiv_res == 4)
	{
		fiv -= 1;
		result = fiv + 3;
	}
	cout << result << endl;

	return 0;
}