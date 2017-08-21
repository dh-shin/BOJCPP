#include <iostream>
using namespace std;

#define MAXN 19
#define IMP 0x7fffffff

int N;
int cost[MAXN][MAXN];
int D[1 << MAXN][MAXN];
int Result;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cost[i][j];
			if (cost[i][j] == 0) cost[i][j] = IMP;
		}
	}
}

void Init_Dynamic()
{
	for (int i = 1; i < N; i++)
		D[1 | (1 << i)][i] = cost[0][i];
}

#define Bit_Check(bits, i) ((bits) & (1<<(i)))
#define Bit_Clear(bits, i) ((bits) & ~(1<<(i)))

int Do_Dynamic()
{
	int allvisit = (1 << N) - 1;
	int prevbits, mincost;
	for (int bits = 3; bits <= allvisit; bits += 2)
	{
		for (int last = 1; last < N; last++)
		{
			if (Bit_Check(bits, last) == 0) continue; // last�� �湮�� ���� ���� ���
			if (D[bits][last] != 0) continue; // �̹� Init_Dynamic���� ����� ���

			D[bits][last] = IMP;
			prevbits = Bit_Clear(bits, last);

			for (int prevlast = 1; prevlast < N; prevlast++)
			{
				if (Bit_Check(prevbits, prevlast) == 0) continue; // ���°� �������� �ʴ� ���
				if (D[prevbits][prevlast] == IMP) continue; // ���� ���°� �Ǳ� �Ұ����� ���
				if (cost[prevlast][last] == IMP) continue; // ���� ���¿��� ���� ���·� �Ǳ� �Ұ����� ���

				if (D[bits][last] > D[prevbits][prevlast] + cost[prevlast][last])
				{
					D[bits][last] = D[prevbits][prevlast] + cost[prevlast][last];
				}
			}
		}
	}

	mincost = IMP;
	for (int last = 1; last < N; last++)
	{
		if (cost[last][0] == IMP) continue;
		if (D[allvisit][last] == IMP) continue;
		if (D[allvisit][last] + cost[last][0] < mincost)
			mincost = D[allvisit][last] + cost[last][0];
	}

	return mincost;
}

void Process()
{
	Init_Dynamic();
	Result = Do_Dynamic();
}

void Output()
{
	cout << Result << endl;
}

int main()
{
	Input();
	Process();
	Output();

	return 0;
}