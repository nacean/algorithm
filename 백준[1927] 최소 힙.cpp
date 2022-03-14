#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include<queue>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (num == 0) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << -pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(-num);
        }
    }


    return 0;
}