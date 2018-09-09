#include <iostream>
using namespace std;

int main() {
    string num[4];
    for (int i = 0; i < 4; i++) {
        cin >> num[i];
    }

    string num1 = num[0] + num[1];
    string num2 = num[2] + num[3];
    cout << stol(num1) + stol(num2) << '\n';
    
    return 0;
}