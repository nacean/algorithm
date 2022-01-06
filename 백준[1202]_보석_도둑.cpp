#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#define ll long long

using namespace std;

multiset<int> bag;
vector<pair<int, int>> crystal;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int m,v; // m == weight, v == cost
		cin >> m >> v;
		crystal.push_back({ -v,m });
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}

	sort(crystal.begin(), crystal.end());

	ll answer = 0;

	for (auto iter = crystal.begin(); iter != crystal.end(); iter++) {

		if (bag.size() == 0) break;

		int crystal_value = -((*iter).first);
		int crystal_weight = (*iter).second;

		auto bag_iter = bag.lower_bound(crystal_weight);

		if (bag_iter != bag.end()) {
			answer += crystal_value;
			bag.erase(bag_iter);
		}

	}

	cout << answer << endl;

	return 0;
}
