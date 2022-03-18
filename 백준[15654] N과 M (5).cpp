#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

vector<int> num;
bool check[10001];
int m;


void func(int cnt,vector<int> v) {
    if (cnt == m) {
        for (int i = 0; i < (int)v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < (int)num.size(); i++) {
            int temp_num = num[i];
            if (!check[temp_num]) {
                check[temp_num] = true;
                vector<int> new_v = v;
                new_v.push_back(temp_num);
                func(cnt + 1, new_v);
                check[temp_num] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    vector<int> v;
    func(0, v);


    return 0;
}