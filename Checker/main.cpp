#include <iostream>
using namespace std;

#define MAXN 1000001

class QItem{
public:
	long long int num;
	int index;
	QItem(){
	}
};

class MinQ{
public:
	int capacity;
	int size;
	QItem** data;
	MinQ(){
		capacity = 8;
		size = 0;
		data = new QItem*[capacity];
	}
	~MinQ(){
		delete[] data;
	}
	void enqueue(QItem* item)
	{
		if (size == capacity)
		{
			QItem** temp = new QItem*[capacity];
			for (int i = 0; i < capacity; i++)
				temp[i] = data[i];
			delete[] data;
			data = new QItem*[capacity * 2];
			for (int i = 0; i < capacity; i++)
				data[i] = temp[i];
			delete[] temp;
			capacity *= 2;
		}

		data[size] = item;
		int curr_idx = size;
		int par_idx = (curr_idx + 1) / 2 - 1;
		while (curr_idx != 0 && item->num < data[par_idx]->num)
		{
			data[curr_idx] = data[par_idx];
			curr_idx = par_idx;
			par_idx = (curr_idx + 1) / 2 - 1;
		}
		data[curr_idx] = item;
		size++;
	}

	QItem* dequeue()
	{
		if (size == 0)
			return NULL;

		QItem* popItem = data[0];
		QItem* lastItem = data[size - 1];
		data[0] = lastItem;
		size--;
		int curr_idx = 0;
		int child = (curr_idx + 1) * 2 - 1;
		while (1)
		{
			if (child >= size) // 자식이 없을 경우
				break;

			if (child + 1 < size && data[child + 1]->num < data[child]->num)
				child++;

			if (data[child]->num < lastItem->num)
			{
				data[curr_idx] = data[child];
				curr_idx = child;
				child = (curr_idx + 1) * 2 - 1;
			}
			else // 자식보다 우선순위가 높을 경우
				break;
		}
		data[curr_idx] = lastItem;
		return popItem;
	}
};

class MaxQ{
public:
	int capacity;
	int size;
	QItem** data;
	MaxQ(){
		capacity = 8;
		size = 0;
		data = new QItem*[capacity];
	}
	~MaxQ(){
		delete[] data;
	}
	void enqueue(QItem* item)
	{
		if (size == capacity)
		{
			QItem** temp = new QItem*[capacity];
			for (int i = 0; i < capacity; i++)
				temp[i] = data[i];
			delete[] data;
			data = new QItem*[capacity * 2];
			for (int i = 0; i < capacity; i++)
				data[i] = temp[i];
			delete[] temp;
			capacity *= 2;
		}

		data[size] = item;
		int curr_idx = size;
		int par_idx = (curr_idx + 1) / 2 - 1;
		while (curr_idx != 0 && item->num > data[par_idx]->num)
		{
			data[curr_idx] = data[par_idx];
			curr_idx = par_idx;
			par_idx = (curr_idx + 1) / 2 - 1;
		}
		data[curr_idx] = item;
		size++;
	}

	QItem* dequeue()
	{
		if (size == 0)
			return NULL;

		QItem* popItem = data[0];
		QItem* lastItem = data[size - 1];
		data[0] = lastItem;
		size--;
		int curr_idx = 0;
		int child = (curr_idx + 1) * 2 - 1;
		while (1)
		{
			if (child >= size) // 자식이 없을 경우
				break;

			if (child + 1 < size && data[child + 1]->num > data[child]->num)
				child++;

			if (data[child]->num > lastItem->num)
			{
				data[curr_idx] = data[child];
				curr_idx = child;
				child = (curr_idx + 1) * 2 - 1;
			}
			else // 자식보다 우선순위가 높을 경우
				break;
		}
		data[curr_idx] = lastItem;
		return popItem;
	}
};

MaxQ* maxQ;
MinQ* minQ;
int visit[MAXN];
QItem* trash[MAXN];

void Process()
{
	maxQ = new MaxQ();
	minQ = new MinQ();

	int n;
	cin >> n;
	int index = 0;
	while (n--)
	{
		char c;
		cin >> c;
		long long int num;
		cin >> num;
		if (c == 'I')
		{
			index++;
			QItem* currItem = new QItem();
			currItem->num = num;
			currItem->index = index;
			visit[index] = 0;
			trash[index] = currItem;

			maxQ->enqueue(currItem);
			minQ->enqueue(currItem);
		}
		else // c == 'D' 
		{
			if (num == -1)
			{
				QItem* popItem = minQ->dequeue();
				while (popItem != NULL && visit[popItem->index] == 1)
					popItem = minQ->dequeue();
				if (popItem != NULL)
					visit[popItem->index] = 1;
			}
			else // num == 1
			{ 
				QItem* popItem = maxQ->dequeue();
				while (popItem != NULL && visit[popItem->index] == 1)
					popItem = maxQ->dequeue();
				if (popItem != NULL)
					visit[popItem->index] = 1;
			}
		}
	}

	QItem* minPop = minQ->dequeue();
	while (minPop != NULL && visit[minPop->index] == 1)
		minPop = minQ->dequeue();

	QItem* maxPop = maxQ->dequeue();
	while (maxPop != NULL && visit[maxPop->index] == 1)
		maxPop = maxQ->dequeue();

	int max, min;
	if (minPop == NULL && maxPop == NULL)
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		min = minPop->num;
		max = maxPop->num;
		cout << max << " " << min << endl;
	}

	delete minQ;
	delete maxQ;
	for (int i = 1; i <= index; i++)
		delete trash[i];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Process();
	}

	return 0;
}