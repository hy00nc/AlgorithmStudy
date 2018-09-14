#include <iostream>
using namespace std;

long long p[101];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        p[1]=p[2]=p[3]=1;
        p[4]=p[5]=2;
        for(int i=6;i<=n;i++){
            p[i]=p[i-1]+p[i-5];
        }
        cout<<p[n]<<'\n';
    }

}