#include <string>
#include <vector>
#include <utility>

using namespace std;

int not_pick[1000000][2]; //0 ╬х╩лю╫, 1 ╩лю╫
int pick[1000000][2];
int solution(vector<int> money) {
    int answer = 0;
    pick[1][1] = 0;
    pick[1][0] = money[0];
    not_pick[1][0] = 0;
    not_pick[1][1] = money[1];


    for (int i = 2; i < (int)money.size() - 1; i++) {
        pick[i][0] = max(pick[i - 1][0], pick[i - 1][1]);
        pick[i][1] = pick[i - 1][0] + money[i];
        not_pick[i][0] = max(not_pick[i - 1][0], not_pick[i - 1][1]);
        not_pick[i][1] = not_pick[i - 1][0] + money[i];
    }

    int last_num = (int)money.size() - 1;

    pick[last_num][0] = max(pick[last_num - 1][0], pick[last_num - 1][1]);
    not_pick[last_num][0] = max(not_pick[last_num - 1][0], not_pick[last_num - 1][1]);
    not_pick[last_num][1] = not_pick[last_num - 1][0] + money[last_num];

    answer = max(max(pick[last_num][0], not_pick[last_num][0]), not_pick[last_num][1]);

    return answer;
}