#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    int s1 = stoi(a + b);
    int s2 = stoi(b + a);
    if (s1 > s2) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    bool it_zero = true;

    vector<string> v;
    for (int num : numbers) {
        v.push_back(to_string(num));
        if (num != 0) it_zero = false;
    }

    if (it_zero == true) return "0";

    sort(v.begin(), v.end(), cmp);
    for (string s : v) {
        answer += s;
    }


    return answer;
}