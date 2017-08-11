#include <iostream>
using namespace std;

#define MAXN 10001

class DArray
{
public:
	int size;
	int used;
	int* node;
	int* time;
	DArray()
	{
		size = 2;
		used = 0;
		node = new int[size];
		time = new int[size];
	}
	~DArray()
	{
		delete[] node;
		delete[] time;
	}
	void push_back(int n, int t)
	{
		if (size == used)
		{
			node = extend(node);
			time = extend(time);
			size *= 2;
		}
		node[used] = n;
		time[used] = t;
		used++;
	}

	int get_node(int index)
	{
		return node[index];
	}

	int get_time(int index)
	{
		return time[index];
	}

	void print_all()
	{
		for (int i = 0; i < size; i++)
			cout << node[i] << " ";
		cout << endl;
		for (int i = 0; i < size; i++)
			cout << time[i] << " ";
		cout << endl;
	}

private:
	int* extend(int* arr)
	{
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];
		delete[] arr;
		arr = new int[size * 2];
		for (int i = 0; i < size; i++)
			arr[i] = temp[i];
		delete[] temp;
		return arr;
	}

};

class Queue{
public:
	int size;
	Node* first;
	Node* last;
	Queue()
	{
		size = 0;
		first = NULL;
		last = NULL;
	}
	void add(int data)
	{
		Node* node = new Node(data);
		if (size == 0)
		{
			first = node;
			last = node;
		}
		else{
			last->next = node;
			last = last->next;
		}
		size++;
	}
	Node* dequeue()
	{
		Node* temp = first;
		if (size == 0)
		{
			return NULL;
		}
		else if (size == 1)
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			first = first->next;
		}
		size--;
		return temp;
	}
};

class Node{
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

int N, D, C;
int Visit[MAXN];
int CNum; // 감염된 컴퓨터 수
int CSec; // 감염까지의 총 시간
DArray* AdjList;
Queue* BFSQueue;

void Input()
{
	CNum = 1; // 자기 자신
	CSec = 0;
	cin >> N >> D >> C;
	AdjList = new DArray[N + 1];
	BFSQueue = new Queue();
	for (int i = 0; i < D; i++)
	{
		int a, b, s;
		// b -> a
		cin >> a >> b >> s;
		AdjList[b].push_back(a, s);
	}
	for (int i = 1; i <= N; i++)
	{
		Visit[i] = 0;
		//AdjList[i].print_all();
	}
}

void BFS(int n, int t)
{
	Visit[n] = 1;
}

void Process()
{
	BFS(C, 0);
	delete BFSQueue;
	delete[] AdjList;
}

void Output()
{
	cout << CNum << " " << CSec << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Input();
		Process();
		Output();
	}

	return 0;
}