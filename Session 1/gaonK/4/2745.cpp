#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    string B;
    int N;
    
    cin >> B >> N;

    for (char x : B) {
        s.push(x);
    }

    long long ans = 0;
    int k = 1;
    while (!s.empty()) {
        char x = s.top();
        s.pop();

        int num;
        if ('A' <= x && x <= 'Z') {
            num = x - 'A' + 10;
        } else {
            num = x - '0';
        }

        ans += num * k;
        k *= N;
    }
    cout << ans << '\n';

    return 0;
}