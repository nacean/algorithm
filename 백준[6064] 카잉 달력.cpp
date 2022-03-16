#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while (t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;

        if (n < m) {
            swap(n, m);
            swap(x, y);
        }

        int ans = -1;

        int cnt = x;

        int find_X = x;
        int find_Y = (cnt-1) % m + 1;

        for (int i = 0; i <= 50000; i++) {
            if (find_X == x && find_Y == y) {
                ans = cnt;
                break;
            }
            
            cnt += n;
            find_Y = (find_Y + n - 1) % m + 1;
        }

        cout << ans << "\n";
    }


    return 0;
}