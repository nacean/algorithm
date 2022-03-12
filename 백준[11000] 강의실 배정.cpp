#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include<queue>
using namespace std;

vector<pair<int, int>> school;

priority_queue<int> last_time;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        school.push_back({ a,b });
    }

    sort(school.begin(), school.end());

    int ans = 1;

    last_time.push(-school[0].second);

    for (int i = 1; i < n; i++) {
        int start = school[i].first;
        int end = school[i].second;

        while (!last_time.empty()) {
            if (-last_time.top() <= start) last_time.pop();
            else break;
        }

        last_time.push(-end);

        ans = max(ans, (int)last_time.size());
    }

    cout << ans;

    return 0;
}