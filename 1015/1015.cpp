#include <iostream>
using namespace std;

#define MAXN 50
#define MAXE 1000

int N;
int A[MAXN + 1];
int* pA[MAXN + 1];

class Vec{
public:
	int capacity = MAXN + 1;
	int size;
	int** data;
	Vec(){
		size = 0;
		data = new int*[capacity];
	}
	~Vec(){
		delete[] data;
	}
	void push_back(int* adr)
	{
		data[size++] = adr;
	}
};

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		pA[i] = new int();
	}
}

void Process()
{
	Vec vec[MAXE + 1];
	for (int i = 1; i <= N; i++)
		vec[A[i]].push_back(pA[i]);

	int pval = 0;
	for (int i = 1; i <= MAXE; i++)
		for (int j = 0; j < vec[i].size; j++)
			*(vec[i].data[j]) = pval++;
}

void Output()
{
	for (int i = 1; i <= N; i++)
		cout << *pA[i] << " ";
	cout << endl;
}

int main()
{
	Input();
	Process();
	Output();
	return 0;
}