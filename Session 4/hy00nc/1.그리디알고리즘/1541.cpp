#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    vector <int> num;
    vector <int> sign;
    int n=0;
    sign.push_back(1);
    for(int i=0;i<s.size();i++){
        if(s[i]=='-'|| s[i]=='+'){
            if(s[i]=='-') sign.push_back(-1);
            else if(s[i]=='+') sign.push_back(1);
            num.push_back(n);
            n=0;
        }
        else{
            n=n*10+(s[i]-'0');
        }
    } num.push_back(n);
    int ans=0;
    bool minus = false;
    for(int i=0;i<num.size();i++){
        if(sign[i]==-1) minus = true;
        if(minus) ans-=num[i];
        else ans+=num[i];
    }
    cout<<ans<<'\n';
    
}