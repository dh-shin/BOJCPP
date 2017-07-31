#include <stdio.h>

int T;
int x1, y1, r1;
int x2, y2, r2;

void Process()
{
	scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

	if (x1 == x2 && y1 == y2) // 중심이 같은 경우
	{
		if (r1 == r2) // 반지름도 같은 경우 (무한대)
			printf("-1\n");
		else // 반지름이 같지 않은 경우 (0)
			printf("0\n");
	}
	else{ // 중심이 같지 않은 경우
		int cdist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); // 두 중심 간 거리
		int rdist = (r1 + r2) * (r1 + r2); // 두 반지름의 합

		if (cdist == rdist) // 중심간 거리와 반지름의 합이 같을 경우 (1)
			printf("1\n");
		else if (cdist < rdist) // 반지름이 더 클 경우 (2)
			printf("2\n");
		else // 중심간 거리가 더 클 경우 (0)
			printf("0\n");
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
		Process();
	scanf("%d", &T);

	return 0;
}