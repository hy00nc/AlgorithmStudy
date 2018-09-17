#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> a[100001];
int parent[100001];
bool check[100001];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue <int> q;
    parent[1]=0; check[1]=true;
    q.push(1);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : a[x]){
            if(check[y]==false){
                q.push(y);
                check[y]=true;
                parent[y]=x;
            }
        }
    }

    for(int i=2;i<=n;i++){
        cout<<parent[i]<<'\n';
    }
}