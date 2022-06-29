#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int wordDP[200001][200];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    wordDP[0][s[0]]++;

    for(int word='a';word<='z';word++){
        for(int i=1;i<s.size();i++){
            if(s[i] == word) wordDP[i][word] = wordDP[i-1][word]+1;
            else wordDP[i][word] = wordDP[i-1][word];
        }
    }

    int n; cin >> n;

    for(int i=0;i<n;i++){
        char now_word; cin >> now_word;
        int start,end; cin >> start >> end;

        int ans = wordDP[end][now_word];
        if(start-1 >= 0) ans -= wordDP[start-1][now_word];

        cout << ans << "\n";
    }


    return 0;
}