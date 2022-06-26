#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;

    int start_num;
    int end_num;

    
    for(int size=1;size<=s.size();size++){
        int temp_num = stoi(s.substr(0,size));
        start_num = temp_num;

        int s_pos = 0;

        bool found = true;

        while(1){
            string temp_string = to_string(temp_num);

            for(int i=0;i<temp_string.size();i++){
                if(s_pos >= s.size()) {
                    found = false;
                    break;
                }
                if(temp_string[i] != s[s_pos++]) {
                    found = false;
                    break;
                }
            }

            if(found == false) break;

            if(s_pos == s.size()){
                end_num = temp_num;
                break;
            }
            
            temp_num++;
        }

        if(found == true){
            break;
        }

    }


    cout << start_num << " " << end_num << endl;

    return 0;
}