#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;



int main()
{
	int t; scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		vector<int> arr;
		int num;
		for (int i = 0; i < 10; i++)
		{
			scanf("%d", &num);
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		printf("%d\n", arr[7]);
		arr.clear();


	}

	return 0;
}