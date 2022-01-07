#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#define ll long long

using namespace std;

ll dp[100000];

ll num[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	dp[0] = num[0];

	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + num[i], num[i]);
	}

	ll answer = -99999999;
	for (int i = 0; i < n; i++) {
		answer = max(dp[i], answer);
	}

	cout << answer;

	return 0;
}
