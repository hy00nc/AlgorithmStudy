#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m,n;
int a[1000][1000];
int dx[4] ={0,0,1,-1};
int dy[4] ={1,-1,0,0};
int days[1000][1000];


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>m>>n;
    queue <pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int input;
            cin>>input;
            a[i][j]=input;
            if(input==1) q.push(make_pair(i,j));
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(a[nx][ny]==0 && a[nx][ny]!=-1){
                    q.push(make_pair(nx,ny));
                    a[nx][ny]=1;
                    days[nx][ny]=days[x][y]+1;
                }
            }
        }
    }

    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0) flag = true;
        }
    }

    if(flag){
        cout<<-1<<'\n';
        return 0;
    }
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(max<days[i][j]) max = days[i][j];
    }
    cout<<max<<'\n';
}