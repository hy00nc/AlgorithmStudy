#include <iostream>
#include <vector>
using namespace std;

vector<int> a[20001];
int mark[20001];

void dfs(int v, int m){
    mark[v]=m;
    for(int i=0;i<a[v].size();i++){
        int next = a[v][i];
        if(mark[next]==0) dfs(next,3-m);
    }
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        //그래프 원상태 복귀
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            a[i].clear();
            mark[i]=0;
        }
        //그래프 저장
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        //
        for(int i=1;i<=n;i++){
            if(mark[i]==0) dfs(i,1);
        }
        bool check=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                int node = a[i][j];
                if(mark[i]==mark[node]) check = false;
            }
        }
        if(check==true) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}