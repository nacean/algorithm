#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<set>
using namespace std;

int board[9][9];
int get_answer = false;
unordered_set<int> bigbox[3][3];
unordered_set<int> rowline[9];
unordered_set<int> colline[9];

void dfs(vector<pair<int, int>> &blanks,int pos) {
	if (get_answer == true) return;

	if (pos == blanks.size()) {
		get_answer = true;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		return;
	}

	int now_row = blanks[pos].first;
	int now_col = blanks[pos].second;

	for (int i = 1; i <= 9; i++) {
		if (bigbox[now_row / 3][now_col / 3].count(i) == 0 && rowline[now_row].count(i) == 0 && colline[now_col].count(i) == 0) { //만약 전부 없으면 넣기

			bigbox[now_row / 3][now_col / 3].insert(i);
			rowline[now_row].insert(i);
			colline[now_col].insert(i);
			board[now_row][now_col] = i;

			dfs(blanks, pos + 1);

			bigbox[now_row / 3][now_col / 3].erase(i);
			rowline[now_row].erase(i);
			colline[now_col].erase(i);
			board[now_row][now_col] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> blanks;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int num; cin >> num;
			if (num == 0) blanks.push_back({ i,j });
			else {
				bigbox[i / 3][j / 3].insert(num);
				rowline[i].insert(num);
				colline[j].insert(num);
			}
			board[i][j] = num;
		}
	}

	dfs(blanks, 0);
	

	return 0;
}