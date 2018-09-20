#include <cstdio>
#include <vector>
using namespace std;

int N, M;
vector<bool> isVisited;
vector<vector<pair<int, int>>> v;

void dfs(int mid, int n) {
    isVisited[n] = true;

    for (pair<int, int> p : v[n]) {
        if (p.second >= mid && !isVisited[p.first]) {
            dfs(mid, p.first);
        }
    }   
}

int main() {
    scanf("%d %d", &N, &M);
    v.resize(N + 1);
    isVisited.resize(N + 1);

    int maxLength = 0;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));

        if (c > maxLength) {
            maxLength = c;
        }
    }
    int st, ed;
    scanf("%d %d", &st, &ed);

    int left = 1;
    int right = maxLength;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        
        for (int i = 1; i <= N; i++) {
            isVisited[i] = false;
        }
        dfs(mid, st);
        
        if (isVisited[ed]) {
            if (ans < mid) {
                ans = mid;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}