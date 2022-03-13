#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include<queue>
using namespace std;

int two = 0;
int five = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
   long long n; cin >> n;

   for (int i = n; i >= 1; i--) {
       int temp = i;
       while (temp % 5 == 0) {
           five++;
           temp /= 5;
       }
       while (temp % 2 == 0) {
           two++;
           temp /= 2;
       }
   }

   cout << min(two, five);

    return 0;
}