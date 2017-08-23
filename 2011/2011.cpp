#include <stdio.h>

#define MAXN 5001

int N;
int Enc[MAXN];
char Str[MAXN];

void Input()
{
	scanf("%s", Str);
	int i;
	for (i = 0; i < MAXN; i++)
	{
		if (Str[i] == '\0')
			break;
	}
	N = i;
}

void Process()
{
	Enc[0] = 1;
	Enc[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (Str[i - 2] > '2')
			Enc[i] = Enc[i - 1];
		else if (Str[i - 2] == '2' && Str[i - 1] > '6')
			Enc[i] = Enc[i - 1];
		else if (Str[i - 2] == '0')
			Enc[i] = Enc[i - 1];
		else if (Str[i - 1] == '0')
			Enc[i] = Enc[i - 2];
		else
		{
			Enc[i] = Enc[i - 2] + Enc[i - 1];
			Enc[i] %= 1000000;
		}
		//printf("Enc[%d] : %d\n", i, Enc[i]);
	}
}

int main()
{
	Input();
	Process();
	if (Str[0] == '0')
		printf("0\n");
	else
		printf("%d\n", Enc[N]);
	return 0;
}