/*#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	return 0;
}
*/

/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string.h>
using namespace std;

long long board[601][601];

int N, K;

long long func_point(long long center_y, long long center_x)
{
	long long temp_point = 0;

	long long left_x = center_x - K + 1;
	long long right_x = center_x + K - 1;

	long long up_y = center_y;
	long long down_y = center_y;

	while (left_x <= right_x)
	{
		for (long long now_x = left_x; now_x <= right_x; now_x++)
		{
			//곱해줄 보너스 = K - 길이
			long long x_dist = center_x - now_x;
			if (x_dist < 0) x_dist = 0 - x_dist;
			long long y_dist = center_y - up_y;
			if (y_dist < 0) y_dist = 0 - y_dist;
			long long dist = x_dist + y_dist;
			long long mult_num = K - dist;

			//만약 보드안에 위치한다면 점수 추가
			if (up_y >= 1 && up_y <= N && now_x >= 1 && now_x <= N) temp_point += mult_num * board[up_y][now_x];

			//맨 중앙은 한번만
			if (up_y == down_y) continue;
			if (down_y >= 1 && down_y <= N && now_x >= 1 && now_x <= N) temp_point += mult_num * board[down_y][now_x];
		}

		//점 이동
		left_x++;
		right_x--;
		up_y++;
		down_y--;
	}

	return temp_point;
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		 cin >> N >> K;

		long long answer = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> board[i][j];
			}
		}

		for (long long center_y = -K + 1; center_y <= N + K - 1; center_y++)
		{
			for (long long center_x = -K + 1; center_x <= N + K - 1; center_x++)
			{
				answer = max(answer, func_point(center_y, center_x));
			}
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << answer << endl;
	}

	return 0;
}