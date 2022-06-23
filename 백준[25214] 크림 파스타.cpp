#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

int arr[200001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;

    for(int i=0;i<n;i++){
        int num; cin >> num;
        arr[i]=num;
    }

    int min = arr[0];
    int min_pos = 0;

    int gab = 0;

    for(int i=0;i<n;i++){
        int now_num = arr[i];

        if(min > now_num){
            min = now_num;
            min_pos = i;
        }

        if(arr[i] - min > gab){
            gab = arr[i] - min;
        }

        cout << gab << " ";

    }

    // 30  70 10 60

    return 0;
}