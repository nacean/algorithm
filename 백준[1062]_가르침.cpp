#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>

using namespace std;

int answer = 0;
int end_bit = 26;

vector<int> check_mask; //check 하기위해 만들어진 char의 집합들
vector<int> bit_words; //단어들을 bit로 만들어 보관한것

void check(int bits_for_check, int now_pos, int cnt)
{
	if (cnt == 0)
	{
		check_mask.push_back(bits_for_check);
		return;
	}

	if (now_pos == end_bit)
		return;

	
	int new_bits_for_check = (bits_for_check | (1 << now_pos));

	check(new_bits_for_check, now_pos + 1, cnt - 1);
	check(bits_for_check, now_pos + 1, cnt);
	
}

int main()
{
	// 'a' == 97, 'z' == 122
	// bitmasks == 0 ~ 25
	
	int word, spell; scanf("%d %d", &word, &spell);

	vector<string> words;
	
	for (int i = 0; i < word; i++)
	{
		string s; cin >> s;
		words.push_back(s);
	}

	if (spell < 5)
	{
		printf("0");
		return 0;
	}

	for (string s : words)
	{
		int new_bit = 0;
		//bitmask에 각 char별로 마킹하기
		for (char c : s)
		{
			new_bit |= (1 << (c - 97));
		}
		bit_words.push_back(new_bit);

	}

	check(0, 0, spell);

	int answer = 0;

	for (int check_bit : check_mask)
	{
		int new_answer = 0;
		for (int bit_word : bit_words)
		{
			if ((check_bit & bit_word) == bit_word) new_answer++;
		}

		if (new_answer > answer) answer = new_answer;
	}

	printf("%d\n", answer);

	return 0;
}