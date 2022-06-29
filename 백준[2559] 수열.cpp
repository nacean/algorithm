#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int arr[100001];
int nu[100001];
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k; cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    nu[0] = arr[0];

    for(int i=1;i<n;i++) nu[i] = arr[i] + nu[i-1];

    int ans = nu[k-1];

    for(int i=k;i<n;i++){
        ans = max(ans,nu[i] - nu[i-k]);
    }

    cout << ans;

    return 0;
}