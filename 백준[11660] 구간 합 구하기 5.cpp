#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define MAX_VALUE 987654321
using namespace std;

int dp[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num; cin >> num;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + num - dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;

		cout << dp[a][b] - dp[a][y - 1] - dp[x - 1][b] + dp[x - 1][y - 1] << "\n";
	}

	return 0;
}