#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;


vector<int> numbers;

int max_answer = -1000000001;
int min_answer = 1000000001;

void calculator(int now_num, int plus, int sub, int mult, int div, int where_now)
{
	//마지막 최종 숫자 체크
	if (plus == 0 && sub == 0 && mult == 0 && div == 0)
	{
		if (max_answer < now_num) max_answer = now_num;
		if (min_answer > now_num) min_answer = now_num;

		return;
	}

	int new_now_num;

	if (plus > 0)
	{
		new_now_num = now_num + numbers[where_now + 1];
		calculator(new_now_num, plus - 1, sub, mult, div, where_now + 1);
	}
	if (sub > 0)
	{
		new_now_num = now_num - numbers[where_now + 1];
		calculator(new_now_num, plus, sub-1, mult, div, where_now + 1);
	}
	if (mult > 0)
	{
		new_now_num = now_num * numbers[where_now + 1];
		calculator(new_now_num, plus, sub, mult-1, div, where_now + 1);
	}
	if (div > 0)
	{
		if (now_num < 0 && numbers[where_now + 1] > 0)
		{
			int rev_now_num = 0 - now_num;
			new_now_num = rev_now_num / numbers[where_now + 1];
			new_now_num = 0 - new_now_num;
		}
		else new_now_num = now_num / numbers[where_now + 1];

		calculator(new_now_num, plus, sub, mult, div-1, where_now + 1);
	}
}


int main()
{
	int plus, sub, mult, div;
	plus = sub = mult = div = 0;


	int n; scanf("%d", &n); // 수의 개수
	for (int i = 0; i < n; i++)
	{
		int num; scanf("%d", &num);
		numbers.push_back(num);
	}
	scanf("%d %d %d %d", &plus, &sub, &mult, &div);

	calculator(numbers[0], plus, sub, mult, div, 0);

	printf("%d\n%d\n", max_answer, min_answer);


	return 0;
}