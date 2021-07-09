#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


int main()
{
	vector<int> smalls;
	int all_height = 0;

	for (int i = 0; i < 9; i++)
	{
		int num; scanf("%d", &num);
		smalls.push_back(num);
		all_height += num;
	}
	sort(smalls.begin(), smalls.end());

	int first, sec;

	for (int i = 0; i < 8; i++)
	{
		for (int k = i + 1; k < 9; k++)
		{
			if (all_height - smalls[i] - smalls[k] == 100)
			{
				first = i;
				sec = k;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (i == first || i == sec) continue;
		
		printf("%d\n", smalls[i]);
	}

	return 0;
}