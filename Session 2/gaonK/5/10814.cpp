#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person {
    int order;
    int age;
    string name;
};

person p[100001];

bool cmp(person &a, person &b) {
    if (a.age == b.age) {
        return a.order < b.order;
    } 
    return a.age < b.age;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> p[i].age >> p[i].name;
        p[i].order = i;
    }

    sort(p, p + N, cmp);
    for (int i = 0; i < N; i++) {
        cout << p[i].age << ' ' << p[i].name << '\n';
    }

    return 0;
}