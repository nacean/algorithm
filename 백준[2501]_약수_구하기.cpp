#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int main()
{
	//n == ����, k == k��°�� ���� ��
	int n,k; scanf("%d %d", &n, &k);
	int answer = 0;
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			cnt++;

		if (cnt == k)
		{
			answer = i;
			break;
		}
	}

	printf("%d\n", answer);
	
	return 0;
}