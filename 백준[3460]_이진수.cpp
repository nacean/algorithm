#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

int main()
{
	//t== 테스트 케이스, n == k번째로 작은 수
	int t; scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n; scanf("%d", &n);

	
		int cnt = 0;
		while (n != 1 && n != 0)
		{
			int new_other = n % 2;
			if (new_other == 1) printf("%d ", cnt);
			int new_n = n / 2;
			n = new_n;
			cnt++;
		}

		if (n == 1) printf("%d", cnt);


		printf("\n");
	}
	
	return 0;
}