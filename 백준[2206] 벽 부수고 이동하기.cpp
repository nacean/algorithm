#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

int n, m;
int board[1001][1001];
int dp[2][1001][1001];

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void break_bfs() {
    priority_queue<pair<pair<int,int>, pair<int, int>>> pq;
    dp[0][1][1] = 1;
    pq.push({ {-1,0},{1,1} });

    while (!pq.empty()) {
        int now_dist = -(pq.top().first.first);
        int now_row = pq.top().second.first;
        int now_col = pq.top().second.second;
        int break_cnt = -pq.top().first.second;
        pq.pop();

        if (break_cnt == 1) {
            if (dp[break_cnt][now_row][now_col] < now_dist || dp[0][now_row][now_col] <= now_dist) continue;
        }
        else if (break_cnt == 0) {
            if (dp[0][now_row][now_col] < now_dist) continue;
        }

        if (now_row == n && now_col == m) continue;

        for (int i = 0; i < 4; i++) {
            int next_row = now_row + dy[i];
            int next_col = now_col + dx[i];
            int next_dist = now_dist + 1;

            if (next_row < 1 || next_col < 1 || next_row > n || next_col > m) continue;

            if (break_cnt == 0) { //부수면서 이동
                if (board[next_row][next_col] == 1 && dp[1][next_row][next_col] > next_dist && dp[0][next_row][next_col] > next_dist ) {
                    dp[1][next_row][next_col] = next_dist;
                    pq.push({ {-next_dist,-1},{next_row,next_col} });
                }
            }

            if (board[next_row][next_col] == 1) continue;

            if (dp[break_cnt][next_row][next_col] > next_dist) {
                dp[break_cnt][next_row][next_col] = next_dist;
                pq.push({ { -next_dist,-break_cnt }, { next_row,next_col } });
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++) {
            board[i][j] = (s[j - 1] - '0');
            dp[0][i][j] = 98765432;
            dp[1][i][j] = 98765432;
        }
    }

    

    break_bfs();

    int ans = min(dp[0][n][m], dp[1][n][m]);
    if (ans == 98765432) cout << -1;
    else cout << ans;

    return 0;
}