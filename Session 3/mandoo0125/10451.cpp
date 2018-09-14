#include <iostream>
#include <vector>
using namespace std;

vector <int> a[1001];
bool check[1001];

void dfs(int v){
    check[v]=true;
    int next = a[v][0];
    if(check[next]==false) dfs(next);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        //그래프 비우기
        for(int i=1;i<=n;i++){
            a[i].clear();
            check[i]=false;
        }
        for(int i=1;i<=n;i++){
            int node;
            cin>>node;
            a[i].push_back(node);
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
}