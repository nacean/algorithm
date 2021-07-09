#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	vector<int> blocks;
	int height, width; scanf("%d %d", &height, &width);

	for (int i = 0; i < width; i++)
	{
		int num; scanf("%d", &num);
		blocks.push_back(num);
	}

	int left_block = -1;

	int cnt = 0;

	for (int h = 1; h <= height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			int now_block = blocks[w];
			if (now_block >= h)
			{
				if (left_block == -1)
					left_block = w;

				else
				{
					cnt = cnt + w - left_block - 1;
					left_block = w;
				}
			}
		}
		left_block = -1;
	}

	printf("%d", cnt);

	return 0;
}