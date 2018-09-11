//10809 알파벳 찾기
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i='a'; i<='z'; i++){

        auto a = find(s.begin(), s.end(), i);
        if(a == s.end()){
            cout << -1 << ' ';
        }
        else{
            cout << (a-s.begin()) << ' ';
        }

    }
    cout << '\n';
    return 0;
}