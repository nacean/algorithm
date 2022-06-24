#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

bool isUpper(char c){
    if(c >= 97) return false;
    else return true;
}

int dp[3001][2];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    //97이상이면 소문자   -> 0이면 소문자, 1이면 대문자
    bool first_word = isUpper(s[0]);

    if(first_word){
        dp[0][0] = 2;
        dp[0][1] = 2;
    }
    else {
        dp[0][0] = 1;
        dp[0][1] = 2;
    }

    for(int i=1;i<s.size();i++){
        bool now_word = isUpper(s[i]);

        if(now_word){//지금 문자가 대문자여야한다면
            dp[i][0] = min(dp[i-1][0]+2,dp[i-1][1]+2);
            dp[i][1] = min(dp[i-1][0]+2,dp[i-1][1]+1);
        }
        else{
            dp[i][0] = min(dp[i-1][0]+1,dp[i-1][1]+2);
            dp[i][1] = min(dp[i-1][0]+2,dp[i-1][1]+2);
        }
    }

    cout << min(dp[s.size()-1][0],dp[s.size()-1][1]) << endl;
    

    return 0;
}