#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;
bool check[51];
vector<int> party[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    int knowing; cin >> knowing;

    for (int i = 0; i < knowing; i++) {
        int num; cin >> num;
        check[num] = true;
    }

    for (int i = 0; i < m; i++) {
        int fake = false;
        int cnt; cin >> cnt;

        for (int k = 0; k < cnt; k++) {
            int num; cin >> num;
            party[i].push_back(num);
            if (check[num]) fake = true;
        }

        if (fake) {
            for (int target : party[i]) {
                check[target] = true;
            }
        }
    }

    for (int i = 0; i < 50; i++) {
        for (int k = 0; k < m; k++) {

            int fake = false;
            for (int target : party[k]) {
                if (check[target]) fake = true;
            }

            if (fake) {
                for (int target : party[k]) {
                    check[target] = true;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int can_lie = true;

        for (int target : party[i]) {
            if (check[target]) can_lie = false;
        }

        if (can_lie) ans++;
    }

    cout << ans;

    return 0;
}