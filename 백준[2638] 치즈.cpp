#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define MAX_VALUE 987654321

using namespace std;

int n, m;
int board[101][101];
int cheeze_cnt = 0;
int ans = 0;
int outside = 2;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void bfs() {
	board[0][0] = outside;
	queue < pair<int, int> >q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int now_row = q.front().first;
		int now_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = now_row + dy[i];
			int next_col = now_col + dx[i];

			if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m) continue;
			if (board[next_row][next_col] == 1 || board[next_row][next_col] == outside) continue;

			board[next_row][next_col] = outside;
			q.push({ next_row,next_col });
		}
	}
}

void func() {
	vector<pair<int,int>> to_erase;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			if (board[row][col] != 1) continue;
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int next_row = row + dy[i];
				int next_col = col + dx[i];
				if (board[next_row][next_col] == outside) cnt++;
				if (cnt == 2) break;
			}
			if (cnt >= 2) to_erase.push_back({ row,col });
		}
	}
	for (pair<int, int> next : to_erase) {
		board[next.first][next.second] = 0;
		cheeze_cnt--;
	}
	ans++;
	outside++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j]) cheeze_cnt++;
		}
	}

	while (cheeze_cnt != 0) {
		bfs();
		func();
	}

	cout << ans;

	return 0;
}