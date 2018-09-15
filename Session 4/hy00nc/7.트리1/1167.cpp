#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct Edge{
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost){}
};
int dist[1000001];
vector <Edge> a[1000001];
bool check[1000001];

void bfs(int x){
    memset(dist,0,sizeof(dist));
    memset(check,false,sizeof(check));
    queue <int> q;
    q.push(x);
    check[x]=true;
    while(!q.empty()){
        int next = q.front(); q.pop();
        for(int i=0;i<a[next].size();i++){
            Edge &e = a[next][i];
            if(check[e.to]==false){
                dist[e.to] = dist[next] + e.cost;
                q.push(e.to);
                check[e.to] = true;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int v;
    cin>>v;
    for(int i=1;i<=v;i++){
        int x, to, cost;
        cin>>x;
        while(true){
            cin>>to;
            if(to==-1) break;
            cin>>cost;
            a[x].push_back(Edge(to,cost));
        }
    }

    bfs(1);
    int next = 1;
    for(int i=2;i<=v;i++){
        if(dist[i]>dist[next]) next = i;
    }
    bfs(next);
    int ans = dist[1];
    for(int i=2;i<=v;i++){
        if(dist[i]>ans) ans = dist[i];
    }
    cout<<ans<<'\n';
}