#include <string>
#include <vector>

using namespace std;

int ancestor[200];
bool check[200];

int get_last_ancestor(int a) {
    if (a == ancestor[a]) return a;

    else return ancestor[a] = get_last_ancestor(ancestor[a]);
}

void make_union(int a, int b) {
    int anc_a = get_last_ancestor(a);
    int anc_b = get_last_ancestor(b);

    if (anc_a < anc_b) {
        ancestor[anc_b] = anc_a;
    }
    else {
        ancestor[anc_a] = anc_b;
    }
}



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) ancestor[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {
                make_union(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int anc = get_last_ancestor(i);
        if (check[anc] == false) {
            check[anc] = true;
            answer++;
        }
    }

    return answer;
}