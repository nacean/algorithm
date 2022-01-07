#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#define ll long long

using namespace std;

ll dp[10][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[1][i - 1] % 1000000000;
		for (int k = 1; k <= 8; k++) {
			dp[k][i] = (dp[k - 1][i - 1] + dp[k + 1][i - 1]) % 1000000000;
		}
		dp[9][i] = dp[8][i - 1] % 1000000000;
	}

	ll answer = 0;
	if (n == 1) cout << 9;
	else {
		for (int i = 0; i <= 9; i++) {
			answer = (answer + dp[i][n]) % 1000000000;
		}
		cout << answer;
	}

	return 0;
}