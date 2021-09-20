#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

long long arr[1000001];
vector<long long> nodes;

long long init(int num, int start, int end) {
	if (start == end) {
		nodes[num] = arr[start];
		return nodes[num];
	}

	else {
		int mid = (start + end) / 2;
		nodes[num] = init(num * 2, start, mid) + init(num * 2 + 1, mid + 1, end);
		return nodes[num];
	}
}

void change_num(int start, int end, int now_node, int target, long long diff) {
	if (target < start || end < target) return;

	nodes[now_node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		change_num(start, mid, now_node * 2, target, diff);
		change_num(mid + 1, end, now_node * 2 + 1, target, diff);
	}
}

long long get_sum(int now_node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;

	else if (left <= start && end <= right) {
		return nodes[now_node];
	}

	else {
		int mid = (start + end) / 2;
		return get_sum(now_node * 2, start, mid, left, right) + get_sum(now_node * 2 + 1, mid + 1, end, left, right);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k; cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		long long num; cin >> num;
		arr[i] = num;
	}

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	nodes.resize(tree_size);
	init(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int a; cin >> a;

		if (a == 1) {
			int b;
			long long c;
			cin >> b >> c;
			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			change_num(0, n - 1, 1, b - 1, diff);
		}

		else if (a == 2) {
			int b, c; cin >> b >> c;
			cout << get_sum(1, 0, n - 1, b - 1, c - 1) << endl;
		}
	}


	return 0;
}
