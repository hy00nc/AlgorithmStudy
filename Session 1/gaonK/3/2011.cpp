#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000

int dp[5001];

int main() {
    string password;
    cin >> password;

    dp[0] = 1;
    int size = password.size();
    for (int i = 0; i < size; i++) {
        int x = password[i] - '0';
        if (1 <= x && x <= 9) {
            dp[i + 1] = dp[i];
        }
        if (i == 0) continue;
        
        x = (password[i - 1] - '0') * 10 + password[i] - '0';
        if (10 <= x && x <= 26) {
            dp[i + 1] += dp[i - 1];
        }
        dp[i + 1] %= MOD;
    }
    cout << dp[size] << '\n';

    return 0;
}