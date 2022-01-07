#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#define ll long long

using namespace std;

ll dp[1000001][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i < n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 15746;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % 15746;
	}

	cout << (dp[n - 1][0] + dp[n - 1][1]) % 15746;

	return 0;
}
