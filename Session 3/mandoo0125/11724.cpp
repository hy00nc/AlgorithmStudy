#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[1001];
bool check[1001];

void dfs(int v){
    check[v]=true;
    for(int i=0;i<graph[v].size();i++){
        int next = graph[v][i];
        if(check[next]==false) dfs(next);
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(check[i]==false){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}