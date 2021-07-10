#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>

using namespace std;

int find_plug(vector<int>is_plugged, int now_to_plug)
{
	bool plug_ok = false;
	for (int past_plug : is_plugged)
	{
		if (past_plug == now_to_plug) plug_ok = true;
	}

	return plug_ok;
}

int main()
{
	int hole, use_cnt; scanf("%d %d", &hole, &use_cnt);

	//만약 전기기구보다 플러그 개수가 더 크면 0
	if (hole >= use_cnt)
	{
		printf("0");
		return 0;
	}

	vector<int>use;

	for (int i = 0; i < use_cnt; i++)
	{
		int num; scanf("%d", &num);
		use.push_back(num);
	}

	//꽂혀있는 전기기구 번호 모음
	vector<int> is_plugged;

	//미리 플러그 꽂아둠
	is_plugged.push_back(use[0]);

	int answer = 0;

	//전기기구를 순서대로 꽂는다
	for (int i = 1; i < use_cnt; i++)
	{
		int now_to_plug = use[i];

		//만약 이미 꽂혀있으면 건너뛴다
		if (find_plug(is_plugged, now_to_plug)) continue;

		//만약 플러그 개수가 남으면, 그대로 꽂는다
		if (is_plugged.size() < hole)
		{
			is_plugged.push_back(use[i]);
			continue;
		}

		//아예 안나타나거나 뒤에있을 수록 바꾼다
		int* how_far = new int[101];
		for (int k = 0; k < 100; k++) how_far[k] = 0;

		for (int k = i + 1; k < use_cnt; k++)
		{
			int future_plug = use[k]; //미래에 사용할 전기기구

			if (how_far[future_plug] != 0) continue; // 가장 최근에 사용할 기록만 남긴다

			how_far[future_plug] = k; //전기기구 번호는 k번 때 사용할 것이다
		}
		
		int what_to_change = 0; //우선순위가 없으면 맨처음껄 바꾼다

		for (int k = 0; k < is_plugged.size(); k++)
		{
			int plug_num = is_plugged[k]; //꽂혀있는 플러그의 전기기구의 번호
			
			//만약 뒤에 전혀 사용하지 않는다면 선택한다
			if (how_far[plug_num] == 0)
			{
				what_to_change = k;
			}

			//사용한다면, 가장 뒤에 사용하는거를 교체한다
			else
			{
				int pick_to_change = is_plugged[what_to_change];

				if (how_far[pick_to_change] == 0) continue; //만약 이미 고른게 한번도 쓰지 않는 것이라면, 건너뛴다

				if (how_far[pick_to_change] < how_far[plug_num]) what_to_change = k;
			}
		}

		//is_plugged에서 삭제 후 현재 넣을 플러그 추가 후 변경횟수 1회 증가
		is_plugged.erase(is_plugged.begin() + what_to_change);
		is_plugged.push_back(now_to_plug);
		answer++;

		delete[] how_far;
	}

	printf("%d", answer);


	return 0;
}