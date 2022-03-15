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
vector<pair<pair<int, int>, int>> rotten;
vector<pair<pair<int, int>,int>> normal;

int dx[6] = { 0,0,1,0,-1,0 };
int dy[6] = { 0,0,0,-1,0,1 };
int dz[6] = { 1,-1,0,0,0,0 };

int ans = 0;
int box[100][100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, h; cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int num; cin >> num;
                box[row][col][i] = num;
                if (num == 1) {
                    rotten.push_back({ {row,col},i });
                }
                else if (num == 0) normal.push_back({ { row,col }, i });
            }
        }
    }


    int normal_size = normal.size();

    while (normal_size != 0) {

        int now_size = rotten.size();

        vector<pair<pair<int, int>, int>> new_rotten;
        int change_cnt = 0;
        ans++;
        for (int i = 0; i < now_size; i++) {
            for (int k = 0; k < 6; k++) {
                int next_row = rotten[i].first.first+dy[k];
                int next_col = rotten[i].first.second+dx[k];
                int next_h = rotten[i].second+dz[k];

                if (next_row < 0 || next_col < 0 || next_h < 0 || next_row >= n || next_col >= m || next_h >= h) continue;

                if (box[next_row][next_col][next_h] == 0) {
                    new_rotten.push_back({ {next_row,next_col }, next_h});
                    box[next_row][next_col][next_h] = 1;
                    change_cnt++;
                    normal_size--;
                }
            }
        }

        if (change_cnt == 0) break;

        rotten = new_rotten;
    }

    if (normal_size != 0) cout << -1;
    else cout << ans;
    return 0;
}