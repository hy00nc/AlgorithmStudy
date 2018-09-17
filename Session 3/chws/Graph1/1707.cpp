//1707
#include <iostream>
#include <vector>
using namespace std;

vector<int> isVisited;
vector< vector<int> > V;

void dfs(int n, int color){
    isVisited[n] = color;

    for(int x : V[n]){
        if(!isVisited[x]){
            dfs(x, color*(-1));
        }
    }
}

int main(){
    int k, v, e;

    cin >> k;
    while(k--){
        cin >> v >> e;
        V.clear();
        V.resize(v+1);
        isVisited.clear();
        isVisited.resize(v+1);

        for(int i=0; i<e; i++){
            int x, y;
            cin >> x >> y;
            V[x].push_back(y);
            V[y].push_back(x);
        }

        for(int i=1; i<v+1; i++){
            if(!isVisited[i]){
                dfs(i, 1);
            }
        }

        bool flag = true;

        for(int i=1; i<v+1; i++){
            for(int x: V[i]){
                if(isVisited[i] == isVisited[x]){
                    flag = false;
                    break;
                }
            }
            if(!flag)  break;
        }

        if(!flag) cout << "NO\n";
        else cout << "YES\n";


    }
    

}