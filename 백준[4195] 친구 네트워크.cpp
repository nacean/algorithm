#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<utility>
#include<math.h>
#include<cstring>
#include<queue>
#include<map>
#define ll long long

using namespace std;

map<string, string> parent;
map<string, int> friendCnt;

string find_parent(string x) {
	if (parent[x] == x) {
		return x;
	}
	else return parent[x] = find_parent(parent[x]);
}

int union_parent(string a, string b) {
	string p_a = find_parent(a);
	string p_b = find_parent(b);

	if (p_a == p_b) return friendCnt[p_a];

	if (p_a < p_b)
	{
		parent[p_b] = p_a;
		int num = friendCnt[p_b];
		friendCnt[p_a] += num;
		return friendCnt[p_a];
	}
	else
	{
		parent[p_a] = p_b;
		int num = friendCnt[p_a];
		friendCnt[p_b] += num;
		return friendCnt[p_b];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		parent = {};
		friendCnt = {};

		for (int i = 0; i < n; i++) {
			string a, b; cin >> a >> b;
			if (!parent.count(a)) {
				parent[a] = a;
				friendCnt[a] = 1;
			}
			if (!parent.count(b)) {
				parent[b] = b;
				friendCnt[b] = 1;
			}

			int ans = union_parent(a, b);

			cout << ans << "\n";

		}
	}

	return 0;

}