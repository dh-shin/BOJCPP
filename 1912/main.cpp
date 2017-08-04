#include <stdio.h>

#define MAXN 100001

int N;
long long int Sum;
long long int Max;
int MaxNeg;

int main()
{
	scanf("%d", &N);

	Sum = 0;
	Max = -1001;
	MaxNeg = -1001;
	int negflag = 1;
	for (int i = 1; i <= N; i++)
	{
		int curr;
		scanf("%d", &curr);
		
		// 음수만으로 이루어진 수열 일 경우 처리
		if (curr > 0)
			negflag = 0;
		if (curr > MaxNeg)
			MaxNeg = curr;

		if (i == 1)
		{
			Sum = curr;
			Max = Sum;
		}
		else
		{
			Sum += curr;
			if (Sum < 0)
				Sum = 0;

			if (Sum > Max)
				Max = Sum;
		}		
	}
	
	if (negflag == 1)
		printf("%d\n", MaxNeg);
	else
		printf("%lld\n", Max);

	return 0;
}