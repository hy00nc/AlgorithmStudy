#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        
        int res = 0;
        for (char x : s) {
            if (x == '(') {
                res++;
            } else if (x == ')') {
                res--;
                if (res < 0) break;
            }
        }
        if (res == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}