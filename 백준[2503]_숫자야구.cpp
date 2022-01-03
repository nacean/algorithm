#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
using namespace std;

string base[100];
set<char> setOfBase[100];
int strike[100];
int ball[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	
	bool strike_complete = false;

	for (int i = 0; i < n; i++) {
		int num, s,b;

		cin >> num >> s >> b;

		base[i] = to_string(num);

		for (int k = 0; k < 3; k++) {
			setOfBase[i].insert(base[i][k]);
		}

		strike[i] = s;
		ball[i] = b;

		if (s == 3) strike_complete == true;
	}

	if (strike_complete == true) {
		cout << 1 << endl;
		return 0;
	}

	int answer = 0;

	for (int temp = 100; temp <= 999; temp++) {
		bool is_correct = true;

		string s_temp = to_string(temp);

		if (s_temp[0] == s_temp[1] || s_temp[1] == s_temp[2] || s_temp[0] == s_temp[2]) continue;
		if (s_temp[0] == '0' || s_temp[1] == '0' || s_temp[2] == '0') continue;


		for (int i = 0; i < n; i++) {
			int temp_Strike = 0;
			int temp_Ball = 0;

			for (int pos = 0; pos < 3; pos++) {
				if (base[i][pos] == s_temp[pos]) temp_Strike++;
				else if (setOfBase[i].count(s_temp[pos]) > 0) temp_Ball++;
			}

			if (temp_Strike != strike[i] || temp_Ball != ball[i]) {
				is_correct = false;
				break;
			}
		}

		if(is_correct == true) answer++;
	}

		cout << answer << endl;
	return 0;
}
