#include <iostream>
using namespace std;

class Node{
public:
	int num;
	Node* next;
	Node(int num){
		this->num = num;
		next = NULL;
	}
};

int N, M;
int size;
Node* head;

void PrintAll()
{
	Node* curr = head;
	for (int i = 1; i <= N; i++)
	{
		cout << curr->num << " ";
		curr = curr->next;
	}
	cout << "\n";
}

void Input()
{
	cin >> N >> M;
	size = N;
	head = NULL;	
	Node* prev = NULL;
	for (int i = 1; i <= N; i++)
	{
		Node* node = new Node(i);
		if (prev == NULL) head = node;
		else  prev->next = node;
		node->next = head;
		prev = node;
	}
}

void Process()
{
	cout << "<";
	Node* prev;
	Node* curr = head;
	while (size--)
	{
		for (int i = 1; i <= M - 1; i++)
		{
			prev = curr;
			curr = curr->next;
		}
		
		if (size == 0) cout << curr->num << ">";
		else cout << curr->num << ", ";

		prev->next = curr->next;
		delete curr;

		curr = prev->next;
	}
	cout << "\n";
}

int main()
{
	Input();
	Process();

	return 0;
}