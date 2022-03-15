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

    priority_queue < pair<int, int>> pq;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;

        if (num != 0) {
            int jeol = num < 0 ? num : -num;
            pq.push({ jeol,-num });
        }
        else {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << -pq.top().second << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}