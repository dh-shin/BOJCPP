#include <stdio.h>

int main()
{
	int total;
	scanf("%d", &total);
	int sum = 0;
	int won;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &won);
		sum += won;
	}
	printf("%d\n", total - sum);
	return 0;
}