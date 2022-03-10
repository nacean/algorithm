#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
using namespace std;

string board[100];
bool check[100][100];

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void dfs(int row, int col, int h, int w) {
    check[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int next_row = dy[i] + row;
        int next_col = dx[i] + col;

        if (next_row >= h || next_col >= w || next_row < 0 || next_col < 0)continue;
        if (!check[next_row][next_col] && board[next_row][next_col] == '#') dfs(next_row, next_col, h, w);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;

    while (tc--) {
        int h, w; cin >> h >> w;

        for (int i = 0; i < h; i++) {
            string s; cin >> s;
            board[i] = s;
            for (int j = 0; j < w; j++) {
                check[i][j] = false;
            }
        }

        int ans = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!check[i][j] && board[i][j] == '#') {
                    ans++;
                    dfs(i, j,h,w);
                }
            }
        }

        cout << ans << "\n";
    }


    return 0;
}