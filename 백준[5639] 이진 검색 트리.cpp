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

void postorder(int start, int stop) {
	if (start == stop) {
		cout << v[start] << "\n";
		return;
	}
	if (start > stop || stop >= (int)v.size() || start >= (int)v.size()) return;

	int now_node = v[start];

	int next_stop = start + 1;

	while (next_stop <= stop) {
		if (v[next_stop] > now_node) {
			break;
		}
		next_stop++;
	}

	postorder(start + 1, next_stop-1);
	postorder(next_stop, stop);
	cout << now_node << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	while (cin >> a) {
		v.push_back(a);
	}

	postorder(0, v.size() - 1);
	

	return 0;
}