#include <string>
#include <vector>

using namespace std;

bool all_lost[31];
bool all_reserve[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    for (int num : lost) {
        all_lost[num] = true;
        answer--;
    }
    for (int num : reserve) {
        if (all_lost[num] == true)
        {
            all_lost[num] = false;
            answer++;
        }
        else all_reserve[num] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (all_lost[i] == true) {
            if (i == 1 && all_reserve[i + 1] == true) {
                all_reserve[i + 1] = false;
                answer++;
            }
            else if (i == n; all_reserve[i - 1] == true) {
                answer++;
            }
            else if (i != 1 && i != n) {
                if (all_reserve[i - 1] == true) {
                    all_reserve[i - 1] = false;
                    answer++;
                }
                else if (all_reserve[i + 1] == true) {
                    all_reserve[i + 1] = false;
                    answer++;
                }
            }
        }
    }

    return answer;
}