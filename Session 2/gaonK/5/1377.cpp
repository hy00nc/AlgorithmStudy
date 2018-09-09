#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (ans < v[i].second - i) {
            ans = v[i].second - i;
        }
    }
    cout << ans + 1 << '\n';

    return 0;
}