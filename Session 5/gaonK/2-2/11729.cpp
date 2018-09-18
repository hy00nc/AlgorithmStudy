#include <iostream>
using namespace std;

void hanoi(int st, int md, int ed, int N) {
    if (N == 0) {
        return;
    }

    hanoi(st, ed, md, N - 1);
    cout << st << ' ' << ed << '\n';
    hanoi(md, st, ed, N - 1);
}

int main() {
    int N;
    cin >> N;

    cout << (1 << N) - 1 << '\n';
    hanoi(1, 2, 3, N);

    return 0;
}