#include <iostream>
#include <vector>
using namespace std;

vector<int> graph;
vector<int> isVisited;
vector<int> startNumber;
int ans = 0;

void dfs(int n, int cnt, int stNum) {
    isVisited[n] = cnt;
    startNumber[n] = stNum;

    int x = graph[n];
    if (!isVisited[x]) {
        dfs(x, cnt + 1, stNum);
    } else if (startNumber[x] == startNumber[n]) {
        ans -= cnt + 1 - isVisited[x];
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
        startNumber.clear();
        startNumber.resize(N + 1);
        ans = N;

        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            graph[i] = x;
        }
        
        for (int i = 1; i <= N; i++) {
            if (!isVisited[i]) {
                dfs(i, 1, i);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}