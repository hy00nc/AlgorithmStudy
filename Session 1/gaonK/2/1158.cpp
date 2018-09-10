#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    
    cout << "<";
    while (!q.empty()) {
        for (int i = 0; i < M; i++) {
            int x = q.front();
            q.pop();

            if (i == M - 1) {
                cout << x;
                if (!q.empty()) {
                    cout << ", ";
                }
            } else {
                q.push(x);
            }
        }
    }
    cout << ">\n";
    
    return 0;
}