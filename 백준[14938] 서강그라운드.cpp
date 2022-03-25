#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define MAX_VALUE 987654321

using namespace std;

int n, m, r;

int supply[101];

vector<pair<int,int>> node[101];
int dp[101][101];

void dijkstra(int first) {
	dp[first][first] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,first });

	while(!pq.empty()) {
		int now_node = pq.top().second;
		int now_len = -pq.top().first;
		pq.pop();

		if (dp[first][now_node] < now_len) continue;

		for (pair<int, int> next : node[now_node]) {
			int next_node = next.second;
			int next_len = next.first + now_len;

			if (next_len < dp[first][next_node]) {
				dp[first][next_node] = next_len;
				pq.push({ -next_len,next_node });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		supply[i] = num;
		for (int j = 1; j <= n; j++) {
			dp[i][j] = MAX_VALUE;
		}
	}

	for (int i = 1; i <= r; i++) {
		int a, b, l; cin >> a >> b >> l;
		node[a].push_back({ l,b });
		node[b].push_back({ l,a });
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] <= m) temp += supply[j];
		}
		ans = max(temp, ans);
	}

	cout << ans;

	return 0;
}