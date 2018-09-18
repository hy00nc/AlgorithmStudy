#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }

    int aSize = a.size();
    int bSize = b.size();
    int aIdx = 0, bIdx = 0;

    vector<int> ans;
    while (aIdx < aSize && bIdx < bSize) {
        if (a[aIdx] <= b[bIdx]) {
            ans.push_back(a[aIdx]);
            aIdx++;
        } else {
            ans.push_back(b[bIdx]);
            bIdx++;
        }
    }
    while (aIdx < aSize) {
        ans.push_back(a[aIdx]);
        aIdx++;
    }
    while (bIdx < bSize) {
        ans.push_back(b[bIdx]);
        bIdx++;
    }

    for (int x : ans) {
        cout << x << '\n';
    }
    cout << '\n';

    return 0;
}