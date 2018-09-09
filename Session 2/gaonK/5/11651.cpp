#include <iostream>
#include <algorithm>
using namespace std;

struct point {
    int x;
    int y;
};

point p[100001];

bool cmp(point &a, point &b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p, p + N, cmp);
    for (int i = 0; i < N; i++) {
        cout << p[i].x << ' ' << p[i].y << '\n';
    }

    return 0;
}