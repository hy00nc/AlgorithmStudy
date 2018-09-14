#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    int lastEnd = v[0].second;
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (v[i].first >= lastEnd) {
            lastEnd = v[i].second;
            ans += 1;
        }
    }
    cout << ans << '\n';

    return 0;
}