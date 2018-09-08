#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    long long N;
    int B;
    cin >> N >> B;

    while (N) {
        s.push(N % B);
        N /= B;
    }

    while (!s.empty()) {
        int x = s.top();
        s.pop();

        if (10 <= x && x <= 36) {
            cout << (char)(x - 10 + 'A');
        } else {
            cout << x;
        }
    }
    cout << '\n';
    
    return 0;
}