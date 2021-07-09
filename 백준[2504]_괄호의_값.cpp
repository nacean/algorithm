#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>

using namespace std;

vector<int> int_gwalho;

void make_answer()
{
	if (int_gwalho.size() == 1)
	{
		printf("%d", int_gwalho.front());
		return;
	}


	for (int i = 0; i < int_gwalho.size()-1; i++)
	{
		if (int_gwalho[i] == -2 && int_gwalho[i + 1] == -1)
		{
			int_gwalho[i] = 2;
			int_gwalho.erase(int_gwalho.begin() + i + 1);
			break;
		}
		else if (int_gwalho[i] == -11 && int_gwalho[i + 1] == -10)
		{
			int_gwalho[i] = 3;
			int_gwalho.erase(int_gwalho.begin() + i + 1);
			break;
		}
		else if (int_gwalho[i] > 0 && int_gwalho[i + 1] > 0)
		{
			int_gwalho[i] = int_gwalho[i] + int_gwalho[i + 1];
			int_gwalho.erase(int_gwalho.begin() + i + 1);
			break;
		}
		else if (int_gwalho[i] == -2 && int_gwalho[i + 1] > 0 && int_gwalho[i + 2] == -1)
		{
			int_gwalho[i] = int_gwalho[i + 1] * 2;
			int_gwalho.erase(int_gwalho.begin() + i + 1,int_gwalho.begin()+i+3);
			break;
		}
		else if (int_gwalho[i] == -11 && int_gwalho[i + 1] > 0 && int_gwalho[i + 2] == -10)
		{
			int_gwalho[i] = int_gwalho[i + 1] * 3;
			int_gwalho.erase(int_gwalho.begin() + i + 1, int_gwalho.begin() + i + 3);
			break;
		}
	}

	make_answer();
}

int main()
{
	string gwalho;

	cin >> gwalho;

	if (gwalho.front() == ')' || gwalho.front() == ']')
	{
		printf("0");
		return 0;
	}

	stack<char> check;

	for (int i=0; i<gwalho.size();i++)
	{
		char c = gwalho[i];

		if (c == '[') int_gwalho.push_back(-11);
		else if (c == ']') int_gwalho.push_back(-10);
		else if (c == '(') int_gwalho.push_back(-2);
		else int_gwalho.push_back(-1);

		if (check.empty()) check.push(c);

		else if (check.top() == '[' && c == ']') check.pop();

		else if (check.top() == '(' && c == ')') check.pop();

		else check.push(c);
	}

	if (!check.empty())
	{
		printf("0");
		return 0;
	}

	make_answer();

	return 0;
}