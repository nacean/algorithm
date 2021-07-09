#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int gcd(int a, int b)
{
	while (a % b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}

	return b;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int a, b; scanf("%d %d", &a, &b);
	if (b > a) swap(a, b);
	printf("%d\n%d", gcd(a, b), lcm(a, b));

	return 0;
}