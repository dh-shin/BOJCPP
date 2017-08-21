#include <iostream>
using namespace std;

#define MAXL 600010

class Node{
public:
	char letter;
	Node* next;
	Node* prev;
	Node(char letter){
		this->letter = letter;
		next = NULL;
		prev = NULL;
	}
	~Node(){
		next = NULL;
		prev = NULL;
	}
};

int N;
int size;
char* editor;
Node* cursor;
Node* head;
Node* empty;

void PrintAll()
{
	Node* iter = head;
	while (iter != empty)
	{
		cout << iter->letter;
		iter = iter->next;
	}
	cout << "\n";
}

void Input()
{
	editor = new char[MAXL];
	cin.getline(editor, MAXL);

	size = 0;
	for (int i = 0; i < MAXL; i++)
	{
		if (editor[i] == '\0')
			break;
		size++;
	}

	empty = new Node('\0');
	cursor = empty;
	head = empty;

	for (int i = 0; i < size; i++)
	{
		Node* node = new Node(editor[i]);
		node->next = cursor;
		node->prev = cursor->prev;
		if (cursor->prev != NULL) cursor->prev->next = node;
		else head = node;
		cursor->prev = node;
	}
	//PrintAll();
	cin >> N;
}

void Process()
{
	char inst, letter;
	while (N--){
		cin >> inst;
		if (inst == 'P') // letter¸¦ Ä¿¼­ ¿ÞÂÊ¿¡ Ãß°¡
		{
			cin >> letter;
			Node* node = new Node(letter);

			node->next = cursor;
			node->prev = cursor->prev;
			if (cursor->prev != NULL) cursor->prev->next = node;
			else head = node;
			cursor->prev = node;
		}
		else if (inst == 'L') // ¿ÞÂÊ ÇÑ Ä­
		{
			if (cursor->prev != NULL) cursor = cursor->prev;
		}
		else if (inst == 'D') // ¿À¸¥ÂÊ ÇÑ Ä­
		{
			if (cursor->next != NULL) cursor = cursor->next;
		}
		else // B: ¿ÞÂÊ ¹®ÀÚ »èÁ¦
		{
			if (cursor == head) continue;
			else if (cursor->prev == head)
			{
				cursor->prev = NULL;
				delete cursor->prev;
				head = cursor;
			}
			else
			{
				Node* newprev = cursor->prev->prev;
				Node* oldprev = cursor->prev;
				newprev->next = cursor;
				cursor->prev = newprev;
				delete oldprev;
			}
		}
	}
}

void Output()
{
	PrintAll();
}

int main()
{
	Input();
	Process();
	Output();

	return 0;
}