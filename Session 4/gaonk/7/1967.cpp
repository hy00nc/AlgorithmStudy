#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V;
    cin >> V;

    vector<vector<pair<int, int> > > v(V + 1);
    vector<bool> isVisited(V + 1);
    vector<int> dist(V + 1);

    for (int i = 0; i < V - 1; i++) {
        int N;
        cin >> N;
        int x, y;
        cin >> x >> y;
        v[N].push_back(pair<int, int>(x, y));
        v[x].push_back(pair<int, int>(N, y));
    }

    queue<int> q;
    q.push(1);
    isVisited[1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (pair<int, int> p : v[x]) {
            if (!isVisited[p.first]) {
                isVisited[p.first] = true;
                q.push(p.first);
                dist[p.first] = dist[x] + p.second;
            }
        }
    }

    int secondStart;
    int max = 0;
    for (int i = 2; i <= V; i++) {
        if (max < dist[i]) {
            max = dist[i];
            secondStart = i;
        }
    }

    isVisited.clear();
    isVisited.resize(V + 1);
    dist.clear();
    dist.resize(V + 1);

    q.push(secondStart);
    isVisited[secondStart] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (pair<int, int> p : v[x]) {
            if (!isVisited[p.first]) {
                isVisited[p.first] = true;
                q.push(p.first);
                dist[p.first] = dist[x] + p.second;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= V; i++) {
        if (ans < dist[i]) {
            ans = dist[i];
        }
    }

    cout << ans << '\n';

    return 0;
}