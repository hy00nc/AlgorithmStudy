#include <iostream>
#include <algorithm>
using namespace std;

int card[500001];

bool checkCard(int N, int num) {
    int left = 0;
    int right = N - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (card[mid] == num) {
            return true;
        } else if (card[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> card[i];
    }

    sort(card, card + N);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        if (checkCard(N, x)) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    cout << '\n';

    return 0;
}