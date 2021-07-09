#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;


int main()
{
	//t== 테스트 케이스, n == k번째로 작은 수
	int n; scanf("%d", &n);
	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int num; scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	printf("%d %d", v.front(), v.back());

	
	return 0;
}