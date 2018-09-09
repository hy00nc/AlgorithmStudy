#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string n;
    int b;
    int m=1;
    cin>>n>>b;
    int sum=0;
    for(int i=n.size()-1;i>=0;i--){
        if(n[i]-'A'>=0) sum+=(n[i]-'A'+10)*m;
        else sum+=(n[i]-'0')*m;
        m=m*b;
    }
    cout<<sum<<'\n';
}