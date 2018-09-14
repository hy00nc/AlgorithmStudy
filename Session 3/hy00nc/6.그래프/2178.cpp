#include <iostream>
#include <queue>
using namespace std;

int n,m;
int a[100][100];
bool check[100][100];
int d[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    queue <pair<int,int>> q;
    q.push(make_pair(0,0));
    check[0][0]=true;
    d[0][0]=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny>=0 && nx>=00 && ny<m && nx<n){
                if(a[nx][ny]==1 && check[nx][ny]==false){
                    q.push(make_pair(nx,ny));
                    d[nx][ny]=d[x][y]+1;
                    check[nx][ny]=true;
                }
            }
        }
    }
    cout<<d[n-1][m-1]<<'\n';
}