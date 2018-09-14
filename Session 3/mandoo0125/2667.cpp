#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[26][26];
int visited[26][26];
vector <int> vcount;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int cnt;
int n;
int vc;

void dfs(int i, int j, int c){
    visited[i][j]=c;
    vc++;
    for(int k=0;k<4;k++){
        int nextX = i + dx[k];
        int nextY = j + dy[k];
        if(nextX>=0 && nextY>=0 && nextX<n && nextY<n){
            if(visited[nextX][nextY]==0 && a[nextX][nextY]==1){
                dfs(nextX,nextY,c);
            }
        }
    }
}

int main(){
 //   cin.tie(NULL);
 //   ios::sync_with_stdio(false);

    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&a[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1 && visited[i][j]==0){
                vc=0;
                dfs(i,j,++cnt); 
                vcount.push_back(vc);
            }
        }
    }
    sort(vcount.begin(), vcount.end());
    cout<<cnt<<'\n';
    for(int i=0;i<cnt;i++){
        cout<<vcount[i]<<'\n';
    }
}