#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<utility>
#include<math.h>
#include<cstring>
#include<queue>
#define ll long long

using namespace std;

ll node[100001];

void dijkstra(int n, int k) {
	priority_queue<pair<ll, int>> pq;

	pq.push(make_pair(0, n));

	while (!pq.empty()) {
		int now_node = pq.top().second;
		ll now_cnt = -pq.top().first;
		pq.pop();
		if (node[now_node] < now_cnt) continue;
		if (now_node == k) continue;

		int first_node = now_node - 1;
		int second_node = now_node + 1;
		int third_node = now_node * 2;

		if (first_node >= 0) {
			if (node[first_node] > now_cnt + 1) {
				node[first_node] = now_cnt + 1;
				pq.push({ -now_cnt - 1,first_node });
			}
		}
		if (second_node <= 100000) {
			if (node[second_node] > now_cnt + 1) {
				node[second_node] = now_cnt + 1;
				pq.push({ -now_cnt - 1,second_node });
			}
		}
		if (third_node <= 100000) {
			if (node[third_node] > now_cnt) {
				node[third_node] = now_cnt;
				pq.push({ -now_cnt,third_node });
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;

	memset(node, 98765321, sizeof(node));

	node[n] = 0;

	dijkstra(n, k);

	cout << node[k] << "\n";
	
	return 0;

}