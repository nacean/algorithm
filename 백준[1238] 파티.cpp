#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define MAX_VALUE 987654321

using namespace std;

int ans = 0;
int x, n, m;
vector<pair<int,int>> node[1001];
int dp[1001][1001];

void djikstra(int first) {
	dp[first][first] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,first });
	while (!pq.empty()) {
		int now_node = pq.top().second;
		int now_weight = -pq.top().first;
		pq.pop();

		if (dp[first][now_node] < now_weight) continue;

		for (pair<int,int> next : node[now_node]) {
			int next_node = next.second;
			int next_weight = now_weight + next.first;

			if (dp[first][next_node] > next_weight) {
				dp[first][next_node] = next_weight;
				pq.push({ -next_weight,next_node });
			}
		}
	}
}

void xdjikstra(int first) {
	dp[first][first] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,first });
	while (!pq.empty()) {
		int now_node = pq.top().second;
		int now_weight = -pq.top().first;
		pq.pop();

		if (dp[first][now_node] < now_weight) continue;

		if (now_node == x) continue;

		for (pair<int, int> next : node[now_node]) {
			int next_node = next.second;
			int next_weight = now_weight + next.first;

			if (dp[first][next_node] > next_weight) {
				dp[first][next_node] = next_weight;
				pq.push({ -next_weight,next_node });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = MAX_VALUE;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		node[a].push_back({ w,b });
	}

	for (int i = 1; i <= n; i++) {
		if (i == x) djikstra(i);
		else xdjikstra(i);
	}

	for (int i = 1; i <= n; i++) {
		if (i != x) ans = max(ans, dp[i][x] + dp[x][i]);
	}

	cout << ans;


	return 0;
}