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

	// 배열이 비어있는 경우
	if (size == 1)
		return;

	int idx = size;
	int target = heap[idx];
	// 루트까지 도달 못했고, 부모보다 자신이 클 경우
	while ((idx != 1) && heap[idx / 2] < target)
	{
		heap[idx] = heap[idx / 2]; // 부모를 아래로 내려보냄
		idx = idx / 2;
	}
	heap[idx] = target;
}

int heap_delete()
{
	// 배열이 비어있는 경우
	if (size == 0)
		return 0;

	int result = heap[1]; // 루트를 결과로
	heap[1] = heap[size]; // 말단을 루트로
	size--;

	int idx = 1;
	int target = heap[idx];
	while (1)
	{
		int child = idx * 2;
		if (child <= size) // 자식이 존재하면
		{
			if (child + 1 <= size && heap[child + 1] > heap[child])
			{
				// 둘째가 존재하고 둘째가 더 크면 타겟을 둘째로
				child++;
			}
			if (heap[child] > target) // child가 타겟보다 더 크면
			{
				heap[idx] = heap[child]; // 타겟 자리에 child가 온다
				idx = child;
			}
			else
			{
				heap[idx] = target;
				break;
			}
		}
		else // 자식이 존재하지 않으면
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