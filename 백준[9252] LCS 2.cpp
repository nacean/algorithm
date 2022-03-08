#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs[1001][1001];


int main() {

    string a, b; cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            char a_c = a[i];
            char b_c = b[j];
            if (a_c == b_c) {
                if (i > 0 && j > 0) lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else lcs[i][j] = 1;
            }
            else {
                if (i == 0 && j == 0) lcs[i][j] = 0;
                else if (i > 0 && j == 0) lcs[i][j] = lcs[i - 1][j];
                else if (i == 0 && j > 0) lcs[i][j] = lcs[i][j - 1];
                else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    string ans="";

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else if (i == 0 || j == 0) {
            if (i == 0 && j == 0) break;
            else if (i == 0) j--;
            else i--;
        }
        else {
            if (lcs[i][j - 1] > lcs[i - 1][j]) j--;
            else i--;
        }
    }
    reverse(ans.begin(), ans.end());
    if (lcs[a.size() - 1][b.size() - 1] == 0) cout << 0;
    else cout << lcs[a.size() - 1][b.size() - 1]<< "\n" << ans;

    return 0;
}