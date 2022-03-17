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

string s;
string ans = "";
stack<pair<int, int>> func_Stack;

void make_tree(int start, int stop) {
    if (start == stop) {
        func_Stack.push({ start,-1 });
        return;
    }

    while (true) {
        bool change = false;
        if (s[start] == '(') {
            stack<pair<char, int>> test;
            test.push({ '(',start });

            for (int i = start + 1; i <= stop; i++) {
                if (i == stop && !test.empty()) {
                    if (test.top().second == start && s[i] == ')') {
                        start++;
                        stop--;
                        change = true;
                    }
                }
                else {
                    if (s[i] == '(') test.push({ '(',i });
                    else if (!test.empty() && s[i] == ')') test.pop();
                }
            }
        }
        if (change == false) break;
    }
    int to_pop = -1;
    char now_pop_char = '*';
    int char_inside_level = 987654321;
    int now_inside_level = 0;
    for (int i = start; i <= stop; i++) {
        if (s[i] == '(') {
            now_inside_level++;
            continue;
        }
        if (s[i] == ')') {
            now_inside_level--;
            continue;
        }

        if ((s[i] == '*' || s[i] == '/') && (now_inside_level <= char_inside_level)) {
            if (now_inside_level == char_inside_level) {
                if (now_pop_char != '-' && now_pop_char != '+') {
                    to_pop = i;
                    now_pop_char = s[i];
                }
            }
            else if (now_inside_level < char_inside_level) {
                to_pop = i;
                char_inside_level = now_inside_level;
                now_pop_char = s[i];
            }
        }
        if ((s[i] == '+' || s[i] == '-') && (now_inside_level <= char_inside_level)) {
            to_pop = i;
            char_inside_level = now_inside_level;
            now_pop_char = s[i];
        }
    }
 
    int left_start = start;
    int left_stop = to_pop - 1;
    int right_start = to_pop + 1;
    int right_stop = stop;
    
    func_Stack.push({ to_pop,-1 });
    func_Stack.push({ right_start,right_stop });
    func_Stack.push({ left_start,left_stop });
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int start = 0;
    int stop = s.size() - 1;

    func_Stack.push({ start,stop });

    while (!func_Stack.empty()) {
        pair<int, int> now = func_Stack.top();
        func_Stack.pop();
        if (now.second == -1) ans.push_back(s[now.first]);
        else make_tree(now.first, now.second);
    }

    cout << ans;
    return 0;
}