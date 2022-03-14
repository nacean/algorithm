#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include<queue>
using namespace std;

set<string> names;
vector<string> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        string s; cin >> s;
        if (names.count(s)) ans.push_back(s);
        else names.insert(s);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (string temp : ans) {
        cout << temp << "\n";
    }

    return 0;
}