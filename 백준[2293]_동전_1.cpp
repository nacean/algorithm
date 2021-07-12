#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>

#define MAX 987654321

using namespace std;


//(coin 번호, 총합 금액)
int arr[100001];

int main()
{
	int coin_cnt, target_won; scanf("%d %d", &coin_cnt, &target_won);
	vector<int> coins;

	for (int i = 0; i < coin_cnt; i++)
	{
		int num; scanf("%d", &num);
		coins.push_back(num);
	}

	//하나씩 동전을 추가할때마다 나오는 경우를 dp로 점점 저장해준다
	for (int now = 0; now < coins.size(); now++)
	{
		//지금부터 계산하려는 동전의 값에 경우의 수 1을 넣는다
		int coin = coins[now];
		arr[coin] += 1;

		// 이번에 새로 동전을 넣은 경우의수 + 이전 동전으로만 가능한 경우의 수
		for (int now_won = 1; now_won <= target_won; now_won++)
		{
			if (now_won - coin >= 0) arr[now_won] += arr[now_won - coin];
		}
	}

	printf("%d\n", arr[target_won]);
	
	return 0;
}