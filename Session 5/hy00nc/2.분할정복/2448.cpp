#include <iostream>
#include <cstring>
using namespace std;

char a[10000][10000];

void draw(int x, int y, int n){
    if(n==3){
        a[x][y]='*';
        a[x+1][y-1]='*'; a[x+1][y+1]='*';
        for(int j=y-2;j<=y+2;j++){
            a[x+2][j]='*';
        }
        return;
    }
    draw(x,y,n/2);
    draw(x+n/2,y-n/2,n/2);
    draw(x+n/2,y+n/2,n/2);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    memset(a,' ',sizeof(a));
    draw(0,n-1,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
}