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

bool isOut[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<pair<long long,int>> maxPQ;
    priority_queue<pair<long long,int>> minPQ;

    int t; cin >> t;

    while (t--) {
        maxPQ = {};
        minPQ = {};
        memset(isOut, false, sizeof(isOut));

        int n; cin >> n;

        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            if (c == 'I') {
                long long num; cin >> num;
                maxPQ.push({ num,i });
                minPQ.push({ -num,i });
            }
            else {
                long long num; cin >> num;

                while (!maxPQ.empty()) {
                    int temp = maxPQ.top().second;
                    if (isOut[temp]) maxPQ.pop();
                    else break;
                }
                while(!minPQ.empty()) {
                    int temp = minPQ.top().second;
                    if (isOut[temp]) minPQ.pop();
                    else break;
                }

                if (!maxPQ.empty()) {
                    if (num == -1) {
                        int temp = minPQ.top().second;
                        minPQ.pop();
                        isOut[temp] = true;
                    }
                    else {
                        int temp = maxPQ.top().second;
                        maxPQ.pop();
                        isOut[temp] = true;
                    }
                }
            }
        }
        while (!maxPQ.empty()) {
            int temp = maxPQ.top().second;
            if (isOut[temp]) maxPQ.pop();
            else break;
        }
        while (!minPQ.empty()) {
            int temp = minPQ.top().second;
            if (isOut[temp]) minPQ.pop();
            else break;
        }
        if (maxPQ.empty()) cout << "EMPTY\n";
        else cout << maxPQ.top().first << " " << -minPQ.top().first << "\n";
    }


    return 0;
}