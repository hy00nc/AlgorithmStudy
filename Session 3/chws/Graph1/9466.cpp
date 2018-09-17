//9466
#include <iostream>
#include <vector>
using namespace std;

int result;

vector<int> graph;
vector<int> isVisited;
vector<int> start;

void dfs(int n, int cnt, int s){
    isVisited[n] = cnt;
    start[n] = s;

    int x = graph[n];
    if(!isVisited[x]){
        dfs(x, cnt+1, s);
    } else if(start[n] == start[x]){
        result -= cnt + 1 - isVisited[x];
    }

}
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        graph.clear();
        graph.resize(n+1);
        isVisited.clear();
        isVisited.resize(n+1);
        start.clear();
        start.resize(n+1);
        result = n;

        for(int i=1; i<n+1; i++){
            int x; 
            cin >> x;
            graph[i] = x;
        }

        for(int i=1; i<n+1; i++){
            if(!isVisited[i]){
                dfs(i, 1, i);
            }
        }

        cout << result << '\n';




    }
    return 0;

}