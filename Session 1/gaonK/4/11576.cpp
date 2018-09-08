#include <iostream>
#include <stack>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    long long ten = 0;
    int N;
    cin >> N;
    stack<int> s;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    long long k = 1;
    while (!s.empty()) {
        int x = s.top();
        s.pop();

        ten += x * k;
        k *= A;
    }
    
    while (ten > 0) {
        s.push(ten % B);
        ten /= B;
    }

    while (!s.empty()) {
        int x = s.top();
        s.pop();
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}