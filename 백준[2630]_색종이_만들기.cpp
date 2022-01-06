#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#define ll long long

using namespace std;

int board[128][128];

int paper[2];

void func(int start_row, int start_col, int len) {
	bool is_correct = true;
	int color = board[start_row][start_col];

	for (int row = start_row; row < start_row + len; row++) {
		for (int col = start_col; col < start_col + len; col++) {
			if (board[row][col] != color) {
				is_correct = false;
				break;
			}
		}
		if (is_correct == false) break;
	}

	if (is_correct == true) {
		paper[color]++;
		return;
	}
	else {
		func(start_row, start_col, len / 2);
		func(start_row + len / 2, start_col, len / 2);
		func(start_row, start_col + len / 2, len / 2);
		func(start_row + len / 2, start_col + len / 2, len / 2);
	}

}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> board[row][col];
		}
	}

	func(0, 0, n);

	cout << paper[0] << endl << paper[1] << endl;

	return 0;
}
