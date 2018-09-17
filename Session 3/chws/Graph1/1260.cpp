//1260 DFS와 BFS
//gaonK의 코드 이해+재구현 해보았음 밑으로 쭉 대부분(안보고)
//그래서 거의 똑같음..ㅋㅋ변수 이름마저도;;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool check[1001];
vector< vector<int> > V;

void dfs(int n){
    check[n] = true;
    cout << n << ' ';
    for(int x: V[n]){
        if(!check[x]){
            dfs(x);
        }
    }
}

void bfs(int n){
    queue<int> q;
    check[n] = true;
    q.push(n);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << ' ';
        
        for(int y:V[x]){
            if(!check[y]){
                q.push(y);
                check[y] = true;
            }
        }
    }
    

}



int main(){
    int n, m, v;
    cin >> n >> m >> v;

    V.resize(n+1);

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);
        V[y].push_back(x);
    }

    for(int i=0; i<n+1; i++){
        sort(V[i].begin(), V[i].end());
    }

    dfs(v);
    cout << '\n';

    for(int i=0; i<n+1; i++){
        check[i] = false;
    }

    bfs(v);
    cout << '\n';

}