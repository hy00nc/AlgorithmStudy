#include <iostream>
using namespace std;

bool check[1000001];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    check[0] = check[1] = true;
    for(int i=2;i*i<=1000000;i++){
        if(check[i]==false){
            for(int j=i+i;j<=1000000;j+=i){
                check[j]=true;
            }
        }
    }

    int m,n;
    cin>>m>>n;
    for(int i=m;i<=n;i++){
        if(check[i]==false) cout<<i<<'\n';
    }
}