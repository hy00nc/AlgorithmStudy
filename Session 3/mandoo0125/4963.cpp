#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[50][50];
int visited[50][50];

int dx[8]={0,0,-1,1,1,-1,1,-1};
int dy[8]={-1,1,0,0,-1,1,1,-1};

int cnt;
int n,m;

void dfs(int i, int j, int c){
    visited[i][j]=c;
    for(int k=0;k<8;k++){
        int nextX = i + dx[k];
        int nextY = j + dy[k];
        if(nextX>=0 && nextY>=0 && nextX<n && nextY<m){
            if(visited[nextX][nextY]==0 && a[nextX][nextY]==1){
                dfs(nextX,nextY,c);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while(true){
        cin>>m>>n;
        if(m==0 && m==0) break;
        //행렬 청소
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=0;
            }
        }
        //행렬 초기화
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        //
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1 && visited[i][j]==0){
                    dfs(i,j,++cnt); 
                }
            }
        }
        cout<<cnt<<'\n';
    }
}