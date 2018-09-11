#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > v;
bool check[1001];

void dfs(int n) {
    check[n] = true;
    cout << n << ' ';
    for (int x : v[n]) {
        if (!check[x]) {
            dfs(x);
        }
    }
}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    check[n] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';

        for (int nx : v[x]) {
            if (!check[nx]) {
                q.push(nx);
                check[nx] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;
    v.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 0; i < N; i++) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(V);
    cout << '\n';

    for (int i = 1; i <= N; i++) {
        check[i] = false;
    }

    bfs(V);
    cout << '\n';

    return 0;
}