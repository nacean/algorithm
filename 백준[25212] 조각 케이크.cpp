#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

int answer = 0;
int n; 

double arr[11];

void dfs(int now_pos, double added_num){
    if(now_pos == n){
        if(added_num >= 0.99 && added_num <= 1.01) answer++;
        return;
    }

    dfs(now_pos+1,added_num+1/arr[now_pos]);
    dfs(now_pos+1,added_num);

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++){
        double num; cin >> num;
        arr[i] = num;
    }

    dfs(0,0);

    cout << answer;

    return 0;
}