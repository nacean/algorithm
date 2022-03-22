#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define MAX_VALUE 987654321

using namespace std;
vector<int> v;
int n, m;

void func(int pos, int cnt,vector<int> bucket) {
	if ((int)bucket.size() == m) {
		for (int num : bucket) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}
	else if (cnt >= m) return;
	else {
		for (int i = pos; i < n; i++) {
			vector<int> new_b = bucket;
			new_b.push_back(v[i]);
			func(i, cnt + 1, new_b);
			func(i + 1, cnt + 1, bucket);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());

	vector<int> bucket;

	func(0, 0, bucket);

	return 0;
}