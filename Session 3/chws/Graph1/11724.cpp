//11724 연결요소의 개수
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > V;
bool isVisited[1001];


void dfs(int n){
    isVisited[n] = true;

    for(int x : V[n]){
        if(!isVisited[x]){
            dfs(x);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    V.resize(n+1);

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        
        V[x].push_back(y);
        V[y].push_back(x);

    }

    int count = 0;
    for(int i=1; i<n+1; i++){
        if(!isVisited[i]){
            dfs(i);
            count ++;
        }
    }

    cout << count << '\n';




}