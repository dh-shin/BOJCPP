#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 100000
#define QSIZE 300020

long long int M;
int N, Q;

long long int A[QSIZE + 1];
int B[MAXN + 1];

class Range{
public:
	long long int s; // 시작 위치
	long long int e; // 끝 위치
	long long int cnt; // 구간 길이

	// this가 높으면 양수, 낮으면 음수
	long long int comp(Range* range)
	{
		if (this->cnt == range->cnt) return range->s - this->s;
		else return this->cnt - range->cnt;
	}
};

class PQ{
public:
	int lastnode;
	Range* data;
	PQ(){
		lastnode = 0;
		data = new Range[QSIZE + 1];
	}
	~PQ(){
		delete[] data;
	}
	
	int enqueue(Range* range)
	{
		if (lastnode == QSIZE) return 0;
		data[++lastnode] = *range;
		
		int n = lastnode, p = n / 2;
		Range temp;

		while (p > 0)
		{
			if (data[n].comp(&data[p]) > 0)
			{
				
				temp = data[n];
				data[n] = data[p];
				data[p] = temp;

				n = p; p = n / 2;
			}
			else break;
		}

		return 1;
	}
	
	int dequeue(Range* range)
	{
		if (lastnode == 0) return 0;

		int n, lc, rc, c;
		Range temp;

		*range = data[1];
		data[1] = data[lastnode--];

		n = 1, lc = 2, rc = 3;

		while (lc <= lastnode)
		{
			if (lc == lastnode) c = lc;
			else c = (data[lc].comp(&data[rc])) > 0 ? (lc) : (rc);

			if (data[c].comp(&data[n]) > 0)
			{		
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

PQ pq;

void Input()
{
	cin >> M;
	cin >> N >> Q;
	Range range;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		range.s = A[i - 1] + 1;
		range.e = A[i] - 1;
		range.cnt = range.e - range.s + 1;
		if(range.cnt > 0) pq.enqueue(&range);
	}
	range.s = A[N] + 1;
	range.e = M;
	range.cnt = range.e - range.s + 1;
	if (range.cnt > 0) pq.enqueue(&range);

	for (int i = 1; i <= Q; i++)
		cin >> B[i];
}

void Process()
{
	long long int seat;
	Range range, nrange;
	for (int i = N + 1; i <= B[Q]; i++)
	{
		pq.dequeue(&range);
		
		seat = (range.s + range.e) / 2;

		nrange.s = range.s;
		nrange.e = seat - 1;
		nrange.cnt = nrange.e - nrange.s + 1;
		if (nrange.cnt > 0) pq.enqueue(&nrange);

		nrange.s = seat + 1;
		nrange.e = range.e;
		nrange.cnt = nrange.e - nrange.s + 1;
		if (nrange.cnt > 0) pq.enqueue(&nrange);
		
		A[i] = seat;
	}
}

void Output()
{
	for (int i = 1; i <= Q; i++)
		printf("%lld\n", A[B[i]]);
}

int main()
{
	Input();
	Process();
	Output();

	return 0;
}
