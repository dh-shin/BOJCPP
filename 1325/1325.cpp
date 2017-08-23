#include <iostream>
using namespace std;

#define MAXN 10001

int N, M;
int Visit[MAXN];

int Num[MAXN];
int MaxNum;
int front, rear;
int Queue[MAXN];

class DArray{
public:
	int used;
	int size;
	int* values;
	DArray(){
		used = 0;
		size = 1;
		values = new int[size];
	}
	~DArray(){
		delete[] values;
	}

	void push_back(int data){
		if (this->used == this->size) {
			int* temp = new int[this->size];
			for (int i = 0; i < this->used; i++)
				temp[i] = this->values[i];

			delete[] this->values;
			this->size *= 2;
			this->values = new int[this->size];

			for (int i = 0; i < this->used; i++)
				this->values[i] = temp[i];
			delete[] temp;	
		}
		this->values[used] = data;
		this->used++;
	}

	int get(int index)
	{
		return this->values[index];
	}

	void print_all()
	{
		for (int i = 0; i < this->used; i++)
			cout << this->values[i] << " ";
		cout << endl;
	}
};

DArray* AdjList;

void Input()
{
	cin >> N >> M;
	AdjList = new DArray[N + 1];
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		// a가 b를 신뢰한다
		// == b를 감염시키면 a도 감염된다
		// == b -> a
		AdjList[b].push_back(a);
	}
}

void Enqueue(int a)
{
	Queue[rear] = a;
	rear++;
}

void BFS(int a)
{
	front = 0;
	rear = 0;

	Enqueue(a);
	Visit[a] = 1;
	
	while (front < rear)
	{
		int start = Queue[front];
		front++;

		for (int i = 0; i < AdjList[start].used; i++)
		{
			int adj = AdjList[start].get(i);
			if (Visit[adj] == 0)
			{
				Enqueue(adj);
				Visit[adj] = 1;
			}
		}
	}
}

void ClearVisit()
{
	for (int i = 1; i <= N; i++)
		Visit[i] = 0;
}

void Process()
{
	MaxNum = -1;
	for (int i = 1; i <= N; i++)
	{
		BFS(i);
		Num[i] = rear;
		if (MaxNum < Num[i])
			MaxNum = Num[i];
		ClearVisit();
	}
}

void Output()
{
	for (int i = 1; i <= N; i++)
	{
		if (Num[i] == MaxNum)
			cout << i << " ";
	}
}

int main()
{
	Input();
	Process();
	Output();
	return 0;
}