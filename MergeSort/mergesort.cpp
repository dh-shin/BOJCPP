#include <iostream>
using namespace std;

#define MAXN 30000

int N;
int data[MAXN + 1];
int temp[MAXN + 1];

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> data[i];
}

void Merge(int s, int c, int e)
{
	int idx1 = s, idx2 = c + 1, idxtmp = s;
	while (idx1 <= c && idx2 <= e)
	{
		if (data[idx1] < data[idx2])
			temp[idxtmp++] = data[idx1++];
		else
			temp[idxtmp++] = data[idx2++];
	}

	if (idx1 > c) while (idx2 <= e) temp[idxtmp++] = data[idx2++];
	else while (idx1 <= c) temp[idxtmp++] = data[idx1++];
	for (int i = s; i <= e; i++) data[i] = temp[i];
}

void MergeSort(int s, int e)
{
	if (s >= e)
		return;

	int c = (s + e) / 2;

	MergeSort(s, c);
	MergeSort(c + 1, e);

	Merge(s, c, e);
}

void Process()
{
	MergeSort(1, N);
}

void Output()
{
	for (int i = 1; i <= N; i++)
		cout << data[i] << " ";
	cout << endl;
}

int main(void)
{
	Input();
	Process();
	Output();
	return 0;
}
