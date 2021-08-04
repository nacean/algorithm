#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>

using namespace std;

int kill_enemy = 0;

int board_col, board_row, dist;



void play_game(int first_bow, int second_bow, int third_bow, vector<pair<int, int>> enemy_list, vector<bool> game_out)
{
	int now_kill = 0;

	

	for (int col_plus = 0; col_plus < board_col; col_plus++)
	{
		//각각 궁수가 없앨 수 있는 적의 위치, 적까지의 거리, 그때 enemy_list의 i 값
		pair<int, int> first_kill = { 99,99 };
		int first_kill_dist = 9999;
		int first_i = -1;

		pair<int, int> second_kill = { 99,99 };
		int second_kill_dist = 9999;
		int second_i = -1;

		pair<int, int> third_kill = { 99,99 };
		int third_kill_dist = 9999;
		int third_i = -1;

		for (int i = 0; i < enemy_list.size(); i++)
		{
			//적의 위치
			int enemy_col = enemy_list[i].second;
			int enemy_row = enemy_list[i].first;

			//만약 보드 바깥으로 벗어나면 continue
			if (enemy_col > board_col) continue;

			//각각 거리를 계산
			int first_enemy_and_bow_dist = abs(enemy_col - (board_col + 1)) + abs(enemy_row - (first_bow));
			int second_enemy_and_bow_dist = abs(enemy_col - (board_col + 1)) + abs(enemy_row - (second_bow));
			int third_enemy_and_bow_dist = abs(enemy_col - (board_col + 1)) + abs(enemy_row - (third_bow));

			//갱신하려는 거리가 더 작고, 아직 죽지 않았을 경우 갱신해줌
			if (first_kill_dist > first_enemy_and_bow_dist && game_out[i] == false)
			{
				first_kill = { enemy_col,enemy_row };
				first_kill_dist = first_enemy_and_bow_dist;
				first_i = i;
			}
			if (second_kill_dist > second_enemy_and_bow_dist && game_out[i] == false)
			{
				second_kill = { enemy_col,enemy_row };
				second_kill_dist = second_enemy_and_bow_dist;
				second_i = i;
			}
			if (third_kill_dist > third_enemy_and_bow_dist && game_out[i] == false)
			{
				third_kill = { enemy_col,enemy_row };
				third_kill_dist = third_enemy_and_bow_dist;
				third_i = i;
			}

			//적들을 한칸씩 col 값을 이동시킴
			enemy_list[i].second += 1;
		}

		//dist가 쓰레기 값이 아니고, 제한된 거리 이하이면 죽임
		if (first_kill_dist != 9999 && dist >= first_kill_dist) game_out[first_i] = true;
		if (second_kill_dist != 9999 && dist >= second_kill_dist) game_out[second_i] = true;
		if (third_kill_dist != 9999 && dist >= third_kill_dist) game_out[third_i] = true;
	}

	//죽은 enemy 개수 계산
	for (bool killed : game_out)
	{
		if (killed == true) now_kill++;
	}

	if (kill_enemy < now_kill) kill_enemy = now_kill;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> enemy_list; //적들의 col,row를 저장
	vector<bool> game_out; //적들이 게임에 아웃 당했는가

	cin >> board_col >> board_row >> dist;

	for (int col = 1; col <= board_col; col++)
	{
		for (int row = 1; row <= board_row; row++)
		{
			int num; cin >> num;
			if (num == 1)
			{
				//맨 왼쪽부터 우선순위기에, sort하기 위해 row를 first로 저장
				enemy_list.push_back({ row,col });
				game_out.push_back(false);
			}
		}
	}

	//맨 왼쪽은 숫자가 작기에, sort로 미리 순서를 정함
	sort(enemy_list.begin(), enemy_list.end());

	//3중포문으로 궁수들의 row값을 뽑고(col값은 정해져있음) 함수 실행
	for (int first_bow = 1; first_bow <= board_row - 2; first_bow++)
	{
		for (int second_bow = first_bow + 1; second_bow <= board_row - 1; second_bow++)
		{
			for (int third_bow = second_bow + 1; third_bow <= board_row; third_bow++)
			{
				play_game(first_bow, second_bow, third_bow, enemy_list, game_out);
			}
		}
	}

	cout << kill_enemy;

	return 0;
}