#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>

using namespace std;

//노드 번호에서 나가는 노드
vector<int> get_out[1001];

//노드 번호로 들어오는 노드
vector<int> get_in[1001];

//들어오는 노드 개수 - 위상정렬 할때 사용
int in_count[1001];

//각 노드의 strahler 번호
int strahler[1001];

//그 노드의 들어오는 노드 가 몇개인가?? 2개이상이면 i+1
int how_many_stra[1001];


void bfs(vector<int> start_node) {

	queue<int> q;

	for (int node_num : start_node)
	{
		q.push(node_num);
	}

	while (!q.empty())
	{
		//검사할 노드
		int now_node_num = q.front();
		int now_strahler = strahler[now_node_num];
		if (how_many_stra[now_node_num] >= 2)
		{
			now_strahler += 1;
			strahler[now_node_num] += 1;
		}
		
		q.pop();

		for (int next_node_num : get_out[now_node_num])
		{
			in_count[next_node_num] -= 1;

			if(in_count[next_node_num] == 0) q.push(next_node_num);

			//만약 아무것도 안들어왔으면 바로 strahler와 개수를 초기화해준다
			if (strahler[next_node_num] == 0)
			{
				strahler[next_node_num] = now_strahler;
				how_many_stra[next_node_num] = 1;
			}
			//만약 같은 strahler 번호가 들어올경우 개수증가
			else if (strahler[next_node_num] == now_strahler)
			{
				how_many_stra[next_node_num] += 1;
			}
			//만약 strahler번호가 더 클경우 초기화 후 개수 1
			else if (strahler[next_node_num] < now_strahler)
			{
				strahler[next_node_num] = now_strahler;
				how_many_stra[next_node_num] = 1;
			}

		}

	}

	

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;

	for (int i = 0; i < t; i++)
	{
		int test_num, node_cnt, line_cnt;
		cin >> test_num >> node_cnt >> line_cnt;

		for (int j = 0; j < line_cnt; j++)
		{
			int start, end; cin >> start >> end;
			get_out[start].push_back(end);
			get_in[end].push_back(start);
			in_count[end]++;
		}

		vector<int> start_node;

		for (int j = 1; j < node_cnt; j++)
		{
			//들어오는 노드가 없으면 시작노드
			if (get_in[j].size() == 0)
			{
				strahler[j] = 1;
				start_node.push_back(j);
			}
		}

		bfs(start_node);

		cout << test_num << " " << strahler[node_cnt] << endl;

		for (int j = 1; j <= node_cnt; j++)
		{
			get_out[j].clear();
			get_in[j].clear();
			strahler[j] = 0;
			how_many_stra[j] = 0;
			in_count[j] = 0;
		}
	}


	return 0;
}