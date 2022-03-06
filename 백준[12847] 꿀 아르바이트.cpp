#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    long long ans = 0;
    int n,m; cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        long long num; cin >> num;
        v.push_back(num);
    }

    int start = 0;
    int end = 0;
    long long charge = 0;

    for (end; end < m; end++) {
        charge += v[end];
    }
    end--;
    ans = charge;

    while (++end < v.size()) {
        charge -= v[start++];
        charge += v[end];
        ans = max(charge, ans);
    }


    cout << ans;

    return 0;
}