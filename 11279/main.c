#include <stdio.h>

#define MAX_SIZE 100001

int N;
int size = 0;
int heap[MAX_SIZE];

void heap_print()
{
	for (int i = 1; i <= size; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

void heap_insert(int item)
{
	size++;
	heap[size] = item;

	// �迭�� ����ִ� ���
	if (size == 1)
		return;

	int idx = size;
	int target = heap[idx];
	// ��Ʈ���� ���� ���߰�, �θ𺸴� �ڽ��� Ŭ ���
	while ((idx != 1) && heap[idx / 2] < target)
	{
		heap[idx] = heap[idx / 2]; // �θ� �Ʒ��� ��������
		idx = idx / 2;
	}
	heap[idx] = target;
}

int heap_delete()
{
	// �迭�� ����ִ� ���
	if (size == 0)
		return 0;

	int result = heap[1]; // ��Ʈ�� �����
	heap[1] = heap[size]; // ������ ��Ʈ��
	size--;

	int idx = 1;
	int target = heap[idx];
	while (1)
	{
		int child = idx * 2;
		if (child <= size) // �ڽ��� �����ϸ�
		{
			if (child + 1 <= size && heap[child + 1] > heap[child])
			{
				// ��°�� �����ϰ� ��°�� �� ũ�� Ÿ���� ��°��
				child++;
			}
			if (heap[child] > target) // child�� Ÿ�ٺ��� �� ũ��
			{
				heap[idx] = heap[child]; // Ÿ�� �ڸ��� child�� �´�
				idx = child;
			}
			else
			{
				heap[idx] = target;
				break;
			}
		}
		else // �ڽ��� �������� ������
		{
			heap[idx] = target;
			break;
		}
	}

	return result;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int curr;
		scanf("%d", &curr);
		if (curr == 0)
			printf("%d\n", heap_delete());
		else
			heap_insert(curr);
	}

	return 0;
}