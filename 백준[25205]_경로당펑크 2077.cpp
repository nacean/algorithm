#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

bool letters[200];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char ja[] = {'r','s','e','f','a','q','t','d','w','c','z','x','v','g'};

    for(int i=0;i<14;i++){
        char now_c = ja[i];
        letters[now_c] = true;
    }

    int n;
    string s;
    cin >> n >> s;

    if(letters[s.back()]){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }


    return 0;
}