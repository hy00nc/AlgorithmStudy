#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph;
bool isChecked[1001];

void dfs(int n) {
    isChecked[n] = true;

    for (int x : graph[n]) {
        if (!isChecked[x]) {
            dfs(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!isChecked[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}