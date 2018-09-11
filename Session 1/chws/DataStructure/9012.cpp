//9012 괄호
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string isValid(string s){
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(')
            cnt++;
        else if(s[i]==')')
            cnt--;

        if(cnt<0)
            return "NO";
    }
    if(cnt==0) return "YES";
    else return "NO";
}


int main(){
    int t;
    cin >> t;

    string s;
    while(t--){
        cin >> s;
        cout << isValid(s) << '\n';
    }


    return 0;
}