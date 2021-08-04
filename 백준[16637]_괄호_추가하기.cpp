#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>

using namespace std;

int n;
string s;

long long int answer = -2147483648;

void dfs(long long int now_value, long long int now_pos)
{
	if (now_pos >= n)
	{
		if (answer < now_value) answer = now_value;
		return;
	}

	char now_cal = s[now_pos-1]; //계산하려는 연산자
	long long int now_num = s[now_pos] - '0'; //지금 해당하는 숫자
	long long int new_non_value;

	//만약 괄호를 안친다면 now_value에 연산을 하고 보냄

	if (now_cal == '+') new_non_value = now_value + now_num;
	else if (now_cal == '-')  new_non_value = now_value - now_num;
	else new_non_value = now_value * now_num;

	dfs(new_non_value, now_pos + 2);

	//만약 마지막 숫자라면? 여기서 끝냄 더이상 괄호 칠 수 없음
	if (now_pos == n - 1) return;

	//만약 괄호를 친다면, 3개를 모두 연산 후 now_value와 연산, 그리고 다음 연산자를 골라둠
	long long int now_sec_num = s[now_pos + 2] - '0';
	long long int sec_value;
	char between_cal = s[now_pos + 1];

	if (between_cal == '+') sec_value = now_num + now_sec_num;
	else if (between_cal == '-')  sec_value = now_num - now_sec_num;
	else sec_value = now_num * now_sec_num;

	if (now_cal == '+') new_non_value = now_value + sec_value;
	else if (now_cal == '-')  new_non_value = now_value - sec_value;
	else new_non_value = now_value * sec_value;

	dfs(new_non_value, now_pos + 4);


}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	//짝수 == 숫자, 홀수 == 연산자
	
	cin >> n >> s;

	long long int first_value = s[0] - '0';
	
	if (s.size() == 1)
	{
		cout << s[0] << endl;
		return 0;
	}

	char between_cal = s[1];
	long long int second_value = s[2] - '0';

	long long int calculated_value = 0;

	if (between_cal == '+') calculated_value = first_value + second_value;
	else if (between_cal == '-') calculated_value = first_value - second_value;
	else if (between_cal == '*') calculated_value = first_value * second_value;

	if (s.size() == 3)
	{
		cout << calculated_value << endl;
		return 0;
	}

	//첫괄호를 안쳤을 때
	dfs(first_value, 2);

	//첫 괄호 쳤을때
	dfs(calculated_value, 4);

	cout << answer;


	return 0;
}