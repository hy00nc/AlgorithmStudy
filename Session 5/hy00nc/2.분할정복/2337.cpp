#include <iostream>
#include <cstring>
using namespace std;

char a[7000][7000];

void draw(int x, int y, int n){
    if(n==1){
        a[x][y]='*';
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1 && j==1){
                continue;
            }
            draw(x+i*n/3,y+j*n/3,n/3);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    memset(a,' ',sizeof(a));
    draw(0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
}