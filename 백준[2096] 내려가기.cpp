#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define MAX_VALUE 987654321

using namespace std;

int min_dp[3][2];
int max_dp[3][2];
int board[3][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int tc = 0; tc < n; tc++) {
		int a, b, c; cin >> a >> b >> c;

		if (tc == 0) {
			board[0][0] = a;
			board[1][0] = b;
			board[2][0] = c;

			for (int j = 0; j < 3; j++) {
				min_dp[j][0] = board[j][0];
				max_dp[j][0] = board[j][0];
				min_dp[j][1] = MAX_VALUE;
			}
			continue;
		}

		board[0][1] = a;
		board[1][1] = b;
		board[2][1] = c;

		min_dp[1][1] = min(min_dp[0][0], min(min_dp[1][0], min_dp[2][0])) + board[1][1];
		max_dp[1][1] = max(max_dp[0][0], max(max_dp[1][0], max_dp[2][0])) + board[1][1];

		min_dp[0][1] = min(min_dp[0][0], min_dp[1][0]) + board[0][1];
		max_dp[0][1] = max(max_dp[0][0], max_dp[1][0]) + board[0][1];

		min_dp[2][1] = min(min_dp[1][0], min_dp[2][0]) + board[2][1];
		max_dp[2][1] = max(max_dp[1][0], max_dp[2][0]) + board[2][1];


		for (int j = 0; j < 3; j++) {
			min_dp[j][0] = min_dp[j][1];
			max_dp[j][0] = max_dp[j][1];
		}
	}

	int max_ans = max(max_dp[0][0], max(max_dp[1][0], max_dp[2][0]));
	int min_ans = min(min_dp[0][0], min(min_dp[1][0], min_dp[2][0]));


	cout << max_ans << " " << min_ans;

	return 0;
}