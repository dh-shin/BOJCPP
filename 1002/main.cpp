#include <stdio.h>

int T;
int x1, y1, r1;
int x2, y2, r2;

void Process()
{
	scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

	if (x1 == x2 && y1 == y2) // �߽��� ���� ���
	{
		if (r1 == r2) // �������� ���� ��� (���Ѵ�)
			printf("-1\n");
		else // �������� ���� ���� ��� (0)
			printf("0\n");
	}
	else{ // �߽��� ���� ���� ���
		int cdist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); // �� �߽� �� �Ÿ�
		int rdist = (r1 + r2) * (r1 + r2); // �� �������� ��

		if (cdist == rdist) // �߽ɰ� �Ÿ��� �������� ���� ���� ��� (1)
			printf("1\n");
		else if (cdist < rdist) // �������� �� Ŭ ��� (2)
			printf("2\n");
		else // �߽ɰ� �Ÿ��� �� Ŭ ��� (0)
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