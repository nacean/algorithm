#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include<queue>
using namespace std;

int dist[101][101];
vector<int> friends[101];

void dfs(int first, int now_node,int now_dist) {
    dist[first][now_node] = now_dist;

    for (int next_node : friends[now_node]) {
        if (dist[first][next_node] > now_dist + 1) {
            dfs(first, next_node, now_dist + 1);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = 987654321;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i,i,0);
    }

    int ans_node = 0;
    int ans_kevin = 987654321;

    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) {
            temp += dist[i][j];
        }
        if (temp < ans_kevin) {
            ans_node = i;
            ans_kevin = temp;
        }
    }

    cout << ans_node;

    return 0;
}