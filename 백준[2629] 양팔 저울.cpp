#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[30][15001];

void func(int pos, vector<int>& chew, int added) {
    if (pos == chew.size()) return;

    int now_num = chew[pos];

    int minus = abs(added - now_num);
    int plus = added + now_num;

    if (!check[pos][plus]) {
        check[pos][plus] = true;
        func(pos + 1, chew, plus);
    }

    func(pos + 1, chew, added);

    if (!check[pos][minus]) {
        check[pos][minus] = true;
        func(pos + 1, chew, minus);
    }


}


int main() {
    int n; cin >> n;
    vector<int> chew;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        chew.push_back(num);
    }

    func(0, chew, 0);
    int m; cin >> m;
    for(int i=0;i<m;i++){
        int num; cin >> num;
        if (num > 15000) {
            cout << "N ";
            continue;
        }
        bool can_find = false;
        
        for (int t= 0; t < n; t++) {
            if (check[t][num]) {
                can_find = true;
                break;
            }
        }

        if (can_find) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}