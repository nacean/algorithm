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

    int n; cin >> n;
    
    int ans = 4;

    for (int f = 225; f >=0; f--) {
        if (f * f > 50000) continue;
        if (f * f == n) {
            ans = 1;
            break;
        }
        for (int s = 225; s >=0; s--) {
            if (f * f + s * s > 50000) continue;
            if (f * f + s * s == n) {
                ans = min(ans, 2);
            }
            for (int t = 225; t >= 0; t--) {
                if (f * f + s * s + t * t > 50000) continue;
                if (f * f + s * s + t * t == n) {
                    ans = min(ans, 3);
                }
            }
        }
    }

    cout << ans;

    return 0;
}