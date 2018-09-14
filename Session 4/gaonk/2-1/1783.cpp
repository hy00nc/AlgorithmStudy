#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (N == 1) {
        cout << 1;
    } else if (N == 2) {
        cout << min((M  + 1) / 2, 4);
    } else {
        if (M >= 7) {
            cout << M - 2;
        } else {
            cout << min(4, M);
        }
    }
    cout << '\n';
    
    return 0;
}