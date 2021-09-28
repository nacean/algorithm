#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

int board[1000][1000];
int dp[1000][1000];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int n, int m) {
	priority_queue<pair<int, pair<int, int>>> q;
	q.push({ 1,{ 0,0 } });

	while (!q.empty()) {
		int now_row = q.top().second.first;
		int now_col = q.top().second.second;
		int now_weight = -q.top().first;
		q.pop();

		if (now_weight > dp[now_row][now_col]) continue;

		for (int i = 0; i < 4; i++) {
			int next_row = now_row + dy[i];
			int next_col = now_col + dx[i];
			if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m) continue;
			if (board[next_row][next_col] == -1) continue;
			int weight = dp[now_row][now_col] + board[next_row][next_col];

			if (dp[next_row][next_col] > weight) {
				dp[next_row][next_col] = weight;
				q.push({ -weight,{ next_row,next_col } });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num; cin >> num;
			board[i][j] = num;
			dp[i][j] = 987654321;
		}
	}

	dp[0][0] = board[0][0];

	if (board[0][0] == -1 || board[n - 1][m - 1] == -1) {
		cout << "-1" << endl;
		return 0;
	}

	bfs(n, m);

	if (dp[n - 1][m - 1] == 987654321) {
		cout << "-1" << endl;
	}
	else {
		cout << dp[n - 1][m - 1] << endl;
	}

	return 0;
}

/*
void bfs(int n, int m) {
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int now_row = q.front().first;
		int now_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = now_row + dy[i];
			int next_col = now_col + dx[i];

			if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m) continue;
			if (board[next_row][next_col] == -1) continue;

			int weight = dp[now_row][now_col] + board[next_row][next_col];

			if (dp[next_row][next_col] > weight) {
				dp[next_row][next_col] = weight;
				q.push({ next_row,next_col });
			}
		}
	}
}
*/
