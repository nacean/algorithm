#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string left, right;
	cin >> left >> right;
	int answer = 55;

	for (int i = 0; i <= right.size() - left.size(); i++) { // i == 처음 위치
		int temp = left.size();

		for (int now = 0; now < left.size(); now++) // i + now 해서 비교
		{
			if (left[now] == right[i + now]) temp--;
		}

		answer = min(temp, answer);
	}
	
	cout << answer;

	return 0;
}
