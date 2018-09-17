#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


vector <int> graph[1001];
bool check[1001];

void dfs(int v){
    check[v]=true;
    cout<<v<<" ";
    for(int i=0;i<graph[v].size();i++){
        int next = graph[v][i];
        if(check[next]==false) dfs(next);
    }
}

void bfs(int v){
    memset(check,false,sizeof(check));
    queue<int> q;
    check[v]=true;
    q.push(v);
    while(!q.empty()){
        int item = q.front();
        cout<<item<<" ";
        q.pop();
        for(int i=0;i<graph[item].size();i++){
            int next = graph[item][i];
            if(check[next]==false){
                check[next]=true;
                q.push(next);
            }
        }
    }
}



int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m,v;
    cin>>n>>m>>v;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    
    dfs(v);
    cout<<'\n';
    bfs(v);
    cout<<'\n';
    return 0;
}