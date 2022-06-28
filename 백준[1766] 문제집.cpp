#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int input[32001]; int n, m;
vector<int> then_go[32001];
vector<int> answer;
priority_queue <int> pq;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   cin >> n >> m;

    for(int i=0;i<m;i++){
        int first , then;
        cin >> first >> then;
        input[then]++;
        then_go[first].push_back(then);
    }

    for(int i=1;i<=n;i++){
        if(!input[i]){
            pq.push(-i);
        }
    }

    while(!pq.empty()){
        int now_num = -pq.top();
        answer.push_back(now_num);
        pq.pop();

        for(int next : then_go[now_num]){
            if(--input[next] == 0) pq.push(-next);
        }

    }

    for(int ans : answer){
        cout << ans << " ";
    }

    return 0;
}