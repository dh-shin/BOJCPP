#include <iostream>
using namespace std;

#define MAXN 100001

class MinQ{
public:
	int size;
	int used;
	int* data;
	
	MinQ()
	{
		size = MAXN;
		used = 0;
		data = new int[MAXN];
	}

	void enqueue(int item)
	{
		used++;
		data[used] = item;
		int curr = used;
		int par = curr / 2;
		while (curr != 1 && data[par] > item)
		{
			data[curr] = data[par];
			curr = par;
			par = curr / 2;
		}
		data[curr] = item;
	}

	int dequeue()
	{
		if (used == 0)
			return 0;
		
		int pop = data[1];
		data[1] = data[used];
		used--;

		int curr = 1;
		int target = data[1];
		while (1)
		{
			int child = curr * 2;
			if (child > used)
				break;

			if (child + 1 <= used && data[child + 1] < data[child])
				child++;
			
			if (data[child] < target)
			{
				data[curr] = data[child];
				curr = child;
			}
			else{
				break;
			}
		}
		data[curr] = target;
		return pop;
	}
};

int N;
MinQ minq;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int curr;
		cin >> curr;
		if (curr == 0)
		{
			int result = minq.dequeue();
			cout << result << endl;
		}
		else{
			minq.enqueue(curr);
		}
	}
	return 0;
}