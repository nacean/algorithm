#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include<queue>
using namespace std;

bool brokenBtn[10];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        brokenBtn[num] = true;
    }
    
    int ans = abs(n - 100);

    for (int i = 0; i <= 1000000; i++) {
        string s = to_string(i);
        bool cannot = false;
        for (int i = 0; i < s.size(); i++) {
            if (brokenBtn[s[i] - '0']) {
                cannot = true;
                break;
            }
        }
        if (cannot == true) continue;

        ans = min(ans, abs(n - i) + (int)s.size());
    }
    

    cout << ans;

    return 0;
}