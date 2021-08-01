#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>

using namespace std;

int answer = 987654321;


//Ŭ������ ��, ���� ��
int arr[1001][1001];

//Ŭ�������, ������� ������ Ƚ���� �� ũ�� �׸���
void dfs(int ClipBoard, int Now_Numbers, int Now_Cnt)
{
	if (Now_Cnt > 500 || Now_Numbers > 1000 || ClipBoard > 1000) return;

	int New_Cnt = Now_Cnt + 1;

	//Ŭ������ ����
	int New_Clip_Board = Now_Numbers;

	if (New_Clip_Board <= 1000)
	{
		if (arr[New_Clip_Board][Now_Numbers] > New_Cnt)
		{
			arr[New_Clip_Board][Now_Numbers] = New_Cnt;
			dfs(New_Clip_Board, Now_Numbers, New_Cnt);
		}
	}

	int New_Now_Numbers = Now_Numbers + ClipBoard;
	
	if (New_Now_Numbers <= 1000)
	{
		if (arr[ClipBoard][New_Now_Numbers] > New_Cnt)
		{
			arr[ClipBoard][New_Now_Numbers] = New_Cnt;
			dfs(ClipBoard, New_Now_Numbers, New_Cnt);
		}
	}

	int Erased_Numbers = Now_Numbers - 1;

	if (Erased_Numbers > 0)
	{
		if (arr[ClipBoard][Erased_Numbers] > New_Cnt)
		{
			arr[ClipBoard][Erased_Numbers] = New_Cnt;
			dfs(ClipBoard, Erased_Numbers, New_Cnt);
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int s; cin >> s;

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			arr[i][j] = 9999;
		}
	}

	//1�� �����ϰ�, 1�� ������������ �ʱ�ȭ == 1
	arr[1][1] = 1;

	dfs(1, 1, 1);

	for (int i = 1; i <= 1000; i++)
	{
		if (answer > arr[i][s]) answer = arr[i][s];
	}

	cout << answer;

	return 0;
}