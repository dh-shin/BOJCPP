#include <iostream>
#include <string>
using namespace std;

class Node{
public:
	int data;
	Node* nextNode;
	Node(int data){
		this->data = data;
		nextNode = NULL;
	}
};

class Queue{
private:
	int counter;
	Node* firstNode;
	Node* lastNode;
public:
	Queue(){
		counter = 0;
		firstNode = NULL;
		lastNode = NULL;
	}
	
	void Push(int data){
		Node* newNode = new Node(data);
		if (lastNode == NULL){
			firstNode = newNode;
			lastNode = newNode;
		}
		else {
			lastNode->nextNode = newNode;
			lastNode = newNode;
		}
		counter++;
	}

	int Pop(){
		if (lastNode == NULL){
			return -1;
		}
		else{
			int result = firstNode->data;
			if (firstNode == lastNode)
			{
				delete firstNode;
				firstNode = NULL;
				lastNode = NULL;
			}
			else{
				Node* newFirst = firstNode->nextNode;
				delete firstNode;
				firstNode = newFirst;
			}
			counter--;
			return result;
		}
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

	int Front(){
		if (firstNode == NULL)
			return -1;
		else
			return firstNode->data;
	}

	int Back(){
		if (lastNode == NULL)
			return -1;
		else
			return lastNode->data;
	}
};

int main()
{
	int n;
	cin >> n;
	Queue queue;
	while (n--)
	{
		string command;
		cin >> command;
		if (command == "push"){
			int data;
			cin >> data;
			queue.Push(data);
		}
		else if (command == "pop"){
			cout << queue.Pop() << endl;
		}
		else if (command == "size"){
			cout << queue.Size() << endl;
		}
		else if (command == "empty"){
			cout << queue.Empty() << endl;
		}
		else if (command == "back"){
			cout << queue.Back() << endl;
		}
		else{
			cout << queue.Front() << endl;
		}
	}
	return 0;
}