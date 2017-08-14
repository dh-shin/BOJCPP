#include <iostream>
using namespace std;


class MinQ{

};

class MaxQ{
public:
	int size;
	int* data;
	int used;
	int pop;
	MaxQ(){
		size = 128;
		used = 0;
		data = new int[size];
	}
	~MaxQ(){
		delete[] data;
	}

	void enqueue(int item){
		used++;
		if (used == size)
		{
			int* temp = new int[size];
			for (int i = 1; i < size; i++)
				temp[i] = data[i];
			delete[] data;
			data = new int[size * 2];
			for (int i = 1; i < size; i++)
				data[i] = temp[i];
			delete[] temp;
			size *= 2;
		}
		int curr = used;
		int par = curr / 2;
		while (curr != 1 && data[par] < item)
		{
			data[curr] = data[par];
			curr = par;
			par = curr / 2;
		}
		data[curr] = item;
	}

	bool dequeue()
	{
		if (used == 0)
			return false;
		
		pop = data[1]; // 정해진 반환값 지정
		used--;

		int curr = 1;
		data[curr] = data[used]; // 말단을 루트로 옮기기
		int curr_item = data[curr];
		while (1)
		{
			int child = curr * 2;
			if (child > used) // 자식이 없는 경우 (끝)
				break; 

			// 자식이 둘다 있고, 둘 중 child + 1 이 더 큰 놈일 경우
			if (child + 1 <= used && data[child] < data[child + 1])
				child++;

			// 자식이 더 클 경우
			if (data[child] > curr_item)
			{
				data[curr] = data[child];
				curr = child;
			}
			else{ // 자신이 자식보다 더 크거나 같을 경우 (끝)
				break;
			}
		}
		data[curr] = curr_item;
		return true;
	}
};

int k;
MaxQ* maxQ;

void Input()
{
	maxQ = new MaxQ();

	cin >> k;
	while (k--)
	{
		int curr;
		cin >> curr;
		maxQ->enqueue(curr);
	}

	while (maxQ->dequeue() == true)
	{
		int output = maxQ->pop;
		cout << output << endl;
	}
	
	delete maxQ;
}

void Process()
{

}

void Output()
{

}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		Input();
	}

	return 0;
}