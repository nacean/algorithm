#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include<queue>
using namespace std;

vector<pair<int,int>> x[3];
priority_queue<pair<int, pair<int, int>>> road;

int n;
int parent[100001];
long long ans = 0;

int find_parent(int x) {
    if (parent[x] == x) return x;

    else return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
    int p_a = find_parent(a);
    int p_b = find_parent(b);

    if (p_b < p_a) swap(p_a, p_b);

    parent[p_b] = p_a;
}

bool same_parent(int a, int b) {
    int p_a = find_parent(a);
    int p_b = find_parent(b);

    if (p_a == p_b) return true;
    else return false;
}

void mst() {

    while (!road.empty()) {
        int now_dist = -road.top().first;
        int a = road.top().second.second;
        int b = road.top().second.first;
        road.pop();

        if (!same_parent(a, b)) {
            union_parent(a, b);
            ans += now_dist;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        x[0].push_back({ a,i });
        x[1].push_back({ b,i });
        x[2].push_back({ c,i });
        parent[i] = i;
    }
    for (int i = 0; i < 3; i++) {
        sort(x[i].begin(), x[i].end());
        for (int pos = 1; pos < x[i].size(); pos++) {
            int dist = abs(x[i][pos].first - x[i][pos - 1].first);
            int left = x[i][pos].second;
            int right = x[i][pos - 1].second;

            road.push({ -dist,{left,right} });
        }
    }

    mst();

    cout << ans;


    return 0;
}