#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

int main()
{
	int n; scanf("%d", &n);

	int cnt = n;

	for (int i = 0; i < n; i++)
	{
		int num; scanf("%d", &num);
		
		if (num == 1)
		{
			cnt -= 1;
			continue;
		}

		for (int t = 2; t <= sqrt(num); t++)
		{
			if (num % t == 0)
			{
				cnt -= 1;
				break;
			}
		}
	}
	printf("%d", cnt);

	return 0;
}