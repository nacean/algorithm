#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#define ll long long

using namespace std;

ll dp[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		dp[0][i] = 1;
		dp[1][i] = 1;
		dp[2][i] = 1;
	}

	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		for (int k = 3; k < n; k++) {
			dp[k][i] = dp[k - 2][i] + dp[k - 3][i];
		}

		cout << dp[n - 1][i] << "\n";
	}

	return 0;
}
