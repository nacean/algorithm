#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
using namespace std;

int parent[10001];
bool check[10001];
vector<int> friend_list[10001];
vector<pair<int,int>> friend_cost;

int find_parent(int x) {
    if (x == parent[x]) return x;

    else return parent[x] = find_parent(parent[x]);
}

void union_parent(int a,int b) {
    int p_a = find_parent(a);
    int p_b = find_parent(b);

    if (p_a == p_b) return;

    if (p_a < p_b) {
        parent[p_b] = p_a;
        for (int friend_num : friend_list[p_b]) {
            friend_list[p_a].push_back(friend_num);
        }
    }
    else {
        parent[p_a] = p_b;
        for (int friend_num : friend_list[p_a]) {
            friend_list[p_b].push_back(friend_num);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int cost; cin >> cost;
        friend_cost.push_back({ cost,i });
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        friend_list[i].push_back(i);
    }

    sort(friend_cost.begin(), friend_cost.end());

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        union_parent(a, b);
    }

    int ans = k;

    for (int i = 0; i < (int)friend_cost.size(); i++) {
        if (check[friend_cost[i].second] == true) continue;
        
        k -= friend_cost[i].first;

        if (k < 0) {
            cout << "Oh no";
            return 0 ;
        }

        for (int num : friend_list[find_parent(friend_cost[i].second)]) {
            check[num] = true;
        }
    }

    cout << ans - k;

    return 0;
}