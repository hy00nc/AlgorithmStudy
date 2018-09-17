#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Edge{
    int to;
    int cost;
    Edge (int to, int cost): to(to), cost(cost){}
};

bool check[10001];
vector <Edge> a[10001];
int dist[10001];

void bfs(int start){
    memset(check,false,sizeof(check));
    memset(dist,0,sizeof(dist));
    check[start]=true;
    queue <int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0;i<a[x].size();i++){
            Edge &e = a[x][i];
            if(check[e.to]==false){
                dist[e.to] = dist[x]+e.cost;
                q.push(e.to);
                check[e.to] = true;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x, y, z;
        cin>>x>>y>>z;
        a[x].push_back(Edge(y,z));
        a[y].push_back(Edge(x,z));
    }
    bfs(1);
    int next=1;
    for(int i=2;i<=n;i++){
        if(dist[i]>dist[next]) next = i;
    }
    bfs(next);
    int ans = dist[1];
    for(int i=2;i<=n;i++){
        if(dist[i]>ans) ans = dist[i];
    }
    cout<<ans<<'\n';
}