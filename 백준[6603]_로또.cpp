#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

void dfs(vector<int> v, vector<int> lotto, int pos) {

	if (lotto.size() == 6) {
		for (int num : lotto) {
			cout << num << " ";
		}
		cout << endl;
		return;
	}

	if (pos == v.size()) return;

	for (int i = pos; i < v.size(); i++) {
		lotto.push_back(v[i]);
		dfs(v, lotto, i + 1);
		lotto.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int k; cin >> k;
		
		if (k == 0) break;

		vector<int> v;

		for (int i = 0; i < k; i++) {
			int num; cin >> num;
			v.push_back(num);
		}

		vector<int> lotto;
		dfs(v, lotto, 0);
		cout << endl;
	}

	
	return 0;
}