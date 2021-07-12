#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>

#define MAX 987654321

using namespace std;

//(몇번째 동전, 총 금액)
int arr[100][10001];

int main()
{
	int coin_cnt, target_won; scanf("%d %d", &coin_cnt, &target_won);
	vector<int> coins;

	for (int i = 0; i < coin_cnt; i++)
	{
		int num; scanf("%d", &num);
		coins.push_back(num);
		arr[0][num] = 1;
	}

	for (int i = 0; i < coin_cnt; i++)
	{
		for (int j = 1; j <= target_won; j++)
		{
			arr[i][j] = -1;
		}
	}

	for (int i = coins[0]; i <= target_won; i = i + coins[0])
	{
		arr[0][i] = arr[0][i - coins[0]] + 1;
	}

	for (int now_num = 1; now_num < coin_cnt; now_num++)
	{
		int coin = coins[now_num];

		for (int price = 0; price <= target_won; price++)
		{
			int down_cnt = arr[now_num - 1][price];
			if (price - coin < 0) arr[now_num][price] = down_cnt;
			else
			{
				int left_cnt = arr[now_num][price - coin];

				if (down_cnt == -1 && left_cnt != -1) arr[now_num][price] = left_cnt + 1;
				else if (left_cnt != -1 && left_cnt + 1 < down_cnt) arr[now_num][price] = left_cnt + 1;
				else arr[now_num][price] = down_cnt;
				
			}
		}
	}

	printf("%d\n", arr[coin_cnt-1][target_won]);
	
	return 0;
}