#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <queue>

#define MAX 987654321

using namespace std;


//(coin ��ȣ, ���� �ݾ�)
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

	//�ϳ��� ������ �߰��Ҷ����� ������ ��츦 dp�� ���� �������ش�
	for (int now = 0; now < coins.size(); now++)
	{
		//���ݺ��� ����Ϸ��� ������ ���� ����� �� 1�� �ִ´�
		int coin = coins[now];
		arr[coin] += 1;

		// �̹��� ���� ������ ���� ����Ǽ� + ���� �������θ� ������ ����� ��
		for (int now_won = 1; now_won <= target_won; now_won++)
		{
			if (now_won - coin >= 0) arr[now_won] += arr[now_won - coin];
		}
	}

	printf("%d\n", arr[target_won]);
	
	return 0;
}