#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string.h>
using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		long long radius; cin >> radius;

		long long answer = 0;

		long long col = 0; //col == radius¸é Á¾·á
		long long row = radius;

		while(row >= 0)
		{
			long long temp_dist = sqrt(row * row + col * col);

			if (temp_dist < radius)
			{
				answer += row + 1;
				col++;
				continue;
			}
			row--;
		}

		answer *= 4; //4¹ø °öÇØÁÜ

		answer -= (radius) * 4;

		answer += 1;
		
		cout << "Case #" << test_case + 1 << endl;
		cout << answer << endl;
	}

	return 0;
}