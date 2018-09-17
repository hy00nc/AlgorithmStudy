#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    while(n>=2 && m>=1 && m+n>=k+3){
        ans++;
        n-=2;
        m--;
    }
    cout<<ans<<'\n';
}