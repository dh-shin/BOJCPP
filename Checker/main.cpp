#include <iostream>
using namespace std;

class Item{
public:
	int a;
	int b;
};

class MinQ{
public:
	int capacity;
	int lastnode;
	Item* data;
	MinQ(){
		capacity = 8;
		lastnode = 0;
		data = new Item[capacity+1];
	}
	~MinQ(){
		delete[] data;
	}

	int enqueue(Item* item)
	{
		if (lastnode == capacity)
			return 0;
		data[++lastnode] = *item;

		int n = lastnode, p = n / 2;
		while (p > 0)
		{
			if (data[n].a < data[p].a)
			{
				Item temp;
				temp = data[n];
				data[n] = data[p];
				data[p] = temp;

				n = p; p = n / 2;
			}
			else break;
		}
		return 1;
	}

	int dequeue(Item* item)
	{
		if (lastnode == 0) return 0;
		*item = data[1];
		data[1] = data[lastnode--];

		int n = 1, lc = 2, rc = 3, c;
		while (lc <= lastnode)
		{
			if (lc == lastnode) c = lc;
			else c = (data[lc].a < data[rc].a) ? (lc) : (rc);

			if (data[c].a < data[n].a)
			{
				Item temp;
				temp = data[c];
				data[c] = data[n];
				data[n] = temp;

				n = c; lc = 2 * n; rc = lc + 1;
			}
			else break;
		}
		return 1;
	}
};

MinQ minq;

int main()
{
	Item d;
	d.a = 5;
	minq.enqueue(&d);
	d.a = 3;
	minq.enqueue(&d);
	d.a = 2;
	minq.enqueue(&d);
	d.a = 1;
	minq.enqueue(&d);
	d.a = 4;
	minq.enqueue(&d);

	while (minq.dequeue(&d))
	{
		printf("%d ", d.a);
	}

	return 0;
}