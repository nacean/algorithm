#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin >> n >> k;

	vector<int> sensor;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		sensor.push_back(num);
	}

	sort(sensor.begin(), sensor.end());

	int answer = sensor.back() - sensor.front();

	vector<int> gab;

	for (int i = 1; i < n; i++) {
		gab.push_back(sensor[i] - sensor[i - 1]);
	}

	sort(gab.begin(), gab.end());

	k -= 1;

	for (int i = 0; i < k && (int)gab.size()-1-i >= 0; i++) {
		int num = (int)gab.size() - i - 1;
		answer -= gab[num];
	}

	cout << answer << endl;
	
	return 0;
}
