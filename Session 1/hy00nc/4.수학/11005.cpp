#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,b;
    cin>>n>>b;
    stack <char> s;
    while(n!=0){
        int mod = n%b;
        n=n/b;
        if(mod>=10) s.push(mod-10+'A');
        else s.push('0'+mod);
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<'\n';
}