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

long long answer = -1;

long long dx[4] = { 1,0,-1,0 };
long long dy[4] = { 0,-1,0,1 };


/*long long get_dist(vector<pair<long long, long long>> points, vector<pair<long long, long long>> ggok, long long all_added, vector<int> capture_pos, int now_num)
{
	long long min_dist = -1;

	if (now_num == 8) return all_added;

	for (int i = 0; i < 8; i++)
	{
		if (capture_pos[i] == -1)
		{
			capture_pos[i] = now_num;
			long long new_all_added = all_added + abs(points[now_num].first - ggok[i].first) + abs(points[now_num].second + ggok[i].second);
			long long temp_dist = get_dist(points, ggok, new_all_added, capture_pos, now_num + 1);
			if (min_dist == -1) min_dist = temp_dist;
			else min_dist = min(min_dist, temp_dist);
			capture_pos[i] = -1;
		}
	}

	return min_dist;
}*/

/*
long long get_dist(vector<pair<long long, long long>> points, vector<pair<long long, long long>> ggok, long long all_added, vector<int> capture_pos, int now_num)
{
	long long last_added = -1;

	long long min_dist = -1;
	vector<int> min_list;

	if (now_num == 8) return all_added;

	//각 꼭지에 대해 최소거리 조사
	for (int i = 0; i < 8; i++)
	{
		//접근 가능
		if (capture_pos[i] == -1)
		{
			long long temp_dist = abs(points[now_num].first - ggok[i].first) + abs(points[now_num].second + ggok[i].second);
			if (min_dist == -1)
			{
				min_dist = temp_dist;
				min_list.push_back(i);
			}
			else if (min_dist == temp_dist)
			{
				min_list.push_back(i);
			}
			else if (min_dist > temp_dist)
			{
				min_dist = temp_dist;
				min_list.clear();
				min_list.push_back(i);
			}
		}
	}

	if (min_list.size() == 1)
	{
		capture_pos[min_list[0]] = 1;

		if (last_added == -1) last_added = get_dist(points, ggok, all_added + min_dist, capture_pos, now_num + 1);
		else last_added = min(last_added, get_dist(points, ggok, all_added + min_dist, capture_pos, now_num + 1));
	}
	else if (min_list.size() >= 2)
	{
		for (int temp_num : min_list)
		{
			capture_pos[temp_num] = 1;
			get_dist(points, ggok, all_added + min_dist, capture_pos, now_num + 1);

			if (last_added == -1) last_added = get_dist(points, ggok, all_added + min_dist, capture_pos, now_num + 1);
			else last_added = min(last_added, get_dist(points, ggok, all_added + min_dist, capture_pos, now_num + 1));

			capture_pos[temp_num] = -1;
		}
	}

	return last_added;
}
*/

long long get_dist(vector<pair<long long, long long>> points, vector<pair<long long, long long>> ggok)
{
	long long min_dist = -1;
	vector<int> ggok_pos;
	for (int i = 0; i < 8; i++) ggok_pos.push_back(i);

	do {
		long long temp_dist = 0;
		for (int i = 0; i <= 7; i++)
		{
			temp_dist += abs(points[i].first - ggok[ggok_pos[i]].first) + abs(points[i].second + ggok[ggok_pos[i]].second);
		}

		if (min_dist == -1) min_dist = temp_dist;
		else min_dist = min(min_dist, temp_dist);


	} while (next_permutation(ggok_pos.begin(), ggok_pos.end()));

	return min_dist;
}

void func(vector<pair<long long, long long>> points, vector<pair<long long, long long>> ggok)
{
	vector<int> capture_pos;
	for (int i = 0; i < 8; i++) capture_pos.push_back(-1);

	long long temp_dist = get_dist(points, ggok);

	if (answer == -1) answer = temp_dist;
	else answer = min(answer, temp_dist);


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++) ggok[j] = { ggok[j].first + dx[i],ggok[j].second + dy[i] };

		temp_dist = get_dist(points, ggok);

		if (temp_dist < answer)
		{
			answer = temp_dist;
			func(points, ggok);
		}

		for (int j = 0; j < 8; j++) ggok[j] = { ggok[j].first - dx[i],ggok[j].second - dy[i] };

	}
}


int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		long long K; cin >> K;
		vector<pair<long long,long long>> points;
		vector<pair<long long,long long>> ggok;
		long long center_x = 0;
		long long center_y = 0;

		for (int i = 1; i <= 8; i++)
		{
			long long x; long long y;
			cin >> x >> y;
			points.push_back({ x,y });
			center_x += x;
			center_y += y;
		}

		center_x /= 8;
		center_y /= 8;
		long long p0_x = center_x - K - K / 2;
		long long p0_y = center_y - K / 2;
		ggok.push_back({ p0_x,p0_y });
		ggok.push_back({ p0_x,p0_y + K });
		ggok.push_back({ p0_x + K,p0_y + 2 * K });
		ggok.push_back({ p0_x + 2 * K, p0_y + 2 * K });
		ggok.push_back({ p0_x + 3 * K, p0_y + K });
		ggok.push_back({ p0_x + 3 * K , p0_y });
		ggok.push_back({ p0_x + 2 * K, p0_y - K });
		ggok.push_back({ p0_x + K, p0_y - K });

		func(points, ggok);

		cout << "Case #" << test_case + 1 << endl;
		cout << answer << endl;

		answer = -1;
	}

	return 0;
}