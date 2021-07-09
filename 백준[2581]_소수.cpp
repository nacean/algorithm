#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;



int main()
{

	int start, end; scanf("%d %d", &start, &end);

	int all = 0;
	int min_answer = 999999;

	for (int i = start; i <= end; i++)
	{
		bool is_sosu = true;

		if (i == 1) continue;

		for (int t = 2; t <= sqrt(i); t++)
		{
			if (i % t == 0)
			{
				is_sosu = false;
				break;
			}
		}

		if (is_sosu == true)
		{
			if (min_answer > i) min_answer = i;
			all += i;
		}

	}

	if (all == 0) printf("-1");

	else
		printf("%d\n%d", all, min_answer);

	return 0;
}