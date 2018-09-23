#include <iostream>
using namespace std;

int a[100][100];

bool same(int x, int y, int n){
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(a[x][y]!=a[i][j]){
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int n){
    if(same(x,y,n)){
        cout<<a[x][y];
    }
    else{
        cout<<'(';
        solve(x,y,n/2);
        solve(x,y+n/2,n/2);
        solve(x+n/2,y,n/2);
        solve(x+n/2,y+n/2,n/2);
        cout<<')';
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    solve(0,0,n);
    cout<<'\n';
}
