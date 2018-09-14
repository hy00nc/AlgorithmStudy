#include <iostream>
#include <string>
using namespace std;

int mod = 1000000;
int d[5001];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    cin>>str;
    int n=str.size();
    str=" "+str;
    d[0]=1;
    for(int i=1;i<=n;i++){
      int x = str[i]-'0';
      if(x>=1 && x<=9) d[i]=(d[i]+d[i-1])%mod;
      if(str[i-1]=='0') continue;
      x = (str[i-1]-'0')*10 + (str[i]-'0');
      if(x>=10 && x<=26) d[i]=(d[i]+d[i-2])%mod;
    }
    cout<<d[n]<<'\n';
}