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
    vector<int > v;
    priority_queue<int> pq;
    map<int, int> m;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
        pq.push(-num);
    }

    int postNum = -pq.top();
    int cnt = 0;
    m[postNum] = cnt;

    while (!pq.empty()) {
        int now_num = -pq.top();
        pq.pop();
        if (postNum == now_num) continue;

        m[now_num] = ++cnt;
        postNum = now_num;
    }

    for (int temp : v) {
        cout << m[temp] << " ";
    }

    return 0;
}