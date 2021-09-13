#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int work[20][20];
int dp[3000000];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			int num; cin >> num;
			work[row][col] = num;
		}
	}

	vector<int> v[20];

	for (int i = 0; i < n; i++) {
		v[0].push_back((1 << i));
		dp[(1 << i)] = work[0][i];
	}

	for (int now = 1; now < n; now++) {

		vector<int> bit_list = v[now - 1];

		for (int i = 0; i < bit_list.size(); i++) {

			int now_bit = bit_list[i];

			for (int col = 0; col < n; col++) {
				int work_pay = work[now][col];
				int next_bit = now_bit | (1 << col);

				if (now_bit == next_bit) { //같은 bit면 중복된 일을 한다는뜻
					continue;
				}

				else if (dp[next_bit] > dp[now_bit] + work_pay || dp[next_bit] == 0) {
					dp[next_bit] = dp[now_bit] + work_pay;
					v[now].push_back(next_bit);
				}
			}
		}
			
	}

	cout << dp[(1 << n) - 1] << endl;

	return 0;
}