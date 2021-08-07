#include <iostream>
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
		int Answer;

		int people_cnt; cin >> people_cnt;
		vector<int> people;

		//너의 부모는 몇번인가?
		vector<int> parent_num;

		//니가 부모가 맞는가?
		bool * check = new bool[people_cnt];

		fill(check, check + people_cnt, true);

		//i와 i+people[i]는 친구관계
		for (int i = 0; i < people_cnt; i++)
		{
			int num; cin >> num;
			people.push_back(num);
			parent_num.push_back(i);
		}

		Answer = 0;

		for (int i = 0; i < people_cnt; i++)
		{
			int now_friend = i + people[i];
			int my_parent = parent_num[i];

			if (i + people[i] >= people_cnt) continue;

			int friend_parent = parent_num[now_friend];


			if (my_parent < friend_parent)
			{
				check[friend_parent] = false;
				parent_num[now_friend] = my_parent;
			}

			else
			{
				check[my_parent] = false;
				parent_num[i] = friend_parent;
			}
			
		}

		for (int i = 0; i < people_cnt; i++)
		{
			if (check[i] == true) Answer++;
		}


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		delete[] check;
		

	}

	return 0;
}