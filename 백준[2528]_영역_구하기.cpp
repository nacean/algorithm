#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#define ll long long
#define max_val 987654321

using namespace std;
int m, n, k;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int board[100][100];
bool check[100][100];

int answer = 0;
vector<int> v;

void bfs(int row, int col)
{
	int size = 1;

	queue<pair<int, int>> q;

	check[row][col] = true;

	q.push({ row,col });

	while (!q.empty()) {

		int now_row = q.front().first;
		int now_col = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = now_row + dy[i];
			int next_col = now_col + dx[i];
			if (next_row < 0 || next_row >= m) continue;
			if (next_col < 0 || next_col >= n) continue;
			if (board[next_row][next_col] == 1 || check[next_row][next_col] == true) continue;

			check[next_row][next_col] = true;
			size++;
			q.push({ next_row, next_col });
		}

	}

	v.push_back(size);
	answer++;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		for (int row = b; row < d; row++) {
			for (int col = a; col < c; col++) {
				board[row][col] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == true || board[i][j] == 1) continue;
			bfs(i, j);
		}
	}

	cout << answer << "\n";

	sort(v.begin(), v.end());

	for (int num : v) {
		cout << num << " ";
	}
	return 0;
}
