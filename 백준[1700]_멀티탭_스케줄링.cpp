#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>

using namespace std;

int find_plug(vector<int>is_plugged, int now_to_plug)
{
	bool plug_ok = false;
	for (int past_plug : is_plugged)
	{
		if (past_plug == now_to_plug) plug_ok = true;
	}

	return plug_ok;
}

int main()
{
	int hole, use_cnt; scanf("%d %d", &hole, &use_cnt);

	//���� ����ⱸ���� �÷��� ������ �� ũ�� 0
	if (hole >= use_cnt)
	{
		printf("0");
		return 0;
	}

	vector<int>use;

	for (int i = 0; i < use_cnt; i++)
	{
		int num; scanf("%d", &num);
		use.push_back(num);
	}

	//�����ִ� ����ⱸ ��ȣ ����
	vector<int> is_plugged;

	//�̸� �÷��� �ȾƵ�
	is_plugged.push_back(use[0]);

	int answer = 0;

	//����ⱸ�� ������� �ȴ´�
	for (int i = 1; i < use_cnt; i++)
	{
		int now_to_plug = use[i];

		//���� �̹� ���������� �ǳʶڴ�
		if (find_plug(is_plugged, now_to_plug)) continue;

		//���� �÷��� ������ ������, �״�� �ȴ´�
		if (is_plugged.size() < hole)
		{
			is_plugged.push_back(use[i]);
			continue;
		}

		//�ƿ� �ȳ�Ÿ���ų� �ڿ����� ���� �ٲ۴�
		int* how_far = new int[101];
		for (int k = 0; k < 100; k++) how_far[k] = 0;

		for (int k = i + 1; k < use_cnt; k++)
		{
			int future_plug = use[k]; //�̷��� ����� ����ⱸ

			if (how_far[future_plug] != 0) continue; // ���� �ֱٿ� ����� ��ϸ� �����

			how_far[future_plug] = k; //����ⱸ ��ȣ�� k�� �� ����� ���̴�
		}
		
		int what_to_change = 0; //�켱������ ������ ��ó���� �ٲ۴�

		for (int k = 0; k < is_plugged.size(); k++)
		{
			int plug_num = is_plugged[k]; //�����ִ� �÷����� ����ⱸ�� ��ȣ
			
			//���� �ڿ� ���� ������� �ʴ´ٸ� �����Ѵ�
			if (how_far[plug_num] == 0)
			{
				what_to_change = k;
			}

			//����Ѵٸ�, ���� �ڿ� ����ϴ°Ÿ� ��ü�Ѵ�
			else
			{
				int pick_to_change = is_plugged[what_to_change];

				if (how_far[pick_to_change] == 0) continue; //���� �̹� ���� �ѹ��� ���� �ʴ� ���̶��, �ǳʶڴ�

				if (how_far[pick_to_change] < how_far[plug_num]) what_to_change = k;
			}
		}

		//is_plugged���� ���� �� ���� ���� �÷��� �߰� �� ����Ƚ�� 1ȸ ����
		is_plugged.erase(is_plugged.begin() + what_to_change);
		is_plugged.push_back(now_to_plug);
		answer++;

		delete[] how_far;
	}

	printf("%d", answer);


	return 0;
}