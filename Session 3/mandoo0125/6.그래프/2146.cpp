#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int a[100][100];
int inum[100][100];
bool check[100][100];
int dist[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int n;

void dfs(int i, int j, int c){
    check[i][j]=true;
    inum[i][j]=c;
    for(int k=0;k<4;k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx>=0 && ny>=00 && nx<n && ny<n){
            if(check[nx][ny]==false && a[nx][ny]==1){
                dfs(nx,ny,c);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==false && a[i][j]==1){
                dfs(i,j,++cnt);
            }
        }
    }
    
    int ans =-1;
    for(int l=1;l<=cnt;l++){
        queue <pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=-1;
                if(inum[i][j]==l){
                    q.push(make_pair(i,j));
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(dist[nx][ny]==-1){
                        dist[nx][ny]=dist[x][y]+1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1 && inum[i][j]!=l){
                    if(ans==-1 || dist[i][j]-1<ans)
                        ans = dist[i][j]-1;
                }
            }
        }
    }
    cout<<ans<<'\n';
}
