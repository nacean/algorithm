#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;



int main()
{
	vector<int> v;

	int start, end; scanf("%d %d", &start, &end);

	for (int i = 1; i <= 1000; i++)
	{
		for (int k = 0; k < i; k++)
		{
			v.push_back(i);
		}
	}

	int answer = 0;

	for (int i = start; i <= end; i++)
	{
		answer += v[i-1];
	}

	printf("%d", answer);


	return 0;
}