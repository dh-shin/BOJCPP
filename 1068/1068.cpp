#include <iostream>
using namespace std;

#define MAXN 51

class MyVec{
public:
	int capacity;
	int size;
	int* data;
	MyVec(){
		capacity = 2;
		size = 0;
		data = new int[capacity];
	}
	~MyVec(){
		delete[] data;
	}
	void push_back(int item){
		if (size == capacity)
		{
			int* temp = new int[capacity];
			for (int i = 0; i < capacity; i++)
				temp[i] = data[i];
			delete[] data;
			data = new int[capacity * 2];
			for (int i = 0; i < capacity; i++)
				data[i] = temp[i];
			delete[] temp;
			capacity *= 2;
		}
		data[size] = item;
		size++;
	}

	int get(int index){
		return data[index];
	}
};

int n;
int root;
int target;
int leafnum;
MyVec* AdjList[MAXN];

void Input()
{
	cin >> n;
	for (int i = 0; i < MAXN; i++)
		AdjList[i] = new MyVec();

	leafnum = 0;
	for (int i = 0; i < n; i++)
	{
		int par;
		cin >> par;
		if (par == -1)
		{
			root = i;
			continue;
		}
		else
		{
			AdjList[par]->push_back(i);
		}
	}
	
	cin >> target;
}

void DFS(int index)
{
	if (AdjList[index]->size == 0)
	{
		leafnum++;
		return;
	}

	for (int i = 0; i < AdjList[index]->size; i++)
	{
		int curr = AdjList[index]->get(i);
		if (curr == target)
		{
			if (AdjList[index]->size == 1)
			{
				leafnum++;
				return;
			}
		}
		else{
			DFS(AdjList[index]->get(i));
		}
	}
}

void Process()
{
	if (target != root)
		DFS(root);

	for (int i = 0; i < MAXN; i++)
		delete AdjList[i];
}

void Output()
{
	cout << leafnum << endl;
}

int main()
{
	Input();
	Process();
	Output();

	return 0;
}