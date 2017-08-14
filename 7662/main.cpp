#include <iostream>
using namespace std;

#define MAXN 1000001

class QItem{
public:
	long long int num;
	int idx;
	QItem(){
	}
};

class MinQ{
public:
	int size;
	int used;
	QItem** data;

	MinQ(){
		size = 128;
		used = 0;
		data = new QItem*[size];
	}

	~MinQ(){
		delete[] data;
	}

	void enqueue(QItem* item){
		used++;
		if (used == size)
		{
			QItem** temp = new QItem*[size];
			for (int i = 1; i < size; i++)
				temp[i] = data[i];
			delete[] data;
			data = new QItem*[size * 2];
			for (int i = 1; i < size; i++)
				data[i] = temp[i];
			delete[] temp;
			size *= 2;
		}

		int curr = used;
		int par = curr / 2;
		while (curr != 1 && (data[par]->num > item->num))
		{
			data[curr] = data[par];
			curr = par;
			par = curr / 2;
		}
		data[curr] = item;
	}

	QItem* dequeue()
	{
		if (used == 0)
			return NULL;

		QItem* pop = data[1]; // ������ ��ȯ�� ����
		data[1] = data[used]; // ������ ��Ʈ�� �ű��
		used--; // ������ �� �ϳ� ���̱�

		QItem* move_item = data[1];
		int curr = 1;
		while (1)
		{
			int child = curr * 2;
			if (child > used) // �ڽ��� ���� ��� (��)
				break;

			// �ڽ��� �Ѵ� �ְ�, �� �� child + 1 �� �� ���� ���� ���
			if (child + 1 <= used && (data[child]->num > data[child + 1]->num))
				child++;

			// �ڽ��� �� ���� ���
			if (data[child]->num < move_item->num)
			{
				data[curr] = data[child];
				curr = child;
			}
			else{ // �ڽ��� �ڽĺ��� �� ũ�ų� ���� ��� (��)
				break;
			}
		}
		data[curr] = move_item;
		return pop;
	}

	void print_all()
	{
		cout << "MINQ : ";
		for (int i = 1; i <= used; i++)
			cout << data[i]->num << " ";
		cout << endl;
	}
};

class MaxQ{
public:
	int size;
	int used;
	QItem** data;

	MaxQ(){
		size = 128;
		used = 0;
		data = new QItem*[size];
	}

	~MaxQ(){
		delete[] data;
	}

	void enqueue(QItem* item){
		used++;
		if (used == size)
		{
			QItem** temp = new QItem*[size];
			for (int i = 1; i < size; i++)
				temp[i] = data[i];
			delete[] data;
			data = new QItem*[size * 2];
			for (int i = 1; i < size; i++)
				data[i] = temp[i];
			delete[] temp;
			size *= 2;
		}

		int curr = used;
		int par = curr / 2;
		while (curr != 1 && (data[par]->num < item->num))
		{
			data[curr] = data[par];
			curr = par;
			par = curr / 2;
		}
		data[curr] = item;
	}

	QItem* dequeue()
	{
		if (used == 0)
			return NULL;

		QItem* pop = data[1]; // ������ ��ȯ�� ����
		data[1] = data[used]; // ������ ��Ʈ�� �ű��
		used--; // ������ �� �ϳ� ���̱�

		QItem* move_item = data[1];
		int curr = 1;
		while (1)
		{
			int child = curr * 2;
			if (child > used) // �ڽ��� ���� ��� (��)
				break;

			// �ڽ��� �Ѵ� �ְ�, �� �� child + 1 �� �� ū ���� ���
			if (child + 1 <= used && (data[child]->num < data[child + 1]->num))
				child++;

			// �ڽ��� �� Ŭ ���
			if (data[child]->num > move_item->num)
			{
				data[curr] = data[child];
				curr = child;
			}
			else{ // �ڽ��� �ڽĺ��� �� ũ�ų� ���� ��� (��)
				break;
			}
		}
		data[curr] = move_item;
		return pop;
	}

	void print_all()
	{
		cout << "MAXQ : ";
		for (int i = 1; i <= used; i++)
			cout << data[i]->num << " ";
		cout << endl;
	}
};

int k;
MaxQ* maxQ;
MinQ* minQ;
int visit[MAXN];

void Input()
{
	maxQ = new MaxQ();
	minQ = new MinQ();

	cin >> k;
	int idx = 0;
	while (k--)
	{
		char op[3];
		long long int num;
		cin >> op >> num;
		if (op[0] == 'I')
		{
			QItem* curr = new QItem();
			curr->num = num;
			curr->idx = ++idx;
			visit[idx] = 0;
			maxQ->enqueue(curr);
			minQ->enqueue(curr);
			//maxQ->print_all();
		    //minQ->print_all();
		}
		else // D
		{
			if (num == 1)
			{
				QItem* item = maxQ->dequeue();
				while (item != NULL && visit[item->idx] == 1)
					item = maxQ->dequeue();

				if (item == NULL)
					continue;

				visit[item->idx] = 1;
				//cout << "POP : " << item->num << endl;
				//maxQ->print_all();
				//minQ->print_all();
			}
			else
			{
				QItem* item = minQ->dequeue();
				while (item != NULL && visit[item->idx] == 1)
					item = minQ->dequeue();
				
				if (item == NULL)
					continue;

				visit[item->idx] = 1;
				//cout << "POP : " << item->num << endl;
				//maxQ->print_all();
				//minQ->print_all();
			}
		}
	}

	QItem* max_item = maxQ->dequeue();
	while (max_item != NULL && visit[max_item->idx] == 1)
		max_item = maxQ->dequeue();
	QItem* min_item = minQ->dequeue();
	while (min_item != NULL && visit[min_item->idx] == 1)
		min_item = minQ->dequeue();

	if (max_item == NULL && min_item == NULL)
		cout << "EMPTY" << endl;
	else
		cout << max_item->num << " " << min_item->num << endl;

	delete maxQ;
	delete minQ;
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		Input();
	}

	return 0;
}