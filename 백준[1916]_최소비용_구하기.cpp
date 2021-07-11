#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>

#define MAX 987654321

using namespace std;

int main()
{
	int town_cnt, bus_cnt; scanf("%d %d", &town_cnt, &bus_cnt);

	//pair(도착지점, 비용)
	vector<pair<int,int>> town_and_go[1001];

	for (int i = 0; i < bus_cnt; i++)
	{
		int start_town, stop_town, bus_cost; scanf("%d %d %d", &start_town, &stop_town, &bus_cost);
		town_and_go[start_town].push_back({ stop_town,bus_cost });
	}

	int start_town, stop_town;
	scanf("%d %d", &start_town, &stop_town);

	int dist[1001]; //각 노드에서의 최단 거리
	fill(dist, dist + 1001, MAX);
	dist[start_town] = 0; //시작 도시는 0으로 초기화

	//pair(노드 번호, 노드 까지의 최단 cost)
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	pq.push({ start_town,0 });

	while (!pq.empty())
	{
		int now_town_num = pq.top().first;
		int now_cost = pq.top().second; //최소를 top으로 해야하기에 음수를 넣어줌!
		pq.pop();

		if (dist[now_town_num] < now_cost) continue; //pq에 과거에 넣은 것보다 최근 갱신한 것이 더 최단거리 일 수 있음

		for (int i = 0; i < town_and_go[now_town_num].size(); i++)
		{
			int next_town_num = town_and_go[now_town_num][i].first;
			int next_cost = town_and_go[now_town_num][i].second;

			//만약 현재cost + 간선 비중 < 다음 갈 최단비용 이면 갱신 후 큐에 넣어줌
			if (now_cost + next_cost < dist[next_town_num])
			{
				dist[next_town_num] = now_cost + next_cost;
				pq.push({ next_town_num,dist[next_town_num] });
			}
		}
	}

	printf("%d\n", dist[stop_town]);

	return 0;
}