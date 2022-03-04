#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<utility>
#include<math.h>
#include<cstring>
#include<queue>
#define ll long long

using namespace std;

int check[201][201][201];

vector<int> v;

void func(int a, int b, int c, int maxA, int maxB, int maxC) {
	check[a][b][c] = true;

	if (a == 0) v.push_back(c);

	int na = a;
	int nb = b;
	int nc = c;
	nb += na;
	na = 0;
	if (nb > maxB) {
		na = nb - maxB;
		nb = maxB;
	}
	if (!check[na][nb][nc]) func(na, nb, nc, maxA, maxB, maxC);

	na = a;
	nb = b;
	nc = c;
	nc += na;
	na = 0;
	if (nc > maxC) {
		na = nc - maxC;
		nc = maxC;
	}
	if (!check[na][nb][nc]) func(na, nb, nc, maxA, maxB, maxC);

	na = a;
	nb = b;
	nc = c;
	na += nb;
	nb = 0;
	if (na > maxA) {
		nb = na - maxA;
		na = maxA;
	}
	if (!check[na][nb][nc]) func(na, nb, nc, maxA, maxB, maxC);

	na = a;
	nb = b;
	nc = c;
	nc += nb;
	nb = 0;
	if (nc > maxC) {
		nb = nc - maxC;
		nc = maxC;
	}
	if (!check[na][nb][nc]) func(na, nb, nc, maxA, maxB, maxC);

	na = a;
	nb = b;
	nc = c;
	na += nc;
	nc = 0;
	if (na > maxA) {
		nc = na - maxA;
		na = maxA;
	}
	if (!check[na][nb][nc]) func(na, nb, nc, maxA, maxB, maxC);

	na = a;
	nb = b;
	nc = c;
	nb += nc;
	nc = 0;
	if (nb > maxB) {
		nc = nb - maxB;
		nb = maxB;
	}
	if (!check[na][nb][nc]) func(na, nb, nc, maxA, maxB, maxC);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c; cin >> a >> b >> c;

	func(0, 0, c, a, b, c);

	sort(v.begin(), v.end());

	for (int num : v) {
		cout << num << " ";
	}

	return 0;

}