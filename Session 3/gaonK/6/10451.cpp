#include <iostream>
#include <vector>
using namespace std;

vector<int> graph;
vector<bool> isVisited;
int cnt = 0;

void dfs(int n) {
    isVisited[n] = true;

    int x = graph[n];
    if (!isVisited[x]) {
        dfs(x);
    } else {
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        graph.clear();
        graph.resize(N + 1);
        isVisited.clear();
        isVisited.resize(N + 1);
        cnt = 0;

        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;

            graph[i] = x;
        }
        
        for (int i = 1; i <= N; i++) {
            if (!isVisited[i]) {
                dfs(i);
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}