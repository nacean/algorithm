#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

int arr[100001];
int dp[100001];
int bucket[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int added = 0;

    for (int i = 1; i <= m; i++) added += arr[i];

    bucket[m] = added;
    dp[m] = added;

    int ans = added;

    for (int i = m + 1; i <= n; i++) {
        bucket[i] = bucket[i-1] - arr[i - m] + arr[i];
    }

    for (int i = m + 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], bucket[i]);
        ans = max(dp[i], ans);
    }

    if (ans < 0) ans = 0;

    cout << ans;

    return 0;
}