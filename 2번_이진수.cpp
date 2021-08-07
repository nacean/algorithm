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

		//b�� ��
		int* arr_b = new int[n + 1];

		//a�� ��
		int* arr_a = new int[n + 1];
		fill(arr_a, arr_a + n + 1, 0);

		//b�� i�϶�, ������ a�� ��
		vector<int> arr_b_to_a[50001];

		//true��� �ϸ� �ȵǴ� a[i]��
		bool do_not_check[50001];

		fill(do_not_check, do_not_check + n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			scanf("%1d", &arr_b[i]);

			//b[i]�� 0�̶�� �ش� a[i]���� �����ؼ� �ȵ�
			if (arr_b[i] == 0)
			{
				if (i > t) do_not_check[i - t] = true;
				if (i <= n - t) do_not_check[i + t] = true;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			//b[i]�� 0�̶�� �ǳʶ�
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
				if (arr_a[a_num] == 0) arr_a[a_num] = 1; //���� üũ�� �ȵ������� a�� �̴´�
				else continue; // üũ �������� �����Ѵ�
			}
			else if (arr_b_to_a[i].size() == 2)
			{
				int small_a_num = arr_b_to_a[i][0]; //1�� ����� a��ȣ
				int big_a_num = arr_b_to_a[i][1]; //�� a��ȣ
				
				if (arr_a[big_a_num] == 1) continue; //���� �տ��� ������ �ߴٸ�, �Ѿ��.
				else arr_a[small_a_num] = 1; //���� �׷��� �ʴٸ�, �� �������� �����Ѵ�

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