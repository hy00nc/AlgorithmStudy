#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person {
    int korean;
    int english;
    int math;
    string name;
};

person p[100001];

bool cmp(person &a, person &b) {
    if (a.korean == b.korean) {
        if (a.english == b.english) {
            if (a.math == b.math) {
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.english < b.english;
    }
    return a.korean > b.korean;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> p[i].name >> p[i].korean >> p[i].english >> p[i].math;
    }

    sort(p, p + N, cmp);
    for (int i = 0; i < N; i++) {
        cout << p[i].name << '\n';
    }

    return 0;
}