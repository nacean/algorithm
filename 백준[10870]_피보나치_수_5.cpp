#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int arr[21];

int main()
{
	arr[0] = 0;
	arr[1] = 1;

	int n; scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%d", arr[n]);

	return 0;
}