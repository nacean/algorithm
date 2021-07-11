#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int N, S; scanf("%d %d", &N, &S); 
	vector<int> numbers;

	for (int i = 0; i < N; i++)
	{
		int num; scanf("%d", &num);
		numbers.push_back(num);
	}

	//투포인터 사용
	int start = 0; int end = 0;

	int answer = 0;
	int added_num = numbers[start];

	while (start <= end)
	{
		int length = end - start + 1;

		if (added_num >= S)
		{
			if (answer == 0) answer = length;
			else if (answer > length) answer = length;
			added_num -= numbers[start];
			start++;
		}
		else if (added_num < S)
		{
			end++;
			if (end == N) break;
			added_num += numbers[end];
		}
	}

	printf("%d\n", answer);

	return 0;
}