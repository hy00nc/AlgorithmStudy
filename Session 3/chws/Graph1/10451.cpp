//10451
#include <iostream>
#include <vector>
using namespace std;

vector<int> V;
vector<bool> isVisited;


void dfs(int n, int* count){
    isVisited[n] = true;
    int x = V[n];
    if(!isVisited[x]){
        dfs(x, count);
    }else{
        (*count) ++;
    }

}

int main(){
    int count;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        V.clear();
        V.resize(n+1);
        isVisited.clear();
        isVisited.resize(n+1);
        count = 0;
        for(int i=1; i<=n; i++){
            cin >> V[i];
        }
        
        for(int i=1; i<=n; i++){
            if(!isVisited[i]){
                dfs(i, &count);
            }
        }
        cout << count << '\n';

    }

}
