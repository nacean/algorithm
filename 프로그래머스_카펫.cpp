#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; i++) {
        if (yellow % i != 0) continue;

        int row = yellow / i;
        int col = i;
        if (row * 2 + col * 2 + 4 == brown) {
            answer.push_back(row + 2);
            answer.push_back(col + 2);
            break;
        }
    }

    return answer;
}