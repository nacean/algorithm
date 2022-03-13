#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include<queue>
using namespace std;

string arr[100001];
map<string, int> map_arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s; cin >> s;

        arr[i] = s;
        map_arr[s] = i;

    }

    for (int i = 1; i <= m; i++) {
        string q; cin >> q;
        int check_num = q[0];

        if (check_num >= 'A' && check_num <= 'Z') cout << map_arr[q] << "\n";
        else cout << arr[stoi(q)] << "\n";
    }

    return 0;
}