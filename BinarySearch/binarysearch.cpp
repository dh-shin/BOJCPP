/*
<���� ī����>
�迭�� ������������ N���� ���ڰ� ����Ǿ� �ִ�.
M���� Ž���� ���ڰ� �־��� ��, �� ���ڰ� �迭�� �� ���� ����Ǿ� �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

INPUT:
10
1 1 1 6 9 11 13 17 19 20
2
1 9

OUTPUT:
3 1
*/

#include <iostream>
using namespace std;

#define MAXN 200000

int N, M;
int Num[MAXN + 1];
int Search[MAXN + 1];
int Result[MAXN + 1];

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Num[i];
	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> Search[i];
}

int Binary_Search_Upper(int s, int e, int num)
{
	int c, sol = -1;
	
	while (s <= e)
	{
		c = (s + e) / 2;
		if (Num[c] == num)
		{
			sol = c;
			s = c + 1;
		}
		else if (Num[c] < num) s = c + 1;
		else e = c - 1;
	}
	return sol;
}

int Binary_Search_Lower(int s, int e, int num)
{
	int c, sol = -1;
	
	while (s <= e)
	{
		c = (s + e) / 2;
		if (Num[c] == num)
		{
			sol = c;
			e = c - 1;
		}
		else if (Num[c] < num) s = c + 1;
		else e = c - 1;
	}
	return sol;
}

void Process()
{
	int upper, lower;
	for (int i = 1; i <= M; i++)
	{
		upper = Binary_Search_Upper(1, N, Search[i]);
		if (upper != -1)
		{
			lower = Binary_Search_Lower(1, N, Search[i]);
			Result[i] = upper - lower + 1;
		}
		else Result[i] = 0;
	}
}

void Output()
{
	for (int i = 1; i <= M; i++)
		cout << Result[i] << " ";
	cout << endl;
}

int main(void)
{
	Input();
	Process();
	Output();

	return 0;
}