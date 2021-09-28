#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

bool answer = false;

void dfs(string& s, string& t, char first, char sec, int spos, int tpos, int cnt) {
	if (tpos == t.size() && cnt == 2) {
		answer = true;
		return;
	}
	if (spos < s.size()) {
		if (s[spos] == t[tpos]) dfs(s, t, first, sec, spos + 1, tpos + 1, cnt);
	}

	if (cnt == 0) {
		//첫번째껄 넣을 수 있으면
		if (t[tpos] == first) {
			dfs(s, t, first, sec, spos, tpos + 1, cnt + 1);
		}
	}
	if (cnt == 1) {
		//두번쨰꺼
		if (t[tpos] == sec) {
			dfs(s, t, first, sec, spos, tpos + 1, cnt + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	string s, t; cin >> s >> t;
	int i, j; cin >> i >> j;

	char first = s[i];
	char sec = s[j];

	string new_s;
	for (int k = 0; k < s.size(); k++) {
		if (k != i && k != j) new_s.push_back(s[k]);
	}

	dfs(new_s, t, first, sec, 0, 0, 0);

	if (answer == false) {
		cout << "NO" << endl;
	}

	else {
		cout << "YES" << endl;
	}

	return 0;
}
