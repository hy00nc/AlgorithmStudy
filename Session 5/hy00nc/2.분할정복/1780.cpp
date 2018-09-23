#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[2200][2200];
int cnt[4];

bool same(int x, int y, int num){
    for(int i=x;i<x+num;i++){
        for(int j=y;j<y+num;j++){
            if(a[x][y]!=a[i][j]){
                return false;
            }
        }
    }
    return true;
}
void solve(int x, int y, int num){
    if(same(x,y,num)){
        cnt[a[x][y]+1]++;
        return;
    }
    else{
        int temp = num/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                solve(x+temp*i,y+temp*j,temp);
            }
        }
    }
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    //행렬 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    //시작
    solve(0,0,n);

    for(int i=0;i<3;i++){
        cout<<cnt[i]<<'\n';
    }
}