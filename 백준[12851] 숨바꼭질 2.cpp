#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define MAX_VALUE 987654321
using namespace std;

int ans = -1;
int ans_cnt = 0;
int dp[100001];

void dijkstra(int subin, int target) {
	dp[subin] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,subin });

	while (!pq.empty()) {
		int now_len = -pq.top().first;
		int now_node = pq.top().second;

		pq.pop();

		if (dp[now_node] < now_len) continue;

		if (now_node == target) {
			if (ans == now_len) ans_cnt++;

			else {
				ans = now_len;
				ans_cnt = 1;
			}
			continue;
		}

		if (now_node - 1 >= 0) {
			if (dp[now_node - 1] >= now_len + 1) {
				dp[now_node - 1] = now_len + 1;
				pq.push({ -(now_len + 1),now_node - 1 });
			}
		}
		if (now_node + 1 <= 100000) {
			if (dp[now_node + 1] >= now_len + 1) {
				dp[now_node + 1] = now_len + 1;
				pq.push({ -(now_len + 1),now_node + 1 });
			}
		}
		if (now_node * 2 <= 100000) {
			if (dp[now_node * 2] >= now_len + 1) {
				dp[now_node * 2] = now_len + 1;
				pq.push({ -(now_len + 1),now_node * 2 });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int subin, target; cin >> subin >> target;

	for (int i = 0; i <= 100000; i++) {
		dp[i] = MAX_VALUE;
	}

	dijkstra(subin, target);

	cout << dp[target] << endl << ans_cnt << endl;

	return 0;
}