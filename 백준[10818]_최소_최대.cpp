#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;


int main()
{
	//t== �׽�Ʈ ���̽�, n == k��°�� ���� ��
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