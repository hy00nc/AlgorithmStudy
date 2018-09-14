#include <iostream>
using namespace std;

int d[100001];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
  //  int d[n+1];
    for(int i=1;i<=n;i++){
        d[i]=i;
        for(int j=1;j*j<=i;j++){
            if(d[i]>d[i-j*j]+1)
            d[i]=d[i-j*j]+1;
        }
    }
    cout<<d[n]<<"\n";
}
