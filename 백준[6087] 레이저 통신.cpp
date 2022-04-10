#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define MAX_VALUE 987654321
using namespace std;

char board[100][100];
vector<pair<int, int>> c;
int w, h;
int dp[100][100];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void bfs() {
	priority_queue<pair<pair<int,int>,pair<int,int>>> pq;
	int first_row = c[0].first;
	int first_col = c[0].second;

	for (int i = 0; i < 4; i++) {
		int next_row = first_row + dy[i];
		int next_col = first_col + dx[i];

		if (next_row < 0 || next_col < 0 || next_row >= h || next_col >= w) continue;
		if (board[next_row][next_col] == '*') continue;

		pq.push({{0,i},{next_row,next_col} });
		dp[next_row][next_col] = 0;
	}

	while (!pq.empty()) {
		int now_row = pq.top().second.first;
		int now_col = pq.top().second.second;
		int now_cnt = -pq.top().first.first;
		int now_dir = pq.top().first.second;
		pq.pop();

		if (dp[now_row][now_col] < now_cnt) continue;
		if (now_row == c[1].first && now_col == c[1].second) continue;

		for (int i = 0; i < 4; i++) {
			if (i == (now_dir + 2) % 4) continue;

			int next_row = now_row + dy[i];
			int next_col = now_col + dx[i];
			int next_cnt = i == now_dir ? now_cnt : now_cnt + 1;
			int next_dir = i;

			if (next_row < 0 || next_col < 0 || next_row >= h || next_col >= w) continue;
			if (board[next_row][next_col] == '*') continue;

			if (dp[next_row][next_col] >= next_cnt) {
				dp[next_row][next_col] = next_cnt;
				pq.push({ { -next_cnt,next_dir }, { next_row,next_col } });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	 cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char tmp; cin >> tmp;
			board[i][j] = tmp;
			if (tmp == 'C') c.push_back({ i,j });
			dp[i][j] = MAX_VALUE;
		}
	}

	dp[c[0].first][c[0].second] = 0;

	bfs();

	cout << dp[c[1].first][c[1].second];

	return 0;
}