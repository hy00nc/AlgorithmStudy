#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> v(N + 1);
    vector<int> parent(N + 1);
    vector<bool> isVisited(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    isVisited[1] = true;

    while (!q.empty()) {
        int root = q.front();
        q.pop();

        for (int x : v[root]) {
            if (!isVisited[x]) {
                isVisited[x] = true;
                parent[x] = root;
                q.push(x);
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}