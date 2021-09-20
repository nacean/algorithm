#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int answer = 0;

void dfs(vector<int>& v, int s, int all_added, int pos) {
	if (pos == v.size()) return;

	for (int i = pos; i < v.size(); i++) {
		int temp_s = all_added + v[i];

		if (temp_s == s) answer++;

		dfs(v, s,temp_s, i + 1);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s; cin >> n >> s;

	vector<int>v;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	dfs(v, s,0,0);

	cout << answer;

	return 0;
}