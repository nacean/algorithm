#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include<queue>
using namespace std;

int match[1000001];
string ioi;

void matching() {
    int j = 0;
    for (int i = 1; i < (int)ioi.size(); i++) {
        while (j > 0 && ioi[i] != ioi[j]) {
            j = match[j - 1];
        }
        if (ioi[i] == ioi[j]) {
            match[i] = ++j;
        }
    }

}

int kmp(string s) {
    int ans = 0;
    int j = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != ioi[j]) {
            j = match[j - 1];
        }
        if (s[i] == ioi[j]) {
            if (j == ioi.size() - 1) {
                ans++;
                j = match[j];
            }
            else {
                j++;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    string s; cin >> s;

    ioi = "IOI";

    for (int i = 2; i <= n; i++) {
        ioi += "OI";
    }

    matching();

    cout <<  kmp(s);


    return 0;
}