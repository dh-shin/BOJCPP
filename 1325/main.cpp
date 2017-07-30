#include <stdio.h>

#define MAXN 10001

int N, M;
int Visit[MAXN];

int Num[MAXN];
int MaxNum;
int front, rear;
int Queue[MAXN];

class Node{
public:
	int value;
	Node* next;
	Node(int value)
	{
		this->value = value;
		next = NULL;
	}
};

Node* AdjList[MAXN];
Node* LastOne[MAXN];

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		AdjList[i] = NULL;

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		// a가 b를 신뢰한다
		// == b를 감염시키면 a도 감염된다
		// == b -> a

		if (AdjList[b] == NULL)
		{
			AdjList[b] = new Node(a);
			LastOne[b] = AdjList[b];
		}
		else{
			Node* ptr = LastOne[b];
			ptr->next = new Node(a);
			LastOne[b] = ptr->next;
		}
	}
}

/*
int DFS(int a)
{
	int count = 0;

	Visit[a] = 1;
	count++;

	for (int i = 1; i <= N; i++)
	{
		if (i != a && Mat[a][i] == 1 && Visit[i] == 0)
			count += DFS(i);
	}
	return count;
}
*/

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

		Node* ptr = AdjList[start];
		while (1)
		{
			if (ptr == NULL){
				break;
			}
			int adj = ptr->value;
			if (Visit[adj] == 0)
			{
				Enqueue(adj);
				Visit[adj] = 1;
			}
			ptr = ptr->next;
		}
	}
}

void ClearVisit()
{
	for (int i = 1; i <= N; i++)
		Visit[i] = 0;
}

void PrintAdjList(){
	for (int i = 1; i <= N; i++){
		Node* ptr = AdjList[i];
		if (ptr == NULL)
			continue;
		printf("%d : ", i);
		while (ptr != NULL)
		{
			printf("%d ", ptr->value);
			ptr = ptr->next;
		}
		printf("\n");
	}
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
			printf("%d ", i);
	}
}

int main()
{
	Input();
	//PrintAdjList();
	Process();
	Output();
	//scanf("%d", &N);
	return 0;
}