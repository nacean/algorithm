#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int n, t; cin >> n >> t;

		//b의 값
		int* arr_b = new int[n + 1];

		//a의 값
		int* arr_a = new int[n + 1];
		fill(arr_a, arr_a + n + 1, 0);

		//b가 i일때, 가능한 a의 값
		vector<int> arr_b_to_a[50001];

		//true라면 하면 안되는 a[i]임
		bool do_not_check[50001];

		fill(do_not_check, do_not_check + n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			scanf("%1d", &arr_b[i]);

			//b[i]가 0이라면 해당 a[i]들은 접근해선 안됨
			if (arr_b[i] == 0)
			{
				if (i > t) do_not_check[i - t] = true;
				if (i <= n - t) do_not_check[i + t] = true;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			//b[i]가 0이라면 건너뜀
			if (arr_b[i] == 0) continue;

			if (i <= n-t)
			{
				if (do_not_check[i + t] == false) arr_b_to_a[i].push_back(i + t);
			}
			if (i > t)
			{
				if (do_not_check[i - t] == false) arr_b_to_a[i].push_back(i - t);
			}

			if (arr_b_to_a[i].size() == 1)
			{
				int a_num = arr_b_to_a[i][0];
				if (arr_a[a_num] == 0) arr_a[a_num] = 1; //만약 체크가 안되있으면 a를 뽑는다
				else continue; // 체크 되있으면 무시한다
			}
			else if (arr_b_to_a[i].size() == 2)
			{
				int small_a_num = arr_b_to_a[i][0]; //1에 가까운 a번호
				int big_a_num = arr_b_to_a[i][1]; //먼 a번호
				
				if (arr_a[big_a_num] == 1) continue; //만약 앞에서 선택을 했다면, 넘어간다.
				else arr_a[small_a_num] = 1; //만약 그렇지 않다면, 더 작은쪽을 선택한다

			}

		}

		cout << "Case #" << test_case + 1 << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << arr_a[i];
		}
		cout << endl;
		delete[] arr_b;
		delete[] arr_a;
	}

	return 0;

}