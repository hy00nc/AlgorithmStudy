#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > graph;
vector<int> isVisited;

void dfs(int n, int side) {
    isVisited[n] = side;

    for (int x : graph[n]) {
        if (!isVisited[x]) {
            dfs(x, -1 * side);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    while (K--) {
        int V, E;
        cin >> V >> E;

        graph.clear();
        graph.resize(V + 1);
        isVisited.clear();
        isVisited.resize(V + 1);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (!isVisited[i]) {
                dfs(i, 1);
            }
        }

        bool flag = true;
        for (int i = 1; i <= V; i++) {
            for (int x : graph[i]) {
                if (isVisited[x] == isVisited[i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break; 
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}