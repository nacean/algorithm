#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define MAX_VALUE 987654321
int n, m;
int start, stop;
using namespace std;
vector<int> ans;
int dp[1001];
vector<pair<int,int>> node[1001];

void dijkstra() {
	dp[start] = 0;
	priority_queue<pair<int,pair<int,vector<int>>>> pq;
	vector<int> first;
	first.push_back(start);
	pq.push({ 0,{start,first} });
	while (!pq.empty()) {
		int now_w = -pq.top().first;
		int now_node = pq.top().second.first;
		vector<int> now_vec = pq.top().second.second;
		pq.pop();
		if (dp[now_node] < now_w) continue;

		if (now_node == stop) {
			ans = now_vec;
			continue;
		}

		for (pair<int, int> next : node[now_node]) {
			int next_node = next.first;
			int next_weight = now_w + next.second;

			if (dp[next_node] > next_weight) {
				dp[next_node] = next_weight;
				vector<int> temp = now_vec;
				temp.push_back(next_node);
				pq.push({ -next_weight,{next_node,temp} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dp[i] = MAX_VALUE;
	}

	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		node[a].push_back({ b,w });
	}

	cin >> start >> stop;

	dijkstra();

	cout << dp[stop] << "\n";
	cout << (int)ans.size() << "\n";
	for (int num : ans) {
		cout << num << " ";
	}


	return 0;
}