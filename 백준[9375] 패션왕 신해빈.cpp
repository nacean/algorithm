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
        int ans = 0;
        map<string, int> m;

        int n; cin >> n;

        for (int i = 0; i < n; i++) {
            string a, b; cin >> a >> b;
            m[b] += 1;
        }

        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (ans == 0) ans = (*iter).second + 1;
            else ans *= ((*iter).second + 1);
        }

        if (ans == 0) cout << 0 << "\n";
        else cout << ans - 1 << "\n";
    }


    return 0;
}