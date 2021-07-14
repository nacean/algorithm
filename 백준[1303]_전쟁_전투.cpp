#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>

#define MAX 987654321

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int board_col, board_row;
vector<string> board;
int check[100][100];
int white = 0;
int blue = 0;

void bfs(int col, int row)
{
	queue<pair<int,int>> q;
	check[col][row] = 1;
	int temp = 1;
	char color = board[col][row];
	q.push({ col,row });

	while (!q.empty())
	{
		int now_col = q.front().first;
		int now_row = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_col = now_col + dy[i];
			int next_row = now_row + dx[i];

			if (next_col < 0 || next_col >= board_col) continue;
			if (next_row < 0 || next_row >= board_row) continue;
			if (board[next_col][next_row] != color) continue;
			
			if (check[next_col][next_row] == 0)
			{
				check[next_col][next_row] = 1;
				q.push({ next_col,next_row });
				temp++;
			}

		}
	}

	if (color == 'W') white += temp * temp;
	else blue += temp * temp;
}



int main()
{
	 scanf("%d %d", &board_row, &board_col);

	for (int i = 0; i < board_col; i++)
	{
		string s;
		cin >> s;
		board.push_back(s);
	}

	for (int i = 0; i < board_col; i++)
	{
		for (int j = 0; j < board_row; j++)
		{
			if (check[i][j] == 0)
				bfs(i, j);
		}
	}

	printf("%d %d\n", white, blue);

	return 0;
}