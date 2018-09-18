#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator < (const Point &v) const {
        if (x == v.x) {
            return y < v.y;
        }
        return x < v.x;
    }
};

vector<Point> a;

bool cmp(const Point &a, const Point &b) {
    return a.y < b.y;
}

int calculateDistance(Point p, Point q) {
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

int findClosestDistance(int st, int ed) {
    if (ed + 1 - st <= 3) {
        int ans = -1;

        for (int i = st; i <= ed - 1; i++) {
            for (int j = i + 1; j <= ed; j++) {
                if (ans == -1 || calculateDistance(a[i], a[j]) < ans) {
                    ans = calculateDistance(a[i], a[j]);
                }
            }
        }

        return ans;
    }

    int md = (st + ed) / 2;
    int left = findClosestDistance(st, md);
    int right = findClosestDistance(md + 1, ed);
    int ans = min(left, right);

    vector<Point> b;
    for (int i = st; i <= ed; i++) {
        int d = a[i].x - a[md].x;
        if (d * d < ans) {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end(), cmp);
    int bSize = b.size();

    for (int i = 0; i < bSize - 1; i++) {
        for (int j = i + 1; j < bSize; j++) {
            int d = b[i].y - b[j].y;
            if (d * d < ans) {
                if (calculateDistance(b[i], b[j]) < ans) {
                    ans = calculateDistance(b[i], b[j]);
                }
            } else {
                break;
            }
        }
    }

    return ans;
}

int main() {
    int N;
    scanf("%d", &N);
    a.resize(N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }

    sort(a.begin(), a.end());
    int ans = findClosestDistance(0, N - 1);
    printf("%d\n", ans);

    return 0;
}