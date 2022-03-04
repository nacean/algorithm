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

int parent[1001];
pair<int, int> coor[1001];
bool check[1001][1001];

int get_parent(int x) {
	if (parent[x] == x) return x;

	else return parent[x] = get_parent(parent[x]);
}

void union_parent(int a, int b) {
	int p_a = get_parent(a);
	int p_b = get_parent(b);

	if (p_a < p_b) parent[p_b] = p_a;
	else parent[p_a] = p_b;
}

bool is_same_parent(int a, int b) {
	int p_a = get_parent(a);
	int p_b = get_parent(b);
	if (p_a == p_b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m; cin >> n >> m;

	double ans = 0;

	for (int i = 1; i <= 1000; i++) parent[i] = i;

	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		coor[i] = { x,y };
	}

	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		union_parent(a, b);
		check[a][b] = true;
		check[b][a] = true;
	}

	priority_queue < pair<double, pair<int, int>>> pq;

	for (int a = 1; a <= n-1; a++) {
		for (int b = a + 1; b <= n; b++) {
			double cnt = sqrt(pow(abs(coor[a].first - coor[b].first), 2) + pow(abs(coor[a].second - coor[b].second), 2));
			pq.push({ -cnt,{a,b} });
		}
	}

	while (!pq.empty()) {
		double now_cnt = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if (check[a][b] == true) continue;

		bool same = is_same_parent(a, b);

		if (same == true) continue;

		double cnt = sqrt(pow(abs(coor[a].first - coor[b].first), 2) + pow(abs(coor[a].second - coor[b].second), 2));
		union_parent(a, b);
		ans += cnt;
	}

	printf("%.2f", ans);
	
	return 0;

}