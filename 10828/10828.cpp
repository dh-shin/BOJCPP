#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* prevNode;
	Node(int data){
		this->data = data;
	}
};

class Stack{
private:
	int counter = 0;
	Node* topNode;

public:
	Stack() {
		counter = 0;
		topNode = NULL;
	}

	void Push(int data){
		if (topNode == NULL){
			topNode = new Node(data);
			topNode->prevNode = NULL;
			counter++;
		}
		else{
			Node* newNode = new Node(data);
			newNode->prevNode = topNode;
			topNode = newNode;
			counter++;
		}
	}

	int Pop(){
		if (topNode == NULL)
		{
			return -1;
		}
		else{
			int result = topNode->data;
			if (topNode->prevNode == NULL){
				delete topNode;
				topNode = NULL;
			}
			else{
				Node* deletable = topNode;
				topNode = topNode->prevNode;
				delete deletable;
			}
			counter--;
			return result;
		}
	}

	int Top(){
		if (topNode == NULL)
			return -1;
		else
			return topNode->data;
	}

	int Size(){
		return counter;
	}

	int Empty(){
		if (counter == 0)
			return 1;
		else
			return 0;
	}
};

int main()
{
	int n;
	cin >> n;

	Stack stack;

	while (n--)
	{
		string command;
		cin >> command;
		if (command.compare("push") == 0)
		{
			int input;
			cin >> input;

			stack.Push(input);
		}
		else if (command.compare("top") == 0)
		{
			cout << stack.Top() << endl;
		}
		else if (command.compare("size") == 0)
		{
			cout << stack.Size() << endl;
		}
		else if (command.compare("empty") == 0)
		{
			cout << stack.Empty() << endl;
		}
		else
		{
			cout << stack.Pop() << endl;
		}
	}
	return 0;
}