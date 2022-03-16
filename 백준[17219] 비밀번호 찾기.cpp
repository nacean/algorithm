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

    map<string, string> m;
    
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        m[a] = b;
    }

    for (int i = 0; i < k; i++) {
        string a; cin >> a;
        cout << m[a] << "\n";
    }

    return 0;
}