#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>

#define MAX 987654321

using namespace std;

int answer = -1;

void make_answer(long long int a, long long int b, int cnt)
{
	if (a > b) return;

	if (a == b)
	{
		if (answer == -1) answer = cnt;
		else if (answer > cnt) answer = cnt;
		
		return;
	}

	make_answer(a * 2, b, cnt + 1);
	make_answer(a * 10 + 1, b, cnt + 1);
	
}


int main()
{
	long long int a, b; scanf("%lld %lld", &a, &b);

	make_answer(a, b, 0);

	if (a > b || answer == -1) printf("-1");

	else
	{
		answer++;
		printf("%d", answer);
	}
	return 0;
}