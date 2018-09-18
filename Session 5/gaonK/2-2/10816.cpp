#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> card;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (card.find(x) == card.end()) {
            card.insert(make_pair(x, 1));
        } else {
            card[x]++;
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        if (card.find(x) == card.end()) {
            cout << 0 << ' ';
        } else {
            cout << card[x] << ' ';
        }
    }
    cout << '\n';

    return 0;
}