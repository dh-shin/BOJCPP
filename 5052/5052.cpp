#include <iostream>
using namespace std;

#define MAXDIGIT 11
#define MAXN 10000

int N;
char* phones[MAXN];
char* temp[MAXN];

class Node{
public:
	char number[MAXDIGIT];
};

void PrintPhones()
{
	for (int i = 0; i < N; i++)
		cout << phones[i] << endl;
}

int StringComp(char* a, char* b)
{
	while (*a && *b && *a == *b)
	{
		a += 1;
		b += 1;
	}
	if (*a > *b) return 1;
	else if (*a < *b) return -1;
	else return 0;
}

void Merge(int s, int e, int c)
{
	int idx1 = s, idx2 = c + 1, idxtmp = s;
	while (idx1 <= c && idx2 <= e)
	{
		if (StringComp(phones[idx1], phones[idx2]) > 0)
			temp[idxtmp++] = phones[idx2++];
		else
			temp[idxtmp++] = phones[idx1++];
	}

	if (idx1 <= c) while (idx1 <= c) temp[idxtmp++] = phones[idx1++];
	if (idx2 <= e) while (idx2 <= e) temp[idxtmp++] = phones[idx2++];
	for (int i = s; i <= e; i++) phones[i] = temp[i];
}

void PhoneSort(int s, int e)
{
	if (s >= e) return;
	int c = (s + e) / 2;

	PhoneSort(s, c);
	PhoneSort(c + 1, e);

	Merge(s, e, c);
}

void Input()
{
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		phones[i] = new char[MAXDIGIT];
		cin.getline(phones[i], MAXDIGIT);
	}
	PhoneSort(0, N - 1);

	// DEBUG
	PrintPhones();
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Input();
	}

	return 0;
}