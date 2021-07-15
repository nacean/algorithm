#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>

#define MAX 987654321

using namespace std;

long long int dp[1500003];

int main()
{
	int n; scanf("%d", &n);
	//(몇일걸리는가(오늘포함),얼마받는가)
	vector<pair<int,long long int>> calls;
	calls.push_back({ 0,0 });

	for (int i = 0; i < n; i++)
	{
		int a,b; scanf("%d %d", &a,&b);
		calls.push_back({ a,b });
	}

	for (int i = 1; i <= n; i++)
	{
		int plus_day = calls[i].first;
		if (dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
		long long int price = calls[i].second + dp[i];

		if (i + plus_day > n + 1) continue;
		if (price > dp[i+plus_day]) dp[i+plus_day] = price;
	}

	long long int answer = 0;

	for (int i = 1; i <= n+1; i++)
	{
		if (answer < dp[i])	answer = dp[i];
	}

	printf("%lld", answer);

	return 0;
}