#include <iostream>
using namespace std;

#define MAXN 10001

class MyVec
{
public:
	int size;
	int used;
	int* node;
	int* time;
	MyVec()
	{
		size = 2;
		used = 0;
		node = new int[size];
		time = new int[size];
	}
	~MyVec()
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

class PQData
{
public:
	int node;
	int time;
	PQData(){
	}
	PQData(int n, int t)
	{
		node = n;
		time = t;
	}
};

class PQueue{
public:
	int size;
	int used;
	PQData* data;
	PQueue()
	{
		size = 8;
		used = 0;
		data = new PQData[size + 1];
	}
	~PQueue()
	{
		delete[] data;
	}

	void enqueue(int n, int t)
	{
		used++;
		if (used == size + 1)
		{
			PQData* temp = new PQData[size + 1];
			for (int i = 1; i <= size; i++)
				temp[i] = data[i];
			delete[] data;
			size *= 2;
			data = new PQData[size];
			for (int i = 1; i <= used; i++)
				data[i] = temp[i];
			delete[] temp;
		}

		data[used].node = n;
		data[used].time = t;
		int curr = used;
		int par = curr / 2;
		PQData currdat = data[curr];
		while (curr != 1 && data[par].time > currdat.time){
			data[curr] = data[par];
			curr /= 2;
			par = curr / 2;
		}
		data[curr] = currdat;
	}

	PQData dequeue()
	{
		int curr = 1;
		PQData pop = data[curr];

		data[curr] = data[used];
		used--;
		PQData top = data[curr];
		while (1)
		{
			int child = curr * 2;
			if (this->used < child)
				break;
			if (this->used >= child + 1 && data[child + 1].time < data[child].time)
				child += 1;

			// value comparison
			if (data[child].time < top.time)
			{
				data[curr] = data[child];
				curr = child;
			}
			else{
				break;
			}
		}
		data[curr] = top;
		return pop;
	}
	
	void print_all()
	{
		for (int i = 1; i <= used; i++)
			cout << "(" << this->data[i].node << ", " << this->data[i].time << ") ";
		cout << endl;
	}
};

int N, D, C;
int Visit[MAXN];
int CNum; // °¨¿°µÈ ÄÄÇ»ÅÍ ¼ö
int CSec; // °¨¿°±îÁöÀÇ ÃÑ ½Ã°£
MyVec* AdjList;
PQueue* MinPQ;

void Input()
{
	CNum = 0;
	CSec = 0;
	cin >> N >> D >> C;
	AdjList = new MyVec[N + 1];
	MinPQ = new PQueue();
	for (int i = 0; i < D; i++)
	{
		int a, b, s;
		// b -> a
		cin >> a >> b >> s;
		AdjList[b].push_back(a, s);
	}

	for (int i = 1; i <= N; i++)
		Visit[i] = 0;
}

void BFS(int n, int t)
{
	MinPQ->enqueue(n, t);
	while (MinPQ->used > 0)
	{
		PQData dat = MinPQ->dequeue();
		int node = dat.node;
		int time = dat.time;
		if (Visit[node] == 1)
			continue;

		if (CSec < time)
			CSec = time;
		CNum++;
		Visit[node] = 1;
		for (int i = 0; i < AdjList[node].used; i++)
		{
			int nextnode = AdjList[node].node[i];
			int nexttime = AdjList[node].time[i];
			if (Visit[nextnode] != 1)
				MinPQ->enqueue(nextnode, nexttime + time);
		}
	}
}

void Process()
{
	BFS(C, 0);
	delete MinPQ;
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