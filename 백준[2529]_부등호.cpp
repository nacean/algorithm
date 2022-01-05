#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#define ll long long
using namespace std;

bool numbers[10];
char boo[10];
string min_ans = "9876543210";
string max_ans = "0";
int n;

void func(int left_num, int now_boo, string result) {

	if (now_boo == n) {
		if (stoll(min_ans) > stoll(result)) min_ans = result;
		if (stoll(max_ans) < stoll(result)) max_ans = result;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (numbers[i] == true) continue;

			if (boo[now_boo] == '<' && left_num < i) {
				numbers[i] = true;
				func(i, now_boo + 1,result+to_string(i));
				numbers[i] = false;
			}
			else if (boo[now_boo] == '>' && left_num > i) {
				numbers[i] = true;
				func(i, now_boo + 1, result + to_string(i));
				numbers[i] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> boo[i];
	}

	for (int i = 0; i <= 9; i++) {
		numbers[i] = true;
		func(i, 0, to_string(i));
		numbers[i] = false;
	}

	cout << max_ans << endl << min_ans;

	return 0;
}
