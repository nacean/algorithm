#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> order[110];
bool chicken_out[14];
int n, m;

int pickChicken(int pos, int cnt) {
    if (pos == (int)chicken.size() && cnt != m) return 987654321;
    if (cnt == m) {
        int ret = 0;
        for (int i = 0; i < (int)house.size(); i++) {
            for (int k = 0; k < (int)order[i].size(); k++) {
                int dist = order[i][k].first;
                int num = order[i][k].second;
                if (chicken_out[num] == true) {
                    ret += dist;
                    break;
                }
            }
        }
        return ret;
    }

    int ret = 987654321;

    //고름
    chicken_out[pos] = true;
    ret = min(ret,pickChicken(pos + 1, cnt + 1));
    chicken_out[pos] = false;

    //안고름
    ret = min(ret, pickChicken(pos + 1, cnt));

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            if (num == 1) house.push_back({ i,j });
            else if (num == 2) chicken.push_back({ i,j });
        }
    }

    for (int house_num = 0; house_num < (int)house.size(); house_num++) {
        for (int chicken_num = 0; chicken_num < (int)chicken.size(); chicken_num++) {
            pair<int, int> house_pos = house[house_num];
            pair<int, int> chicken_pos = chicken[chicken_num];

            order[house_num].push_back({ abs(house_pos.first - chicken_pos.first) + abs(house_pos.second - chicken_pos.second), chicken_num });
        }
        sort(order[house_num].begin(), order[house_num].end());
    }

    int ans = pickChicken(0, 0);

    cout << ans;

    return 0;
}