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

	char now_cal = s[now_pos-1]; //����Ϸ��� ������
	long long int now_num = s[now_pos] - '0'; //���� �ش��ϴ� ����
	long long int new_non_value;

	//���� ��ȣ�� ��ģ�ٸ� now_value�� ������ �ϰ� ����

	if (now_cal == '+') new_non_value = now_value + now_num;
	else if (now_cal == '-')  new_non_value = now_value - now_num;
	else new_non_value = now_value * now_num;

	dfs(new_non_value, now_pos + 2);

	//���� ������ ���ڶ��? ���⼭ ���� ���̻� ��ȣ ĥ �� ����
	if (now_pos == n - 1) return;

	//���� ��ȣ�� ģ�ٸ�, 3���� ��� ���� �� now_value�� ����, �׸��� ���� �����ڸ� ����
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
	
	
	//¦�� == ����, Ȧ�� == ������
	
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

	//ù��ȣ�� ������ ��
	dfs(first_value, 2);

	//ù ��ȣ ������
	dfs(calculated_value, 4);

	cout << answer;


	return 0;
}