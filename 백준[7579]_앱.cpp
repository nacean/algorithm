#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#define ll long long

using namespace std;

int dp[10001]; // 현재 index 비용에서 최대 크기
int memory[100];
int cost[100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> memory[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}


	for (int pos = 0; pos < n; pos++) {
		for (int now_cost = 10000; now_cost >=cost[pos]; now_cost--) {
			dp[now_cost] = max(dp[now_cost], dp[now_cost - cost[pos]] + memory[pos]);
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= m) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}
